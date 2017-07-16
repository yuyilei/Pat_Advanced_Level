#include<string>
#include<iostream>
using namespace std ; 
int main() {
    int n , i , j , k , max = 0 , out = 0 ; 
    string first , input ; 
    cin >> n ; 
    getchar() ; // getline 之前要消去前一行的\n 
    getline(cin,first) ;
    for ( i = 0 ; i < n - 1 ; i ++ ){
        getline(cin,input) ; 
        out = 0 ; 
        for ( j = first.length() - 1 , k = input.length() - 1 ; j >= 0 && k >= 0 ; j-- , k--  ) {
            if (first[j] == input[k] ){
                out++ ; 
            }
            else {
                break ; 
            }
        }
        if ( out == 0 ){
            cout << "nai"; 
            return 0 ; 
        }
        if ( i == 0 ){
            max = out ; 
        }
        max = (max>out) ? out : max ; 
    }
    for ( i = first.length() - max  ; i < first.length() ;  i++) {
        cout << first[i] ;
    }
    return 0 ; 
}

