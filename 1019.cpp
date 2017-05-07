#include<iostream>
using namespace std ;
int main() {
    long a , b , i , p , len , q  = 0 , res[50] , flag = 0 ; 
    cin >> a >> b ; 
    while ( a > 0 ){
        res[p++] = a % b ; 
        a /= b ; 
    } 
    len = p-- ; 
    while ( q <= p ){
        if ( res[q++] != res[p--] ){
            flag = 1 ; 
            printf("No\n") ; 
            break ; 
        }
    }
    if ( flag == 0  ){
    printf("Yes\n") ; 
    }
    for ( i = len -1 ; i >= 0 ; i-- ){
        printf("%ld",res[i]) ; 
        if ( i != 0 ){
            printf(" ") ; 
        }
    }
    if ( len == 0 ){
        printf("0") ; 
    }
    return 0 ; 
}
