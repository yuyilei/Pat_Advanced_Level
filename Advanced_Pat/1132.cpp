#include<iostream>
#include<string>
using namespace std ; 
int main() {
    int n, i, k, t, p ;
    string tmp, t1, t2 ;  
    cin >> n ; 
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> tmp ; 
        k = tmp.length()/2;
        t1 = tmp.substr(0,k) ; 
        t2 = tmp.substr(k,2*k) ; 
        t = stoi(t1)*stoi(t2) ; 
        p = stoi(tmp) ; 
        if ( !t || p % t )                // 注意要判断t是不是等于0  
            cout << "No" << endl ; 
        else 
            cout << "Yes" << endl ; 
    }
    return 0 ; 
}