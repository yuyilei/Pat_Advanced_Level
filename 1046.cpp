#include<cstdio>
using namespace std ; 
int main() {
    int i , j , n , m , *a , p , q , sum1 , sum2 ; 
    scanf("%d",&n) ; 
    a = new int[n] ; 
    for ( i = 0 ; i < n ; i++ )
        scanf("%d",&a[i]) ; 
    scanf("%d",&m) ; 
    for ( i = 0 ; i < m ; i++ ){
        scanf("%d%d",&p,&q) ; 
        p-- ; 
        q-- ; 
        if ( p > q ) { j = q ; q = p ; p = j ; }
        for ( sum1 = 0 , j = p ; j < q ; j++ )
            sum1 += a[j] ; 
        for ( sum2 = 0 , j = p - 1 ; j >= 0 ; j--) { 
            sum2 += a[j] ; 
            if ( sum2 > sum1 ){
                break ; 
            }
        }
        for ( j = n - 1 ; j > q - 1 && sum2 <= sum1 ; j-- ) {
            sum2 += a[j] ; 
        }
        printf("%d\n",((sum1 > sum2 ) ? sum2 : sum1) ) ; 
    }
    return 0 ; 
}
