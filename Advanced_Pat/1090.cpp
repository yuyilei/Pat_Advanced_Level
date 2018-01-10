#include<vector>
#include<cstdio>
#include<queue>
#include<iostream>
#include<cmath>
using namespace std ;
int main() {
    int n, i ,j, t, root, k = -1, num = 0 ;
    double p, r, ans = 0 ; 
    cin >> n >> p >> r ; 
    r /= 100.0 ; 
    vector<vector<int> > node (n) ; 
    for ( i = 0 ; i < n ; i++ ) {
        cin >> t ; 
        if ( t == -1 ) 
            root = i ;
        else 
            node[t].push_back(i) ; 
    }
    queue<int> q ;
    q.push(root) ; 
    while ( !q.empty() ) {
        int len = q.size() ; 
        num = 0 ; 
        for ( i = 0 ; i < len ; i++ ) {
            int now = q.front() ; 
            q.pop() ; 
            if ( node[now].size() == 0 ) 
                num++ ; 
            for ( j = 0 ; j < node[now].size() ; j++ ) 
                q.push(node[now][j]) ; 
        }
        k++ ; 
    }
    ans = (double)(p*pow((1+r),(double)k)) ; 
    printf("%.2lf %d\n",ans,num) ; 
    return 0 ; 
}