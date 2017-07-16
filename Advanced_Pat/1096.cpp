#include<cstdio>
#include<math.h>
using namespace std ; 
int main() {
    long  n , i , j , k ,  temp , a[100] , num = 0 , flag = 0 , tmp2  ; 
    scanf("%ld",&n) ; 
    float s = sqrt(n)  ; 
    for ( i = 2 , j = 0 ; i <= s ; i++ ){
        if ( n % i == 0 ){
            a[j++] = i ; 
        }
    }
    a[j++] = n ; 
    for ( temp = 0 , num = 0 , k = j , i = 0 ; i < k ; i++ ){
        temp = 0 ; 
        tmp2 = n ; 
        for ( temp = 0 , tmp2 = n ; a[i+temp] == (a[i]+temp) && tmp2 % a[i+temp] == 0  ; temp++ ) {
                tmp2 /= a[i+temp] ; 
            }
        if ( temp > num ){
            num = temp ; 
            flag = i ; 
        }
    }
    printf("%ld\n",num) ; 
    for ( i = flag ; i < flag + num - 1 ; i++ ){
        printf("%ld*",a[i]) ; 
    }
    printf("%ld\n",a[flag+num-1]) ; 
    return 0 ; 
}
