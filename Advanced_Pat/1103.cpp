#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std ;

int sum = 0, p, n, k ; 
vector<int> res ; 
vector<int> pows (22) ; 
int most = 1 ; 

void get_pow() {
    pows[1] = 1 ; 
    int i, j ; 
    for ( i = 2 ; i <= 20 ; i++ ) {
        int tmp = i ; 
        for ( j = 1 ; j < p ; j++ ) { 
            tmp *= i ; 
            if ( tmp > n ) 
                return ; 
        }
        pows[i] = tmp ; 
        most = i ; 
    }
}

void dfs(int target, int count, vector<int> &temp) {
    if ( count == k ) {
        if ( target == 0 ) { 
            int now = 0 ; 
            for  ( int i = 0 ; i < temp.size() ; i++ ) 
                now += temp[i] ; 
            if ( sum <= now ) {
                res = temp ; 
                sum = now ; 
            }
        }
        return ; 
    }
    int low = ( count > 0 ) ? temp[count-1] : 1 ; 
    int high = min((int)sqrt((double)target),most) ; 
    for ( int i = low ; i <= high ; i++ ) {
        int now_pow = pows[i] ; 
        if ( target >= now_pow ) { 
            temp[count] = i ; 
            dfs(target-now_pow,count+1,temp) ;
        }
        else 
            return ; 
    } 
}

int main() {
    int i ; 
    cin >> n >> k >> p ; 
    get_pow() ; 
    vector<int> temp (k) ; 
    dfs(n,0,temp) ;
    if ( res.empty() ) {
        cout << "Impossible" << endl ; 
        return 0 ; 
    }
    for ( i = k-1 ; i >= 0 ; i-- ) {
        if ( i == k-1 ) 
            printf("%d = %d^%d",n,res[i],p) ; 
        else 
            printf(" + %d^%d",res[i],p) ; 
    }
    cout << endl ; 
    return 0 ; 
}
