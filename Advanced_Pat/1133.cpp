#include<cstdio>
#include<iostream>
#include<vector>
using namespace std ; 

struct node {
    int val, next ; 
} list[100000] ;

int main() {
    int i, j, s, n, k, ad, newstart ; 
    cin >> s >> n >> k ; 
    vector<int> res[3] ; 
    for ( i = 0 ; i < n ; i++ ) {
        cin >> ad ; 
        cin >> list[ad].val >> list[ad].next  ; 
    }

    for ( i = s ; i != -1 ; i = list[i].next ) {
        if ( list[i].val < 0 ) 
            res[0].push_back(i) ; 
        else if ( list[i].val >= 0 && list[i].val <= k ) 
            res[1].push_back(i) ; 
        else 
            res[2].push_back(i) ; 
    }
    
    for ( i = 0 ; res[i].empty() ; i++ ) ; 
    newstart = res[i][0] ; 

    for ( i = 0 ; i < 3 ; i++ ) {
        for ( j = 0 ; j < res[i].size() ; j++ ) {
            if ( res[i][j] != newstart ) 
                printf("%05d\n",res[i][j]) ; 
            printf("%05d %d ",res[i][j],list[res[i][j]].val) ; 
        }
    }
    cout << "-1" << endl ; 
    return 0 ; 
}