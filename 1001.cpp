#include<iostream>
#include<vector>
using namespace std ; 
int main() {

    long long a , b ;
    cin >> a >> b ;
    long long  res = a + b ; 
    vector<int> out ;
    vector<char> output ;

    if ( res < 0 ){
    
        res = -res ;
        output.push_back('-') ;
    }

    if (res==0) {
    
        cout << '0' ; 
        return 0 ; 
    }

    while (res) {
    
        int c  = res % 10 ;
        out.push_back(c) ;
        res /= 10 ;
    }
    
    int num = ( out.size() + 2 ) / 3 ;
    if ( out.size() % 3 == 0 ){
    
        num -- ; 
    }
    int k = 0 ;
    int flag = 0 ;
    int s = out.size() % 3 ;
    int q = s ;
//    cout << s ;

    for (vector<int>::iterator it = out.end() ; it != out.begin() ; it--, s--  ){
        if ( s == 0)  {
            flag = 1 ;
            if ( q == 0 )
                k = 0 ;
            else 
                k = 3 ;
        }

        if ( k % 3 == 0 && num && k && flag ){
        
            output.push_back(',') ;
            num-- ;
        }
        output.push_back(*(it-1)+'0') ;
        k++ ; 
    }
    
    for (vector<char>::iterator it = output.begin() ; it != output.end() ; it++ ){
    
        cout << *it ;
    }
    return 0 ;
}
