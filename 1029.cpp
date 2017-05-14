#include<vector>
#include<cstdio>
using namespace std ; 
int main() {
    long n , m , i , media , q = 0 , p = 0 , now = 0 ;
    scanf("%ld",&n) ; 
    vector<long> a (n) ; 
    for ( i = 0 ; i < n ; i++ ){
        scanf("%ld",&a[i]) ; 
    }
    scanf("%ld",&m) ; 
    vector<long> b (m) ; 
    for ( i = 0 ; i < m ; i++ ){
        scanf("%ld",&b[i]) ; 
    }
    media = ((n+m)-1)/2  ; 
    for ( i = 0 ; i <= media && p < n && q < m ; i++ ){
            if ( a[p] < b[q] ){
                now = a[p++] ;    
            }
            else {
                now = b[q++] ; 
            }
        }
        while ( p < n && i <= media ){
            i++ ; 
            now = a[p++] ; 
        }
        while ( q < m && i <= media ){
            i++ ; 
            now = b[q++] ; 
        }
    printf("%ld\n",now) ; 
}
