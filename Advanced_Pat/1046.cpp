#include<cstdio>
using namespace std ; 
int main() { // 无非就是比正向相加和反向相加的大小区别,sum是所有的数的总和,sum1是正向相加，sum2是反向相加 b[i] 是前i项的和
    int i , j , n , m , *a , *b , p , q , sum1 , sum2 , sum = 0 ; 
    scanf("%d",&n) ; 
    a = new int[n] ; 
    b = new int[n] ; 
    for ( i = 0 ; i < n ; i++ ){
        scanf("%d",&a[i]) ; 
        sum += a[i] ; 
        b[i] = ( i == 0 ) ? ( a[0] ) : ( b[i-1] + a[i] ) ; 
    }
    scanf("%d",&m) ; 
    for ( i = 0 ; i < m ; i++ ){
        scanf("%d%d",&p,&q) ; 
        if ( p > q ) { j = q ; q = p ; p = j ; }
        sum1 = b[q-2] - b[p-2] ;
        sum2 = sum - sum1 ; 
        printf("%d\n",((sum1 > sum2 ) ? sum2 : sum1) ) ; 
    }
    return 0 ; 
}
