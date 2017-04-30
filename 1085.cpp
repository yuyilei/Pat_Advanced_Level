#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std ; 
int cmp(int a , int b ){
    return a <  b ; 
}
int help[1000000000] = {0} ; 
int main () {
    int n , p , i , j , max , out = 0 , temp ; 
    cin >> n >> p ; 
    vector<int> in(n) ;
    map<int,int> index ; 
    set<int> had ; 
    for ( i = 0 ; i < n ; i++) {
        cin >> in[i] ; 
        had.insert(in[i]) ; 
    }
    sort(in.begin(),in.end(),cmp) ;
    for ( i = 0 , j = 0 ; i < in[n-1]; i++ ){
        if ( i == in[j] ){
            help[i] = 0 ; 
            j++ ; 
        }
        else {
            help[i] = in[j-1] ; 
        }
    }
    for ( i = 0 ; i < in[n-1] ; i++) {
        cout << help[i] << endl ; 
    }
    for ( i = 0 ; i < n ; i++ ){
        index[in[i]] = i ; 
    } 
    for ( i = 0 ; i < n - out ; i++ ){
        max = in[i] * p ; 
        while ( max < in[n-1] ){
            if ( help[max] == 0 ){
                temp = index[max] ; 
                break ; 
            }
            else { 
                temp = index[help[max]] ; 
                break ; 
            }
        }
        temp = temp  - i + 1  ; 
        out = temp > out ? temp : out ;
    }
    cout << out ;  
    return 0 ; 
}
