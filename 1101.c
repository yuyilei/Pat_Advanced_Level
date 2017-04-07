#include<stdio.h>
#include<stdlib.h>
int cmp( const void * a , const void * b ) {

    return *(int*) a - *(int*)b ;
}
int main () {
    int n ; 
    int a[100000] ;
    int b[100000] ;
    int i , out = 0 , flag ;
    int res[100000] ; 
    scanf("%d",&n) ;
    for ( i = 0 ; i < n ; i++ ){
    
        scanf("%d",&a[i]) ;
        b[i] = a[i] ;
    }
    qsort(a,n,sizeof(int),cmp) ;
    flag = 0  ;
    for ( i = 0 ; i < n ; i++ ){
    
        if ( b[i] == a[i] && ( flag <  b[i])) {
            res[out++] = a[i] ;   
        } 

        if ( flag < b[i]) {
        
            flag = b[i] ;
        }
    }

    printf("%d\n",out) ;
    if ( out == 0 ){
    
        printf("\n") ;
        return 0 ; 
    }
    for ( i = 0 ; i < out ; i ++ ){
    
        printf("%d",res[i]) ;
        if ( i  != out -1 ){
        
            printf(" ") ;
        }
    }
    return 0 ; 
}
