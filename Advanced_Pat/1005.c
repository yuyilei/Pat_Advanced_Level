#include<stdio.h>
#include<string.h>

int main() {

    char num[101] ;
    gets(num) ;
    int sum = 0 ; 
    int i ; 
    for ( i = 0 ; i < strlen(num) ; i++){
        
            sum += num[i] - '0' ;
        }
    
    if ( sum ==0 ){
    
        printf("zero") ;
        return 0 ; 
    }
    int out[100] ;
    i = 0 ; 
    while ( sum > 0 ) {
        
        int  n = sum % 10 ;
        out[i++] = n ; 
        sum /= 10 ;
    }
    
    int len = i  ; 
    for ( i = len - 1 ; i >= 0 ; i-- ){
    
        switch(out[i]) {
        
            case 0 : printf("zero") ; break ;
            case 1 : printf("one") ; break ;
            case 2 : printf("two") ; break ;
            case 3 : printf("three") ; break ;
            case 4 : printf("four") ; break ;
            case 5 : printf("five") ; break ;
            case 6 : printf("six") ; break ;
            case 7 : printf("seven") ; break ;
            case 8 : printf("eight") ; break ;
            case 9 : printf("nine") ; break ;
        }

        if ( i != 0 ){
        
            printf(" ") ;
        }
    }
    return 0 ; 
}

