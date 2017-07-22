#include<cstdio>
#include<queue>
using namespace std ;
struct node {
    int weight , rank , flag ;
} ;
int main() {
    int p , g , i , j , now = -1  , tmp , max  ;
    scanf("%d %d",&p,&g) ;
    struct node * ps =  new struct node  [p] ;
    struct node maxn , t ;
    queue < struct node > qs ;
    for ( i = 0 ; i < p ; i++ ) {
        scanf("%d",&ps[i].weight) ;
        ps[i].flag = i ;
    }
    for ( i = 0 ; i < p ; i++ ){
        scanf("%d",&tmp) ;
        qs.push(ps[tmp])  ;  // 将老鼠按照顺序放入队列中
    }
    while ( qs.size() > 0  ) {
        tmp = qs.size() ; // 本轮要比较的老鼠的数量
        now = ( qs.size() % g  == 0 ) ? ( tmp / g +1 ) : ( tmp / g + 2 ) ;  // 本轮被淘汰的老鼠的名次
        for ( j = 0 , max = -2  ; j < tmp  ; j++ ) {
                t = qs.front() ;
                qs.pop() ;
                ps[t.flag].rank = now ;
                if ( max < t.weight ) {
                    maxn = t ;
                    max = t.weight ;
                }
                if ( j == tmp - 1 ||  ( j + 1 ) % g == 0) {   // 本轮或本组比较结束, 将最大值放入队列里
                    qs.push(maxn) ;
                    max = -2 ;
                }
            }
        if ( qs.size() == 1 ) {
            t = qs.front() ;
            ps[t.flag].rank = 1 ;
            qs.pop() ;
        }
    }
    for ( i = 0 ; i < p - 1 ; i++ )
        printf("%d ",ps[i].rank) ;
    printf("%d\n",ps[p-1].rank) ;
    return 0 ;
}
