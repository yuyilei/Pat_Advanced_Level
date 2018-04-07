#include<cstdio>
using namespace std ;

int hashing[10001] = {0} ;
int msize, m, n ;

bool isprime(int value ) {
    if ( value <= 1 ) 
        return false ;
    for ( int i = 2 ; i*i <= value ; i++ ) 
        if ( value % i == 0 ) 
            return false ; 
    return true ; 
}

/*
插入时，只用检查到 (size-1)^2就行了
*/
void Insert(int value) {
    for ( int i = 0 ; i < msize ; i++ ) {
        int v = (i*i + value) % msize ; 
        if ( hashing[v] == 0 ) {
            hashing[v] = value ; 
            return ; 
        } 
    } 
    printf("%d cannot be inserted.\n",value) ; 
} 

/*
查找时，查找不到的条件是hashing[v] = 0 或查找次数超过msize 
所以查找时检查到 size^2 
*/
int Search(int value) {
    int count = 0 ; 
    for ( int i = 0 ; i <= msize ; i++ ) {
        count++ ; 
        int v = (i*i + value) % msize ; 
        if ( hashing[v] == value || hashing[v] == 0 ) 
            return count ; 
    } 
    return count ; 
}
int main() {
    int i, j, t, res = 0 ; 
    scanf("%d %d %d",&msize,&n,&m) ; 
    while ( !isprime(msize) ) 
        msize++ ; 
    for ( i = 0 ; i < n ; i++ ) {
        scanf("%d",&t) ; 
        Insert(t) ; 
    }
    for ( i = 0 ; i < m ; i++ ) {
        scanf("%d",&t) ; 
        res += Search(t) ; 
    }
    printf("%.1f\n",(float)res/m) ; 
    return 0 ; 
}