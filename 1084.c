#include<stdio.h>
#include<string.h>
int main() {

    char a[81] ;
    char b[81] ;
    gets(a) ; 
    gets(b) ;
    int num[128] = {0} ;
    int len1 = strlen(a) ;
    int len2 = strlen(b) ;
    int i ; 

    for ( i = 0 ; i < len1 ; i++ ){
    
        a[i] = toupper(a[i]) ;
        num[a[i]]++ ;
    }

    for ( i = 0 ; i < len2 ; i++ ){
    
        b[i] = toupper(b[i]) ;
        num[b[i]] = 0 ;
    }
   
   for ( i = 0 ; i < len1 ; i++){
   
       if ( num[a[i]] != 0 ){
       
           printf("%c",a[i]) ;
           num[a[i]] = 0 ; 
       }
   }
    return 0 ;   
}
