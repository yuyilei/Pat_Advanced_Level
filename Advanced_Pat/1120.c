#include<stdio.h>
int sum ( int n ) {
    int  res  = 0 ; 
    while ( n > 0 ) {
        res += ( n % 10 ) ;
        n /= 10 ;
    }
    return res  ; 
}
int main() {
    int n , k , i, t = 0 , a[37] = {0};
    scanf("%d",&n) ;
    for ( i = 0 ; i < n ; i++) {
        scanf("%d",&k) ;
        int s  = sum (k) ;
        if ( a[s] == 0 ){
            t++ ;
        }
        a[s]++ ;
    }
    i = 0 ;
    printf("%d\n",t) ;
    while ( t > 0 ) {
        if ( a[i] != 0 ) {
            printf("%d",i) ;
            t-- ;
            if ( t != 0 ){
                printf(" ") ;
            }
        }
        i++ ; 
    }
    return 0 ; 
}
