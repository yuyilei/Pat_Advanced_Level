#include<cstdio>
#include<string.h>
using namespace std ;
int main() {
    char a , b , c[9999]  , tmp ;
    int i = 0 , num1 , flag1 ,flag2 = 0 , d ;
    scanf("%c",&a) ;
    scanf("%c",&tmp) ;
    while ( tmp != 'E' ) {
        if ( tmp != '.' )
            c[flag2++] = tmp ; // flag2表示数字的长度
        else
            flag1 = flag2 ;  // flag1表示小数点的位置
        scanf("%c",&tmp) ;
    }
    scanf("%c",&b) ;
    scanf("%d",&d) ;
    if ( a == '-' ) {  printf("-") ; }
    if ( b == '-' ) {
        printf("0.") ;
        for ( i = 0 ; i < d - flag1 ; i++ ) { printf("0") ; }
        printf("%s\n",c) ;
    }
    else {
        for ( i = 0 ; i < flag1 ; i++ )
            printf("%c",c[i]) ;
        num1 = ( flag2 - 1 > d ) ? flag2 - 1 : d ;
        for ( i = 0 ; i < num1 ; i++ ) {
            if ( i == d ) { printf(".") ; }
            printf("%c",((i+flag1)>=flag2)?'0':c[i+flag1]) ;
        }
    }
    return 0 ;
}
