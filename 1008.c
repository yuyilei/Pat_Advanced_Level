#include<stdio.h>
int main() {

    int n ;
    int a[100] ;
    int sum ; 
    int i ;

    scanf("%d",&n) ;


    for ( i =0 ; i < n ; i++) 
        scanf("%d",&a[i]) ;

    sum = 5 * n ;
    int floor = 0 ;

    for ( i = 0 ; i < n ;i ++){
    
        if ( a[i] > floor){
        
            sum += 6*(a[i]-floor) ;
            floor = a[i] ;
        }
        else if  (a[i] < floor ){
        
            sum += 4*(floor - a[i]) ;
            floor = a[i] ;
        }
    }

    printf("%d",sum) ; 
    return 0 ;  
}
