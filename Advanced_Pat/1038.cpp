#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std ;
int cmp (string a , string b ) { return a + b < b + a ; }
int main() {
    int num , i , j = 0 , flag = 0 ;
    cin >> num ;
    string *p = new string [num] ;
    for ( i = 0 ; i < num ; i++ ) { cin >> p[i] ; }
    sort(p,p+num,cmp) ;
    for ( i = 1 ; i < num ; i++ ) { p[0] += p[i] ; }
    for ( i = 0 ; i < p[0].size() ; i++ ) {
        if ( p[0][i] != '0' || flag == 1 ) {
            cout << p[0][i] ;
            flag = 1 ;
        }
    }
    if ( flag == 0 ) { cout << "0" << endl ; }
    return 0 ;
}
