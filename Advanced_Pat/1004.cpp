#include<iostream>
#include<vector>
#include<queue> 
using namespace std ; 

int main() {
    int n, m, i, j, node, k, num = 0, now, t ;
    cin >> n >> m ; 
    vector<vector<int> > tree (n+1) ;  
    for ( i = 0 ; i < m ; i++ ) {
        cin >> node >> k ; 
        for ( j = 0 ; j < k ; j++ ) {
            cin >> t ; 
            tree[node].push_back(t) ; 
        } 
    }
    queue<int> q ; 
    q.push(1) ; 
    while ( !q.empty() ) {
        int len = q.size() ; 
        num = 0 ;
        for ( i = 0 ; i < len ; i++ ) {
            now = q.front() ; 
            q.pop() ; 
            if ( tree[now].size() == 0 ) 
                num++ ; 
            else { 
                for ( j = 0 ; j < tree[now].size() ; j++ ) 
                    q.push(tree[now][j]) ; 
            }
        }
        if ( now != 1 )
            cout << " " ; 
        cout << num ; 
    }
    cout << endl ; 
    return 0 ; 
}   