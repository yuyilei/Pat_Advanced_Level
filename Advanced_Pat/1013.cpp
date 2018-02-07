#include<cstring>
#include<iostream>
using namespace std ; 

int edge[1001][1001] = {0} ; 
int n, k, m ; 
int visit[1001] = {0} ; 

// 一个无向连通图，去除一条边之后，需要连接多少条边，才能让剩下图变成连通图
// 问题的本质就是，去除一条边之后，有num个连通分量，就需要num-1条边连接。 
// 用dfs统计图的连通分量的个数 
// 注意每次都要将visit数组设为0 

void dfs(int root) {
    visit[root] = 1 ; 
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( edge[root][i] == 1 && visit[i] == 0 ) {
            visit[i] = 1 ; 
            dfs(i) ; 
        }
    }
}

int main() {
    cin >> n >> m >> k ; 
    int i, j, x, y, t, num ; 
    for ( i = 0 ; i < m ; i++ ) {
        cin >> x >> y ; 
        edge[x][y] = 1 ; 
        edge[y][x] = 1 ; 
    }
    for ( i = 0 ; i < k ; i++ ) {
        cin >> t ; 
        memset(visit,0,sizeof(visit)) ;                        // C中头文件为<string.h>  ，C++中头文件为<cstring>  
        visit[t] = 1 ; 
        num = 0 ; 
        for ( j = 1 ; j <= n ; j++ ) {
            if ( visit[j] == 0 ) {
                num++ ; 
                dfs(j) ; 
            }
        }
        cout << num-1 << endl ; 
    }
    return 0 ; 
}