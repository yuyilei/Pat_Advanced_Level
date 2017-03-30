#include<iostream>
#include<string>
using namespace std;
int main() {


    int a , b ;
    cin >> a >> b ;
    string s = to_string( a+b ) ; // 坑爹啊,c++11 才支持to_string() ,每次编译都要加上 -std=c++11
    int len = s.length() ;
    int n = s.length() % 3 ;
    for ( int i = 0 ; i < len ; i++ ){
    
        cout << s[i] ;
        if (s[i] == '-') continue ; // 负号不算数字,下标不加 
        if ((i+1) % 3 == n && i != len-1 ) 
            cout << "," ;
    }
    return 0 ; 
}
