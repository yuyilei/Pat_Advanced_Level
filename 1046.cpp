#include<cstdio>
using namespace std ; 
int main() {
    int i , j , n , m , *a , p , q , sum1 , sum2 , sum = 0 ; 
    scanf("%d",&n) ; 
    a = new int[n] ; 
    for ( i = 0 ; i < n ; i++ ){
        scanf("%d",&a[i]) ; 
        sum += a[i] ; 
    }
    scanf("%d",&m) ; 
    for ( i = 0 ; i < m ; i++ ){
        scanf("%d%d",&p,&q) ; 
        p-- ; 
        q-- ; 
        if ( p > q ) { j = q ; q = p ; p = j ; }
        for ( sum1 = 0 , j = p ; j < q ; j++ )
            sum1 += a[j] ; 
        sum2 = sum - sum1 ; 
        printf("%d\n",((sum1 > sum2 ) ? sum2 : sum1) ) ; 
    }
    return 0 ; 
}
