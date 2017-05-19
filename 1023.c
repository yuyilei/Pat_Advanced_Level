#include<stdio.h>
#include<string.h>
int main() {
    char a[22] , b[22] ;
    memset(b,0,22) ; // 一定要先清零,否则。。。b 的长度。。 变很奇怪 
    gets(a) ;
    int len = strlen(a) , j = 0 , i  , ji = 0 , jin = 0 , di = 0 , num[10] = {0} ;
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
    puts(b) ; 
    return 0 ; 
}
