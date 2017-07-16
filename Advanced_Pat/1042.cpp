#include<iostream>
using namespace std ; 
int main() {
    int a[55] , b[55] , i , j , num , res[55] , temp ; 
    char out[5] = {'S' , 'H' , 'C' , 'D' , 'J' } ; 
    cin >> num ; 
    for ( i = 1; i < 55 ; i++ ){
        cin >> a[i] ; 
        b[i] = i ; 
    }
    for ( i = 0 ; i < num ; i++ ){
        for ( j = 1 ; j < 55 ; j++ )
            res[a[j]] = b[j] ;
        for ( j = 1 ; j < 55 ; j++ )
            b[j] = res[j] ; 
    }
    for ( i = 1 ; i < 55 ; i++ ){
        temp = ( res[i] - 1 ) / 13 ; 
        cout << out[temp] << ( res[i] - temp * 13 ) ; 
        if ( i != 54 ) cout << " " ; 
    }
    return 0 ; 
}
