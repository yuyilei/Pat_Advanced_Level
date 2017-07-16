#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std ; 
int cmp( int a , int b){
    return a > b ; 
}
int main() {
    int n , m , i , j ,  out = 0  ; 
    vector <int> a ; 
    vector <int> b ; 
    scanf("%d",&n) ; 
    a.resize(n) ; 
    for ( i = 0 ; i < n ; i++ ){
        scanf("%d",&a[i]) ;    
    }
    scanf("%d",&m) ; 
    b.resize(m) ; 
    for ( i = 0 ; i < m ; i++ ){
        scanf("%d",&b[i]) ; 
    }
    sort(a.begin(),a.end(),cmp) ; 
    sort(b.begin(),b.end(),cmp) ;
    for ( i = 0 ; a[i] > 0 && b[i] > 0 ; i++ , j++ ){
        out += ( a[i] * b[i] ) ; 
    }
    for ( i = n -1 , j = m - 1 ; a[i] < 0 && b[j] < 0 ; i-- , j-- ){
        out += ( a[i] * b[j] ) ; 
    }
    printf("%d",out) ;
    return 0 ; 
}
