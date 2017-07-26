#include<cstdio>
#define ALL 100000
using namespace std ;
int main() {
    int n , m , i , j , min = 1000000000 , now = 0 , count = 0 ;
    scanf("%d %d",&n,&m) ;
    int **p = new int *[ALL] ;
    int *num = new int [n] ;
    for ( i = 0 ; i < ALL ; i++ ) { p[i] = new int [2] ; }
    for ( i = 0 ; i < n   ; i++ )
        scanf("%d",&num[i]) ;
    for ( i = 0 , j = 0 ; i < n && j <= n ;   ) {
        if ( now < m ) { now += num[j++] ; }
        else if ( now >= m ) {
            if ( now <= min  ) {
                if ( now < min ) {
                    count = 0 ;
                    min = now ;
                }
                p[count][0] = i + 1 ;
                p[count++][1] = j  ;
            }
            now -= num[i] ;
            i++ ;
        }
    }
    for ( i = 0 ; i < count ; i++ )
        printf("%d-%d\n",p[i][0],p[i][1]) ;
    return 0 ;
}
