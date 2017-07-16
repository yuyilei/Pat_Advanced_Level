#include<stdio.h>
int main() {

    char s[100000] ;
    gets(s) ;
    long len = strlen(s) ;
    long long p = 0 , pa = 0 , pat = 0 ;

    for ( int i = 0 ; i < len ; i++ ) {
    
        if ( s[i] == 'P'){
        
            p++ ; 
        }
        if ( s[i] == 'A'){ 
        
            pa += p ;
        }
        if ( s[i] == 'T'){
        
            pat += pa ;
        }
    }
   printf("%lld",pat%1000000007) ;
   return 0 ; 
}
