#include<stdio.h>
#include<string.h>
int main() {

    char a[10000] ;
    char b[10000] ; 
    int number1[128] = {0} ;
    int number2[128] = {0} ;
    gets(a) ;
    gets(b) ;
    int lena = strlen(a) ;
    int lenb = strlen(b) ;
    
    for ( int i = 0 ; i < lena ; i++){
    
        number1[(int)a[i]]++ ; 
    }

    for ( int i = 0 ; i < lenb ; i++) {
    
        number2[(int)b[i]]++ ;
    }

    for ( int i = 0 ; i < 128 ; i++) {
   
       if ( number2[i] != 0 ){
       
           number1[i] = 0 ;
       } 
    }

    for  ( int i = 0 ; i < lena ; i++ ){
    
        if ( number1[(int)a[i]] != 0 )
            printf("%c",a[i]) ;
    }
    return 0 ; 
}
