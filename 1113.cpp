#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std ;
int main () {

    int  n ;
    int i ;
    int sum = 0 ;
    int half = 0 ; 
    scanf("%d",&n) ;
    vector<int> v(n) ; // 初始化个数为n,否则段错误
    for ( i = 0 ; i< n ; i++) {
    
        scanf("%d",&v[i]) ;
        sum += v[i] ;
    }

    sort(v.begin(),v.end()) ;

    for ( i = 0 ; i < n/2 ; i++) {
        half += v[i] ;
    }
    printf("%d %d",n%2,sum-2*half) ;
    return 0 ;  
}
