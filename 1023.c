#include<stdio.h>
#include<string.h>
int main() {

    char a[22] ;  
    char b[22] ;
    int num[10] = {0} ;
    gets(a) ;
    int len = strlen(a) ;
    int j = 0 , i ;
    int ji = 0 , jin = 0 ;
    int di = 0 ;

    for ( i = len-1 ; i >= 0 ; i--){
    
        ji = (a[i] - '0')*2 ;
        di = ji % 10 ;
        b[i] = jin + di + '0' ;
        num[a[i]-'0']++ ;
        num[b[i]-'0']-- ;
        jin = ( ji + jin ) / 10 ;
    }
    
    for ( i = 0 ; i < 10 ; i++){
    
        if ( num[i] != 0 ){
        
            printf("No\n") ;
            if ( jin != 0 ){
            
                printf("%d",jin) ;// 输出最高位
            }
            break ;
        }
    }

    if ( i == 10 ){
    
        printf("Yes\n") ;
    }

    for ( i = 0 ; i < len ; i ++ ){
    
        printf("%c",b[i]) ; // 不能用pust(b)或者printf("%s",b) 后面会多一个@莫名其妙,不知道为什么
    }

    return 0 ; 
}
