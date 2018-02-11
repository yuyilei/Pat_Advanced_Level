#include<iostream>
#include<vector> 
using namespace std ; 

int n, m, num = 0 ; 
int visit[501] = {0} ; 
vector<vector<int> > graph ;  
// 一个连通图，如果它各个点的度都是偶数的话，就是Eulerian，正好只有两个点的度是奇数的话，它是Semi-Eulerian，其他的就是Non-Eulerian 
// 先用dfs判断是否连通 

void dfs(int root) {
    visit[root] = 1 ; 
    num++ ; 
    for ( int i = 0 ; i < graph[root].size() ; i++ ) {
        if ( visit[graph[root][i]] == 0 ) 
            dfs(graph[root][i]) ; 
    }
}

int main() {
    int i, j, k, a, b, odd = 0 ;
    cin >> n >> m ; 
    graph.resize(n+1) ;  
    for ( i = 0 ; i < m ; i++ ) {
        cin >> a >> b ; 
        graph[a].push_back(b) ; 
        graph[b].push_back(a) ;  
    }
    dfs(1) ; 
    for ( i = 1 ; i <= n ; i++ ) {
        if ( i != 1 ) 
            cout << " " ; 
        cout << graph[i].size() ; 
        if ( graph[i].size() % 2 ) 
            odd++ ; 
    } 
    cout << endl ; 
    if ( num == n && odd == 0 ) 
        cout << "Eulerian" << endl ; 
    else if ( num == n && odd == 2 ) 
        cout << "Semi-Eulerian" << endl ; 
    else 
        cout << "Non-Eulerian" << endl ; 
    return 0 ; 
}