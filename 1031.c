#include<stdio.h>
#include<string.h>
// 此题有点坑

int main() {

    char str[81] ;
    int i ;
    int lens ;
    gets(str) ;
    lens = strlen(str) ;
    int left ; 
    int bottom ;

    int n1 = (lens+2) / 3  ; // 要让u型看起来尽量"方", 要让左边(包括下面那个),底面,右边(包括下面那个)的大小尽量相近 ,所以先加2 
    left = n1 - 1 ; 
    bottom = lens - 2*left ;

    for ( i = 0 ; i < left ; i ++ ){
    
        for ( int j = 0 ; j < bottom  ; j ++){
        
            if ( j == 0){
            
                printf("%c",str[i]) ;
            }
            else if  ( j == bottom - 1){
            
                printf("%c",str[lens-1-i]) ;
            }
            else {
                printf(" ") ;
            }
        }
        printf("\n") ;
    }

    for ( i = left ; i < left + bottom ; i++ ) 
        printf("%c",str[i]) ;

    return 0 ;
}
