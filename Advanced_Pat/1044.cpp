#include<cstdio>
#define ALL 500
using namespace std ;
int main() {
    int n , m , i , j , sum = 0 , min , flag = 0 , now = 0 , count = 0 , index = 0 ;
    scanf("%d %d",&n,&m) ;
    int **p = new int *[ALL] ;
    int *num = new int [n] ;
    int a[ALL] ;
    for ( i = 0 ; i < ALL ; i++ ) { p[i] = new int [2] ; }
    for ( i = 0 ; i < n   ; i++ ) {
        scanf("%d",&num[i]) ;
        sum += num[i] ;
    }
    min = sum ;
    for ( i = 0 ; i < n ; i++ ) {
        for ( j = i , now = 0 ; j < n ; j++ ) {
            now += num[j] ;
            if ( now >= m ) {
                if ( now < min ) {
                    count = 0 ;
                    min = now ;
                    index = 0 ;
                    a[count] = index++ ;
                    p[a[count]][0] = i + 1 ;
                    p[a[count++]][1] = j + 1 ;

               }
                else if ( now == min ) {
                    a[count] = index++  ;
                    p[a[count]][0] = i + 1 ;
                    p[a[count++]][1] = j + 1 ;

                }
              //  printf("i %d , j %d , now %d\n",i,j,now) ;
                break ;
            }
        }
    }
    for ( i = 0 ; i < count ; i++ ) {
        printf("%d-%d\n",p[a[i]][0],p[a[i]][1]) ;
    }
    return 0 ;
}
