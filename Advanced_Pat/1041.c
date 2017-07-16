#include<stdio.h>
int main() {

    int number[100000] = {0} ;
    int count[100000] = {0} ;
    int n ;
    int i ; 
    scanf("%d",&n) ;
    
    for ( i = 0 ; i < n ; i++) {
    
        scanf("%d",&number[i]) ;
        count[number[i]]++ ;
    }
    
    for  ( i = 0 ; i < n ; i++){
    
        if ( count[number[i]] == 1 ){
        
            printf("%d",number[i]) ;
            return 0 ;
        }
    }
    printf("None") ;
    return 0 ; 
}
