#include<cstdio>
#define ALL 100000
using namespace std ;  //  网上看到这题还有中二分发查找，但是我没学过，先不写
int main() {
    int n , m , i , j , min = 1000000000 , now = 0 , count = 0 ;
    scanf("%d %d",&n,&m) ;
    int **p = new int *[ALL] ;
    int *num = new int [n] ;
    for ( i = 0 ; i < ALL ; i++ ) { p[i] = new int [2] ; } // 二维数组存答案
    for ( i = 0 ; i < n   ; i++ )
        scanf("%d",&num[i]) ;
    for ( i = 0 , j = 0 ; i < n && j <= n ;   ) { // i , j 的大小根据情况动态增加
        if ( now < m ) { now += num[j++] ; }    // 当前总和不到m,往后加一位,j加一
        else if ( now >= m ) {                  // 当前总和大于等于m,查看是否符合条件后把第i位的数减去，i加一
            if ( now <= min  ) {
                if ( now < min ) {
                    count = 0 ;
                    min = now ;
                }
                p[count][0] = i + 1 ;
                p[count++][1] = j  ;
            }
            now -= num[i] ;
            i++ ;
        }
    }
    for ( i = 0 ; i < count ; i++ )
        printf("%d-%d\n",p[i][0],p[i][1]) ;
    return 0 ;
}
