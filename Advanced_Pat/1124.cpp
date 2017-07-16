#include<iostream>
#include<set>
#include<vector>
using namespace std ;
int main() {
    vector<string> in ;
    int n , m , s , i , flag = 0 ; 
    set<string> had ; 
    cin >> n >> m >> s ;
    in.resize(n) ;
    for ( i = 0 ; i < n ; i++ ){
        cin >> in[i] ; 
    }
    for ( i = s - 1 ; i < n ; ){
        if ( had.count(in[i]) == 0 ){
            cout << in[i] << endl; 
            flag = 1 ;
            had.insert(in[i]) ;
            i += m  ; 
        }
        else {
            i++ ; 
        }
    } 
    if ( flag == 0 ){
        cout << "Keep going..." << endl ;
    }
    return 0 ; 
}
