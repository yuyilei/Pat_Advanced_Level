#include<cstdio>
#include<algorithm>
using namespace std ; 

int main() {
    int n, i, t, index = 0 ; 
    scanf("%d",&n) ; 
    int *p = new int [n+1] ;
    for ( i = 0 ; i < n ; i++ ) {
        scanf("%d",&t) ; 
        if ( t > 0 ) 
            p[index++] = t ; 
    }
    sort(p,p+index) ;  
    if ( p[0] != 1 ) {
        printf("1\n") ; 
        return 0 ; 
    } 
    for ( i = 1 ; i < index ; i++ ) {
        if ( p[i] > p[i-1] + 1 ) 
            break ; 
    }
    printf("%d\n",p[i-1]+1) ; 
    return 0 ; 
}