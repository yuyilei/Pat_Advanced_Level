#include<cstdio>
#include<queue>
using namespace std ;
struct node {
    int weight , rank , flag ;
} ;
int main() {
    int p , g , i , j , num = 0 , now = -1  , tmp  , max ;
    scanf("%d %d",&p,&g) ;
    struct node * ps =  new struct node  [p] ;
    struct node maxn ;
    int * pa = new int [p] ;
    queue < struct node > qs ;
    for ( i = 0 ; i < p ; i++ ) {
        scanf("%d",&ps[i].weight) ;
        ps[i].flag = 1 ;
    }
    for ( i = 0 ; i < p ; i++ ){
         scanf("%d",&tmp) ;
         pa[tmp] = i ;
    }
    for ( i = 0 ; i < p ; i++ )
        qs.push(ps[pa[i]])  ;
    while ( qs.size() > 0  ) {
        now = qs.size() / g + 2 ;
        i = 0 ;
        queue < struct node > temp ;
        for ( j = 0 ; j < now - 1  ; j++ ) {
            i = 0 ;
            maxn = qs.front() ;
            qs.pop() ;
            while ( i < g - 1  ) {
                struct node t = qs.front() ;
                qs.pop() ;
                if ( maxn.weight < t.weight ) {
                    maxn = t ;
                    maxn.rank = now ;
                }
                else {
                    t.rank = now ;
                }
                if ( qs.size() == 0   )
                    break ;
                i++ ;
            }
            temp.push(maxn) ;
            printf("now1 %d \n",now) ;
            printf("size1  %lu\n",temp.size() ) ;
            printf("weight %d \n",maxn.weight) ;
        }
        if ( temp.size() < g )
            break ;
        qs = temp ;
    }
    for ( i = 0 ; i < g - 1 ; i++ )
        printf("%d ",ps[i].rank) ;
    printf("%d\n",ps[g-1].rank) ;
    return 0 ;
}
