#include<iostream>
#include<string>
#include<algorithm>
using namespace std ;
string change( string a ){
    int flag = 0 ;
    string res = a ;
    reverse(a.begin(),a.end()) ; 
    for ( int i = 0 ; i < a.length() ; i++ ){
        res[i] = res[i] + a[i] + flag -'0' ; 
        flag = 0 ;
        if ( res[i] > '9' ){
            flag = 1 ;
            res[i] -= 10 ;
        }
    }
    if (flag==1){
        res += '1' ;
    }
    reverse(res.begin(),res.end()) ; 
    return res ; 
}
int main() {
    string a , t ; 
    int k , i ;
    cin >> a >> k ;
    for ( i = 0 ; i < k ; i++ ){
        t = a ; 
        reverse(t.begin(),t.end()) ; 
        if ( t == a ){
            cout << a << endl << i ; 
            return 0 ; 
        }
        a = change(a) ; 
    }
    cout << a <<endl << k ; 
    return 0 ; 
}
