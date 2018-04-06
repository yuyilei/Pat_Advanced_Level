#include<cstdio>
#include<vector> 
using namespace std ;

int graph[201][201] = {0} ; 

/*
先判断是不是Clique，
然后再把其余的点加入点集，查看是不是Clique 
*/

int judge(vector<int> tmp, int flag) {
    if ( flag != -1 ) 
        tmp.push_back(flag) ; 
    int res = 1, k = tmp.size() ; 
    for ( int p = 0 ; res && p < k ; p++ ) {
        for ( int q = p + 1 ; res && q < k ; q++ ) {
            if ( graph[tmp[p]][tmp[q]] == 0 ) 
                res = 0 ; 
        }
    }
    return res ; 
} 
int main() {
    int i, j, e, v, t1, t2, m, k, q, p, t ; 
    scanf("%d %d",&v,&e) ; 
    for ( i = 0 ; i < e ; i++ ) {
        scanf("%d %d",&t1,&t2) ; 
        graph[t1][t2] = graph[t2][t1] = 1 ;  
    }
    scanf("%d",&m) ; 
    for ( i = 0 ; i < m ; i++ ) {
        scanf("%d",&k) ; 
        vector<int> flag (v+1,0) ; 
        vector<int> tmp ; 
        for ( j = 0 ; j < k ; j++ ) {  
            scanf("%d",&t) ; 
            tmp.push_back(t) ; 
            flag[t] = 1 ; 
        } 
        if ( judge(tmp,-1) == 0 ) {
            printf("Not a Clique\n") ; 
            continue ; 
        }
        int ifmax = 1 ;
        for ( j = 1 ; j <= v ; j++ ) {
            if ( flag[j] == 0 ) {
                if ( judge(tmp,j) == 1 ) {
                    ifmax = 0 ; 
                    break ; 
                } 
            }
        }
        if ( ifmax ) 
            printf("Yes\n") ; 
        else 
            printf("Not Maximal\n") ; 
    }
    return 0 ; 
}