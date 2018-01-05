#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
vector<int> in ;
int res[10002] ; 
int num ; 
int now = 0 ; 

void get_level(int root ) {
    if ( root > num ) 
        return ;
    get_level(2*root) ;
    res[root] = in[now++] ;
    get_level(2*root+1) ;
}

int main() {
    int i; 
    cin >> num ;
    in.resize(num) ;
    for ( i = 0 ; i < num ; i++ ) 
        cin >> in[i] ;
    sort(in.begin(),in.end()) ; 
    get_level(1) ; 
    cout << res[1] ; 
    for ( i = 2 ; i <= num ; i++ ) 
        cout << " " <<  res[i] ;  
    cout << endl ; 
    return 0 ; 
}