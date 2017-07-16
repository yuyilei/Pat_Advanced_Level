#include<stdio.h>
int main() {
    int  n, i ; 
    long  num[100001]={0} ; // 这个地方要是long ，不然会溢出
    float a ,sum = 0  ;
    scanf("%d",&n) ;
    for ( i = 0 ; i < n /2 ; i++) {
        num[i] = (n-i)*(i+1) ;
        num[n-i-1] = num[i] ; 
    }
    if ( n % 2 ){
        num[n/2] = (n/2+1)*(n/2+1) ;
    }
    for ( i = 0 ; i < n ; i++ ){
        scanf("%f",&a) ; 
        sum += ( num[i]*a) ;
    }
    printf("%.02f",sum) ; 
    return 0 ; 
}
