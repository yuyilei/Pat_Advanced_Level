#include<iostream>
#include<math.h>
using namespace std ; 
int isPrime(int a ){
    if ( a == 1 ) { return 0 ; } // 翻转了之后有可能会得到1,所以在这要加个1的判断  
    for ( int i = 2 ; i <= sqrt(a) ; i++ ) // 是++ ,不要和+2搞混了！！
        if ( a % i == 0 )
            return 0 ; 
    return 1 ; 
}
int reverse( int a , int b ){
    int res ; 
    for ( res = 0 ; a > 0 ; a /= b  )
        res = res*b + a % b ; 
    return res ;  
}
void output(int a , int b ){
    int res = reverse(a,b) ; 
    if ( isPrime(res) == 1 && isPrime(a) == 1 )
        cout << "Yes" << endl ; 
    else  cout << "No" << endl ;  
}
int main() {
   int a , b ; 
   while(1) {
        cin >> a ; 
        if ( a < 0 ) { return 0 ; } 
        cin >> b ; 
        output(a,b) ; 
   }
   return 0 ; 
}
