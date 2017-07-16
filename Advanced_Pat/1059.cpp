#include<iostream>
#include<vector>
#include<math.h>
using namespace std ; 
int tell(long n ){
    int tmp = sqrt(n) + 1 , i ; 
    for ( i = 3 ; i <= tmp ; i += 2 ){
        if ( n % i == 0){
            return 0 ; 
        }
    }
    return 1 ; 
}
int main() {
    long n , all , i , j , temp , max ; 
    cin >> n ; 
    if ( n == 1 ){ // n是1时直接输出 
        cout << "1=1" << endl ; 
        return 0 ; 
    }
    all = sqrt(n) + 2 ; // +2 ,否则n 是 3时不满足
    vector<long> res (all+2,0) ; 
    for ( i = 2 ; i <= all ; i += 2  ){
        if ( n % i == 0 && tell(i) ){
            max = i ; 
            temp = n ; 
            while ( temp % i == 0 ){
                temp = temp / i ; 
                res[i]++ ; 
            }
        }
        if ( i == 2 ){
            i-- ; 
        }
    }
    cout << n << "=" ; 
    for ( i = 0 ; i <= all ; i++ ){
        if ( res[i] != 0 ){
            if ( res[i] != 1 ){
                cout << i << "^" << res[i] ; 
            }
            else { 
                cout << i ;    
            }
            if ( i != max ){
                cout << "*" ; 
            }
        } 
    }
    return 0 ; 
}
