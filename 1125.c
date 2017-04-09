#include<stdio.h>
#include<stdlib.h>
int cmp ( const void* a , const void * b) {
    return *( int*) a - *( int*) b ;
}
int main() {
    int n , i , res ; 
    int a[10001] ;
    scanf("%d",&n) ;
    for ( i = 0 ; i < n ; i++) {
        scanf("%d",&a[i]) ;
    }
    qsort(a,n,sizeof(int),cmp) ;
    res = a[0] ;
    for ( i = 1 ; i < n ; i ++ ) {
        res = ( res + a[i]) / 2 ; 
    }
    printf("%d",res) ; 
    return 0 ; 
}
