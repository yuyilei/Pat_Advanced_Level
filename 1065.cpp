#include<iostream>
using namespace std ; 
int main() {
    int n , i  ; 
    long long a , b , c , temp ; 
    cin >> n ; 
    for ( i = 0 ; i < n ; i ++ ){
        cin >> a >> b >> c ; 
        temp = a + b ; 
        if ( a > 0 && b > 0 && temp <= 0 ){ //  溢出 ,下同 
            cout << "Case #" << i+1 << ": true" << endl ;
        }
        else if ( a < 0 && b < 0 && temp >= 0 ){
            cout << "Case #" << i+1 << ": false" << endl ;
        }
        else if ( temp > c ){
            cout << "Case #" << i+1 << ": true" << endl ;
        }
        else {
            cout << "Case #" << i+1 << ": false" << endl ;
        }
    }
    return 0 ; 
}
