#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ; 

vector<int> num ; 
vector<int> res ; 
int findmore[10001][101] ;            // findmore[i][j] 表示前i个硬币最多能组成多少元（小于等j)  
bool use[10001][101] = {false} ; 
int n, sum ; 

bool cmp(int a, int b ) { return a > b ; }                           // 比较函数，降序排列

void find_coin() {
    int i, j ; 
    for ( i = 1 ; i <= n ; i++ ) {
        for ( j = 1 ; j <= sum ; j++ ) {
            if ( j < num[i] ) 
                continue ; 
            if ( findmore[i-1][j] <= findmore[i-1][j-num[i]] + num[i] ) {
                findmore[i][j] = findmore[i-1][j-num[i]] + num[i] ; 
                use[i][j] = true ; 
            }
            else 
                findmore[i][j] = findmore[i-1][j] ; 
        } 
    }
}
 
void get_coin() {
    if ( sum != findmore[n][sum] ) {                                 // 如果 sum == findmore[n][sum] 就表示能找出至少一组解  
        cout << "No Solution" << endl ; 
        return ; 
    }  
    while ( sum ) {
        while ( !use[n][sum] )                                      // num是降序排列的，最先找到的一定是最小的         
            n-- ; 
        res.push_back(num[n]) ; 
        sum -= num[n] ; 
        n-- ; 
    }
    for ( int i = 0 ; i < res.size() ; i++ ) {                      
        if ( i != 0 ) 
            cout << " " ; 
        cout << res[i] ; 
    }
    cout << endl ; 
}

int main() {
    int i, j ; 
    cin >> n >> sum ; 
    num.resize(n+1) ; 
    for ( i = 1 ; i <= n ; i++ ) 
        cin >> num[i] ; 
    sort(num.begin()+1,num.end(),cmp) ;                                // 从大到小排列
    find_coin() ;  
    get_coin() ; 
    return 0 ; 
}