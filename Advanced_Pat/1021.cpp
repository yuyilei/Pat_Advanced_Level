#include<vector>
#include<iostream>
using namespace std ;
vector<int> pre ;
vector<int> mapp [10001] ;  
int depth[10001] ; 
int maxx = 0, n ;
bool visited[10001] = {false} ; 

int root(int a) {
    if ( pre[a] != a ) 
        pre[a] = root(pre[a]) ; 
    return pre[a] ; 
}

void init_visit() {
    for ( int i = 1 ; i <= n ; i++ ) 
        visited[i] = false ; 
}

void Union(int a, int b) {
    int x = root(a) ; 
    int y = root(b) ; 
    if ( x != y ) 
        pre[x] = y ; 
}

int dfs(int now) {
    if ( visited[now] ) 
        return 0 ; 
    visited[now] = true ; 
    int len = mapp[now].size() ; 
    int max_depth = 0 ; 
    for ( int i = 0 ; i < len ; i++ ) {
        if ( !visited[mapp[now][i]] ) { 
            int tmp = dfs(mapp[now][i]) ; 
            max_depth = max(max_depth,tmp) ;  
        }
    }
    return max_depth + 1 ; 
}

int main() {
    int i, j, a, b, sum = 0 ;
    cin >> n ; 
    pre.resize(n+1) ; 
    for ( i = 1 ; i < n + 1 ; i++ ) 
        pre[i] = i ; 
    for ( i = 0 ; i < n - 1 ; i++ ) {
        cin >> a >> b ;  
        mapp[a].push_back(b) ; 
        mapp[b].push_back(a) ; 
        Union(a,b) ; 
    } 
    for ( i = 1 ; i < n + 1 ; i++ ) 
        if ( pre[i] == i ) 
            sum++ ; 
    if ( sum != 1 ) {
        cout << "Error: " << sum << " components" << endl ; 
        return 0 ; 
    }
    for ( i = 1 ; i <= n ; i++ ) {
        init_visit() ; 
        depth[i] = dfs(i) ; 
        maxx = max(depth[i],maxx) ;  
    }
    for ( i = 1 ; i <= n ; i++ ) 
        if ( depth[i] == maxx )
            cout << i << endl ; 
    return 0 ;
}
