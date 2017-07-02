#include<math.h>
#include<cstdio>
using namespace std ;
int gcd ( int a , int b ) {
    return (b==0) ? a : gcd( b , a % b) ; // 辗转相除发得到最大公因数  
}
int main() {
    int a , b , num , temp , i , sum = 0 ,  sum1 = 0 , sum2 = 1 , temp2 ; 
    scanf("%d",&num) ; 
    for ( i = 0 ; i < num ; i++ ){
        scanf("%d/%d",&a,&b) ; 
        sum += ( a / b )  ; // 把假分数超出的部分存到sum 里 ，时间比较短
        a %= b ; 
        temp = fabs( gcd ( a , b )) ; 
        a /= temp ; // 通分 
        b /= temp ;
        temp2 = fabs( (b * sum2 ) / gcd( b , sum2 ) ) ; // 最小公倍数是两数之积除以最大公因数 
        sum1 *= ( temp2 / sum2 ) ; // 前i项的分子 
        sum1 += ( a * temp2 / b ) ; 
        sum2 = temp2 ; // 前i项的分母 
    }
    sum += ( sum1 / sum2 ) ; 
    temp = fabs( gcd(sum1,sum2) ) ; 
    sum1 /= temp ; 
    sum2 /= temp ;
    sum1 %= sum2 ; 
    if ( ( sum != 0 ) || ( sum == 0 && sum1 == 0 )){
        printf("%d",sum) ;
        if ( sum1 != 0 ) printf(" ") ; 
    }
    if ( sum1 != 0 ) {
        printf("%d/%d",sum1,sum2) ; 
    }
    return 0 ; 
}
