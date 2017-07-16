#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std ; 
int cmp(int a , int b ){
    return a <  b ; 
}
int main () {
    int n , p , i , j ,z , max , h ,  out = 0 , temp , k = 0 , flag = 0  ; 
    cin >> n >> p ; 
    vector<int> in(n) ;
    map<int,int> index ; 
    vector<int> help(n) ; 
    for ( i = 0 ; i < n ; i++) {
        scanf("%d",&in[i]) ; 
    }
    sort(in.begin(),in.end(),cmp) ;
    for ( i = 0 ; i < n ; i++ ){
        index[in[i]] = i ; 
    } 
    for ( i = n - 1 ; ; i--){
        if ( in[i] <= in[0]*p ){
            h = i ; 
            break ; 
        }
    }
    for ( i = 0 ; i < n - out ; i++ ){
        max = in[i] * p ; 
        if   ( max >= in[n-1] ){
            temp = n - 1 - i  ; 
            help[i] = n - 1  ; 
        } 
        z = ( i!= 0 )? help[i-1]:h;
        while ( max >= in[z] && z < n - 1 && max < in[n-1] ){
            flag = 1 ;
            z++  ; 
        }
        if (flag ){
            help[i] = z - 1  ;     
            flag = 0 ; 
            temp = z - 1  - i  ; 
        }
        temp++ ; 
        out = temp > out ? temp : out ;
    }
    cout << out ;  
    return 0 ; 
}
