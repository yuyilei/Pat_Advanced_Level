#include<cstdio>
#include<math.h>
using namespace std ; 
int gcd ( int a ,int b ) {
    return ( b == 0 ) ? a : gcd ( b , a % b ) ; 
}
int main() {
    int a1 , b1 , a2 , b2 , a3 , b3 , temp , temp1 , temp2 ; 
    scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2) ; 
    temp1 = abs(gcd(a1,b1)) ; 
    a1 /= temp1 ; 
    b1 /= temp1 ; 
    if ( a2 != 0 ){
        temp1 = abs(gcd (a2,b2) ) ;
        a2 /= temp1 ; 
        b2 /= temp1 ;
    }
    temp = ( b1 * b2) / abs(gcd( b1 , b2 )) ;
    b3 = temp ; 
    a3 = ( a1 * temp / b1 ) + ( a2 * temp / b2 ) ; 
    temp = abs(gcd(a3 , b3)) ; 
    a3 /= temp ; 
    b3 /= temp ; 

    return 0 ; 
}
