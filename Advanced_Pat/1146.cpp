#include<cstdio>
#include<vector>
using namespace std ;
 
int Degree[1001] = {0}, tmp[1001] = {0} ;
int order[1001] = {0} ;
int graph[1001][1001] = {0} ; 
int n ; 

/*
判断是不是拓扑排序，
判断入度是不是等于0。。
每次删去一个点，就要更新入度. 
*/

bool judge() {
    int i, j ; 
    for ( i = 1 ; i <= n ; i++ )
        tmp[i] = Degree[i] ; 
    for ( i = 0 ; i < n ; i++ ) {
        int now = order[i] ; 
        if ( tmp[now] != 0 ) {
            return false ; 
        } 
        for ( j = 1 ; j <= n ; j++ ) {
            if ( graph[now][j] == 1 ) 
                tmp[j]-- ; 
        }
    }
    return true ; 
} 

int main() {
    int i, m, k, j, x, y ;
    vector<int> res ; 
    scanf("%d %d",&n,&m) ; 
    for ( i = 0 ; i < m ; i++ ) {
        scanf("%d %d",&x,&y) ; 
        Degree[y]++ ;  
        graph[x][y] = 1 ; 
    } 
    scanf("%d",&k) ; 
    for ( i = 0 ; i < k ; i++ ) {
        for ( j = 0 ; j < n ; j++ ) 
            scanf("%d",&order[j]) ; 
        if ( !judge() ) 
            res.push_back(i) ; 
    } 
    for ( i = 0 ; i < res.size() ; i++ ) {
        printf("%d",res[i]) ; 
        if ( i != res.size() - 1 ) 
            printf(" ") ; 
    }
    printf("\n") ; 
    return 0 ;
}