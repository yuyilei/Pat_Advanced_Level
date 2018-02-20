#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std ; 

long gcd(long a, long b) {
    while ( b != 0 ) {
        long tmp = a % b ; 
        a = b ; 
        b = tmp ; 
    }
    return (a > 0 ) ? a : -a ; 
}

string num2str(long x, int y) {
    long most = gcd(x,y) ; 
    int flag = 0, z ; 
    string res = "" ; 
    x /= most ; 
    y /= most ; 
    if ( x < 0 ) {
        x = -x ;  
        flag = 1 ; 
        res += "(-" ; 
    }
    if ( x % y == 0 ) {
        res += to_string(x/y) ; 
        if ( flag ) 
            res += ")" ; 
    }
    else {
        if ( x / y != 0 ) {
            res += to_string(x/y) ; 
            res += " " ; 
            x %= y ; 
        }
        res += to_string(x) ; 
        res += "/" ; 
        res += to_string(y) ; 
        if ( flag ) 
            res += ")" ; 
    }
    return res ; 
}

int main() {
    long a1, b1, a2, b2 ; 
    scanf("%ld/%ld %ld/%ld",&a1,&b1,&a2,&b2) ; 
    string c1 = num2str(a1,b1) ; 
    string c2 = num2str(a2,b2) ; 
    cout << c1 << " + " << c2 << " = " << num2str(a1*b2+a2*b1,b2*b1) << endl ;  
    cout << c1 << " - " << c2 << " = " << num2str(a1*b2-a2*b1,b2*b1) << endl ; 
    cout << c1 << " * " << c2 << " = " << num2str(a1*a2,b1*b2) << endl ; 
    cout << c1 << " / " << c2 << " = " ; 
    if ( a2 == 0 ) {
        cout << "Inf" << endl ;  
        return 0 ; 
    }
    long t1 = a1*b2, t2 = b1*a2 ; 
    if ( t2 < 0 ) {
        t1 = -t1 ; 
        t2 = -t2 ; 
    }
    cout << num2str(t1,t2) << endl ; 
    return 0 ;
}