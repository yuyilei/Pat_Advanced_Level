#include<iostream>
#include<cstdio>
#include<vector> 
#include<queue>
#include<cmath>
using namespace std ; 

int main() {
    int n, i, j, t ; 
    double p, r ; 
    cin >> n >> p >> r ; 
    vector<vector<int> > node (n) ; 
    for ( i = 0 ; i < n ; i++ ) {
        cin >> t ; 
        node[i].resize(t) ; 
        for ( j = 0 ; j < t ; j++ ) 
            cin >> node[i][j] ; 
    }
    queue<int> q ; 
    int num = 0, k = 0 ; 
    q.push(0) ; 
    while ( !q.empty() && !num) {
        int len = q.size() ; 
        for ( i = 0 ; i < len ; i++ ) {
            int now = q.front() ; 
            q.pop() ;
            if ( node[now].size() == 0 ) 
                num++ ; 
            for ( j = 0 ; j < node[now].size() ; j++ ) 
                q.push(node[now][j]) ; 
        }
        if ( num > 0 ) 
            break ; 
        k++ ; 
    }
    double ans = p ; 
    for ( i = 0 ; i < k ; i++ ) 
        ans *= (double)(1 + r/100.0) ; 
    printf("%.4lf %d\n",ans,num) ; 
    return 0 ; 
}