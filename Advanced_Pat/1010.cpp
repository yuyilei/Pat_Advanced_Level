#include<cstdio>
#include<cstring>
using namespace std ; 

long long n1, n2, radix, low, high ; 
int n[12] = {0}, len = 0 ; 

/*
low = max(n[12]) + 1 
high = max(low,n1) 
在low和high中进行二分查找，当n2 < 0 说明小于0 ，要将 mid-- 
*/

int ctoi(char x) {
    if ( x >= '0' && x <= '9' ) 
        return x - '0' ; 
    return x - 'a' + 10 ; 
}

void getn1(char a[]) {
    long long tmp = 1 ; 
    for ( int i = strlen(a) - 1 ; i >=0 ; i-- ) {
        n1 += ctoi(a[i])*tmp ; 
        tmp *= radix ;            
    }
}

void getn2(char a[]) {
    long long maxx = 0 ;
    for ( int i = 0 ; i < strlen(a) ; i++ ) {
        n[i] = ctoi(a[i]) ; 
        maxx = (maxx > n[i]) ? maxx : n[i] ; 
    }
    len = strlen(a) ; 
    low = maxx + 1 ; 
    high = ( n1 > low ) ? n1 : low ; 
}

int main() {
    int tag, i, j ; 
    char a1[12], a2[12] ; 
    scanf("%s %s %d %lld",a1,a2,&tag,&radix) ;  
    if ( tag == 1 ) {
        getn1(a1) ; 
        getn2(a2) ; 
    }
    else {
        getn1(a2) ; 
        getn2(a1) ; 
    } 
    while ( low <= high ) {
        long long mid = ( low + high) / 2 ; 
        long long tmp = 1 ; 
        n2 = 0 ;
        for ( i = len-1 ; i >=0 ; i-- ) {
            n2 += tmp*n[i] ; 
            tmp *= mid ; 
        }
        if ( n2 == n1 ) {
            printf("%lld\n",mid) ; 
            return 0 ;
        }
        if ( n2 < 0 ) 
            high-- ; 
        else if ( n2 > n1 ) 
            high = mid - 1 ; 
        else if ( n2 < n1 ) 
            low = mid + 1 ; 
    }
    printf("Impossible\n") ; 
    return 0 ; 
}