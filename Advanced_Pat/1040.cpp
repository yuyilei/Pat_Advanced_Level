#include<iostream>
using namespace std ;
int tell(int a, int b , string in ){
    int i = a , j = b ; 
    while ( a <= b ){
        if ( in[a++] != in[b--])
            return 0 ; 
    }
    return j - i + 1  ;
}
int main() {
    string in ; 
    int i , j ,  len , max = 0 , t = 0  ; 
    getline(cin,in) ;
    len = in.length() ; 
    for ( i = 0 ; i < len - max ; i ++ ){ 
        for ( j = len - 1 , t = 0 ; j > i + max ; j--){
            if ( in[i] == in[j] ){
                t = tell(i,j,in) ; 
                if ( t != 0 ){
                    max = t ; 
                    break ; 
                }
            }
        } 
    }
    cout <<  ((max==0)?1:max) << endl  ; 
    return 0 ; 
}
