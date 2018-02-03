#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

// 两个测试点超时 (25/30) 
vector<int> num ; 
vector<int> res ; 
int maxx = 0, sum, n ; 

void knapsack(int pos, int now, vector<int> &tmp) {
    if ( now <= 0 ) {
        if ( now == 0 && maxx < tmp.size() ) {
            maxx = tmp.size() ; 
            res.assign(tmp.begin(),tmp.end()) ; 
        }
        return ; 
    }
    for ( int i = pos ; now >= num[i] && n + tmp.size() > maxx + i ; i++ ) {
        tmp.push_back(num[i]) ; 
        knapsack(i+1,now-num[i],tmp) ; 
        tmp.pop_back() ; 
    }
}

int main() {
    int sum, i, j, t ;
    cin >> n >> sum ; 
    for ( i = 0 ; i < n ; i++ ) { 
        cin >> t ; 
        if ( t <= sum )
            num.push_back(t) ; 
    }
    sort(num.begin(),num.end()) ; 
    vector<int> tmp ; 
    knapsack(0,sum,tmp) ;
    if ( res.empty() ) {
        cout << "No Solution" << endl ; 
        return 0 ; 
    }
    for ( j = 0 ; j < res.size() ; j++ ) {
        if ( j != 0 ) 
            cout << " " ; 
        cout << res[j] ; 
    }
    cout << endl ; 
    return 0 ; 
}