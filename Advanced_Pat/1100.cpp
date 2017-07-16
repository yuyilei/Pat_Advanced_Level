#include<iostream>
#include<string>
using namespace std ;
string a[14] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec", "tam"};
string b[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
void fun1( string s ){
    if ( s[0] == '0' && s.length() == 1 ) {
        cout << "tret"  << endl ;
        return ; 
    }
    else { 
        int sum = 0 ;
        for ( int i = 0 ; i < s.length() ; i++ ) {
            sum = (sum * 10 + (s[i]-'0')) ;
        }
        cout << b[sum/13] ;
        int k = sum % 13 ;
        if ( sum > 13  && k != 0 ){ 
            cout << " " << a[k] << endl ;
        }
        else {
            if ( k != 0 )  {
                cout << a[k] ;
            } 
            cout << endl ;
        }
    }
}
void  fun2( string s) {
    int len = s.length() ;
    int sum = 0 ; 
    if ( len == 4 ){
        cout << "0" << endl ; 
    }
    if ( len == 3){
        for ( int i = 0 ; i < 14 ; i++ ) {
            if ( s[0] == a[i][0] && s[1] == a[i][1] && s[2] == a[i][2]) {
                cout << i << endl ; 
                return ;
            }
            if  ( s[0] == b[i][0] && s[1] == b[i][1] && s[2] == b[i][2] ) {
                cout << i*13 << endl ; 
                return ; 
            }
        }
    }
    else  {
        for ( int i = 1 ; i < 13 ; i++) {
            if  ( s[0] == b[i][0] && s[1] == b[i][1] && s[2] == b[i][2]  ){
                sum +=( 13* i ) ;
                break ;
            }
        }
        for ( int  i = 1 ; i < 13 ; i++ ){
            if ( s[4] == a[i][0] && s[5] == a[i][1] && s[6] == a[i][2] ) {
                sum +=  i  ;
                cout << sum << endl ; 
                return  ; 
            }
        }
    }
}
int main() {
    int n , i ; 
    string s  ; 
    cin >> n ; 
    getchar() ; 
    for ( i = 0 ; i < n ; i++) {
        getline(cin,s) ; 
        if ( s[0] >='0' && s[0] <= '9' ) {
            fun1(s) ;
        }
        else {
            fun2(s) ;
        }
    }
    return 0 ; 
}
