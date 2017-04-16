#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std ; 
int cmp ( int a ,int b ){
    return a > b ; 
}
int main() {
    int all, i  , n , m , k = 0 , j = 0 ; 
    scanf("%d",&all) ;
    vector<int> num(all) ;
    for ( i = 0 ; i < all ; i++){
        scanf("%d",&num[i]) ;
    }
    sort(num.begin(),num.end(),cmp) ;
    m = all ; 
    n = 1 ;
    for ( i = 1 ; m >= n ; i++ ){
        if ( all % i == 0  ){
            if ( all / i >= i  ){
                n = i ; 
                m = all / n ;
             }
            else {
                break ; 
            }
        }
    }
    vector<vector<int> > out(m, vector<int>(n));
    i = 0 ; 
    while ( k < all ){
        for (  ; j < n ; j++ ){
            if ( out[i][j] == 0 ){
                out[i][j] = num[k++] ;
            } 
            else {
                break ; 
            }
        }   
        i++ ; 
        j-- ;
        for (    ; i < m ; i++ ){
            if ( out[i][j] == 0 ){
                out[i][j] = num[k++] ;
            }
            else {
                break ; 
            }
        }
        i--;
        j-- ;
        for ( ; j >= 0 ; j--){
            if ( out[i][j] == 0 ){
                out[i][j] = num[k++] ;
            }
            else {
                break ;
            }
        }
        j++ ;
        i-- ; 
        for ( ; i >= 0 ; i-- ){
            if ( out[i][j] == 0 ){
                out[i][j] = num[k++] ;
            }
            else {
                break ; 
            }
        }
        i++ ;
        j++ ; 
    }
    for ( i = 0 ; i < m ; i++) {
        for ( j = 0 ; j < n ;  j++) {
            printf("%d",out[i][j]) ;
            if ( j != n - 1){
                printf(" ") ;
            }
        }
        printf("\n") ; 
    }
    return 0 ; 
}
