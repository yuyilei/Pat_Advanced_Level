#include<cstdio>
#include<string.h>
using namespace std ;
int main() {
    int num ,i , j , now = 0 ;
    char tmp1[80] , tmp2[80] ;
    double sum = 0 , e ;
    scanf("%d" ,&num) ;
    for ( i = 0 ; i < num ; i++ ) {
        scanf("%s",tmp1) ;
        sscanf(tmp1,"%lf",&e) ;    // 把字符串以double的格式写入e
        sprintf(tmp2,"%.2lf",e) ;   // 把e以两位浮点数的格式写入tmp2
        j = strlen(tmp1) ;
        if ( strncmp(tmp1,tmp2,j) || e > 1000 || e < -1000 ) {
            printf("ERROR: %s is not a legal number\n", tmp1) ;
            continue ;
        }
        sum += e ;
        now++ ;
    }
    if ( now == 0 )
         printf("The average of 0 numbers is Undefined\n") ;
    else
          printf("The average of %d %s is %.2f\n",now,(now==1)?"number":"numbers",sum / now ) ;
    return 0 ;
}
