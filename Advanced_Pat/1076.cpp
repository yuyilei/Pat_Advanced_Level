#include<iostream>
#include<vector>
#include<queue> 
using namespace std ; 

vector<vector<int> > mapp ; 
int n, level ; 

// 就是带层数限制的广度优先遍历。。。。。。 
int bfs(int root) {
    vector<bool> visit (n+1,false) ; 
    queue<int> q ; 
    visit[root] = true ; 
    int cnt = 0, now = 0 ; 
    q.push(root) ; 
    while ( !q.empty() && now < level ) {
        int len = q.size() ; 
        for ( int i = 0 ; i < len ; i++ ) {
            int val = q.front() ; 
            q.pop() ; 
            for ( int j = 0 ; j < mapp[val].size() ; j++ ) {
                int node = mapp[val][j] ; 
                if ( visit[node] ) 
                    continue ; 
                cnt++ ; 
                q.push(node) ; 
                visit[node] = true ;     
            }
        }
        now++ ; 
    } 
    return cnt ; 
}

int main() {
    int i, j, t, k ; 
    cin >> n >> level ; 
    mapp.resize(n+1) ;  
    for ( i = 0 ; i < n ; i++ ) {
        cin >> k ; 
        for ( j = 0 ; j < k ; j++ ) {
            cin >> t ; 
            mapp[t].push_back(i+1) ; 
        }
    }
    cin >> k ; 
    for ( i = 0 ; i < k ; i++ ) {
        cin >> t ; 
        cout << bfs(t) << endl ; 
    }
    return 0 ; 
}