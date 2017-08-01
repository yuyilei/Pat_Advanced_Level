#include<cstdio>
#include<math.h>
using namespace std ;
int gcd ( int a ,int b ) {
    return ( b == 0 ) ? a : gcd ( b , a % b ) ;
}
int main() {
    char k[4] = {'+' , '-' , '*' , '/' } ;
    int a1 , b1 , a2 , b2 , a3[4] , b3 , temp , temp1 , temp2 , c1 , c2 , c3 , d1 , d2 , d3 , i ;
    scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2) ;
    temp1 = fabs(gcd(a1,b1)) ;
    a1 /= temp1 ;
    b1 /= temp1 ;
    if ( a2 != 0 ){
        temp1 = fabs(gcd (a2,b2) ) ;
        a2 /= temp1 ;
        b2 /= temp1 ;
    }
    c1 = a1 / b1 ;
    c2 = a2 / b2 ;
    d1 = fabs(a1 % b1) ;
    d2 = fabs(a2 % b2) ;
    temp = ( b1 * b2) / fabs(gcd( b1 , b2 )) ;
    b3 = temp ;
    a3[0] = ( a1 * temp / b1 ) + ( a2 * temp / b2 ) ;
    a3[1] = ( a1 * temp / b1 ) - ( a2 * temp / b2 ) ;
    a3[2] = ( a1 * temp / b1 ) * ( a2 * temp / b2 ) ;
    if ( a2 != 0 )
        a3[3] = ( a1 * temp / b1 ) / ( a2 * temp / b2 ) ;
    for ( i = 0 ; i < 4 ; i++ )
        printf(" %d\n",a3[i]) ;
    for ( i = 0 ; i < 4 ; i++ ) {
        temp = fabs(gcd(a3[i] , b3)) ;
        a3[i] /= temp ;
        b3 /= temp ;
        c3 = a3[i] / b3 ;
        d3 = fabs(a3[i] % b3) ;
        if ( a1 < 0 ) {
            if ( c1 != 0 ) {
                if ( b1 == 1 )
                    printf("(%d) ",c1) ;
                else
                    printf("(%d %d/%d) ",c1,d1,b1) ;
            }
            else {
                printf("(%d/%d) ",a1,b1) ;
            }
        }
        else if ( a1 == 0 ) {
            printf("0") ;
        }
        else if ( a1 > 0 ) {
            if ( c1 != 0 )
                printf("%d %d/%d ",c1,d1,b1) ;
            else
                printf("%d/%d ",a1,b1) ;
        }
        printf("%c ",k[i]) ;
        if ( a2 < 0 ) {
            if ( c2 != 0 ) {
                if ( b2 == 1 )
                    printf("(%d) ",c2) ;
                else
                    printf("(%d %d/%d) ",c2,d2,b2) ;
            }
            else {
                printf("(%d/%d) ",a2,b2) ;
            }
        }
        else if ( a2 == 0 ) {
            printf("0 ") ;
        }
        else if ( a2 > 0 ) {
            if ( c2 != 0 )
                printf("%d %d/%d ",c2,d2,b2) ;
            else
                printf("%d/%d ",a2,b2) ;
        }
        printf("= ") ;
        if ( i == 3 && a2 == 0 ) {
            printf("Inf\n") ;
            break ;
        }
        if ( a3[i] < 0 ) {
            if ( c3 != 0 ) {
                if ( b3 == 1 )
                    printf("(%d) ",c3) ;
                else
                    printf("(%d %d/%d) ",c3,d3,b3) ;
            }
            else {
                printf("(%d/%d) ",a3[i],b3) ;
            }
        }
        else if ( a3[i] == 0 ) {
            printf("0") ;
        }
        else if ( a3[i] > 0 ) {
            if ( c3 != 0 )
                printf("%d %d/%d ",c3,d3,b3) ;
            else
                printf("%d/%d ",a3[i],b3) ;
        }
        printf("\n") ;

    }
  //  printf("%d %d %d %d %d %d %d %d %d %d %d %d \n",a1,b1,c1,d1,a2,b2,c2,d2,a3,b3,c3,d3) ;
    return 0 ;
}
