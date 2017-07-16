#include<stdio.h>
#include<stdlib.h>
int cmp( const void * a ,const void * b ) {
    return *( long *) a -*( long * ) b  ;
}
int main() {
    long  a[100000] , b[100000] , i , couple , all , x , y , out[100000] = {0} , k = 0 , t = 0  ;
    for ( int i = 0 ; i < 100000 ; i++) {
        a[i] = -1 ;
        b[i] = -1 ;
    }
    scanf("%ld",&couple) ;
    for ( i = 0 ; i < couple ; i++ ){
        scanf("%ld%ld",&x,&y) ;
        a[x] = y ; 
        b[y] = x ;
    }
    scanf("%ld",&all) ;
    long left[100000] = {0} ;
    for ( i = 0 ; i < all ; i++) {
        scanf("%ld",&x) ;
        if ( a[x] == -1  && b[x] == -1 ) {
            out[k++] = x ;           
        }
        else if ( a[x] >= 0 ) {
            b[x] = -2 ; 
            left[t++] = x ;
        }
        else if ( b[x] >= 0  ){
            a[x] = -2 ;
            left[t++] = x ;
        }
    }
    for ( i = 0 ; i < t ; i++ ){
        if (!(( a[left[i]] == -2 && b[b[left[i]]] == -2 ) || ( b[left[i]] == -2 && a[a[left[i]] ]== -2 ))) { 
            out[k++] = left[i] ; 
        }
    }
    qsort(out,k,sizeof(long),cmp) ;
    printf("%ld\n",k) ;
    for ( i = 0 ; i < k ; i++ ){
        printf("%05ld",out[i]) ;
        if ( i != k-1 ) {
            printf(" ") ;
        }
    }
    return 0 ; 
}
