#include<vector>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
using namespace std ;

int main() {
    double p, r , ans = 0 ;
    int n, i, j ,t ; 
    cin >> n >> p >> r ; 
    r /= 100 ; 
    vector<vector<int> > node (n) ;
    for ( i = 0 ; i < n ; i++ ) {
        cin >> t ; 
        if ( t == 0 ) {
            node[i].resize(2) ; 
            node[i][0] = 0 ; 
            cin >> node[i][1] ; 
        }
        else 
            node[i].resize(t) ; 
        for ( j = 0 ; j < t ; j++ ) 
            cin >> node[i][j] ; 
    }
    int k = 0 ; 
    queue<int> q ;
    q.push(0) ; 
    while ( !q.empty() ) {
        int len = q.size() ; 
        for ( i = 0 ; i < len ; i++ ) {
            int now = q.front() ; 
            q.pop() ; 
            if ( node[now][0] == 0 ) {
                int num = node[now][1] ; 
                ans += (double)(num*p*pow(1+r,(double)k)) ;  
            }
            else {
                for ( j = 0 ; j < node[now].size() ; j++ ) 
                    q.push(node[now][j]) ; 
            }
        }
        k++ ; 
    }
    printf("%.1lf\n",ans) ; 
    return 0 ; 
}