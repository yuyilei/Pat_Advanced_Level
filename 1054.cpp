#include<cstdio>
#include<iostream>
#include<map>
using namespace std ; 
int main() {
    long m , n , i , j  , temp , max = 0 , out ;
    cin >> m >> n ;
    map<long,long> a ; 
    for ( i = 0 ; i < n ; i++ ){
        for ( j = 0 ; j < m ; j++) {
            scanf("%ld",&temp) ; // 用cin会超时！！！！！
            if (a.count(temp) == 0 ){
                a[temp] = 1 ;
            }
            else {
                a[temp]++ ; 
            }
        }
    }
    for ( map <long,long> ::iterator it = a.begin() ; it != a.end() ; it++ ){
        int t = it->second ;  
        if ( t > max ){
            max = t ;
            out = it->first ;
        }
    }
    printf("%ld",out) ; 
    return 0 ;
}
