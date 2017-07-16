#include<stdio.h>
#include<string.h>

int main () {

    long long num ;
    char a[20] ;
    gets(a) ;
    int len = strlen(a) ;
    long long ten = 1 ;
    long long sum = 0 ;
    long long out = 0 ; 

    for ( int  i = len-1 ; i >=0 ; i--){
    
        sum += (a[i]-'0')*ten ;
        ten *= 10 ;
    }
    
    if ( a[len-1] != '0') {
    
        out += 1 ;
    }

    out += ( sum / 10 ) ;
    ten = 100 ;
    int temp1 = 10 ;
    for ( int i = len - 2 ; i >= 0 ; i--){
        out += ((sum/ten)*temp1) ; 
        if ( a[i] == '1') {
        
            out += ((sum % temp1)+1) ;
        }
        if ( a[i] > '1' ){
        
            out += temp1 ;
        }
        temp1 *= 10 ;
        ten *= 10 ;
    }

    printf("%lld",out) ;
    return 0 ; 
}
