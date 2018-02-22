#include<iostream>
using namespace std ;

int marked[10006] = {0} ; 
int n, T ; 

// 哈希表采用二次探测。。。单词不认识。。。。只取正数 +1^2, +2^2, +3^2 ...... 

bool isprime(int x) {
    if ( x == 1 ) 
        return false ; 
    for ( int i = 2 ; i * i <= x ; i++ ) 
        if ( x % i == 0 ) 
            return false ; 
    return true ; 
}

int main() {
    int i, now, j, k ; 
    cin >> T >> n ; 
    while ( !isprime(T) ) 
        T++ ; 
    for ( i = 0 ; i < n ; i++ ) {
        cin >> now ; 
        for ( j = 0 ; j < T ; j++ ) {
            int k = ( now + j*j ) % T ; 
            if ( marked[k] == 0 ) {
                cout << k << (( i == n-1 ) ? "\n" : " ") ; 
                marked[k] = 1 ; 
                break ; 
            }
        }
        if ( j >= T ) 
            cout << "-" << (( i == n-1 ) ? "\n" : " ") ; 
    }  
    return 0 ;  
}