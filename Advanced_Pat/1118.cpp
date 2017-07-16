#include<iostream>
#include<vector>
using namespace std ;
vector <int> all(10010,0) ;
int main() {
    int k , n , i , j , t ,flag = 0, num = 0 , m , now = 0  , tp , q , max = 0 , b1 , b2  ;
    cin >> k ;
    vector <int> temp (10) ;
    for (  i = 0 ; i < k ; i ++ ){
        cin >> m  ;
        temp.resize(m) ; 
        for ( j = 0 ; j < m ; j++ ) {
            cin >> temp[j] ; 
            max = ( max < temp[j]) ? temp[j] : max ; 
            tp = all[temp[j]] ;
            if ( tp != 0 ) {
                flag = tp ;            
            }
        }
        if ( flag == 0 ){
            q = now + 1 ; 
            now++ ; 
        }
        else {
            q = flag  ;  
        }
        for ( j = 0 ; j < m ; j++ ) {
            all[temp[j]] = q ; 
        }
    }
    cin >> n ; 
    vector <string> out(n) ; 
    for (  i = 0 ; i < n ; i++ ){
        cin >> b1 >> b2 ; 
        if ( all[b1] == all[b2] ){
            out[i] = "Yes" ; 
        }
        else {
            out[i] = "No" ; 
        }
    }
    cout << now << " " << max << endl ;
    for ( i = 0 ; i < n ; i++ ){
        cout << out[i] << endl ; 
    }
    return 0 ; 
}
