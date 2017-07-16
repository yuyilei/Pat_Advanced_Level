#include<iostream>
#include<stack>
#include<vector>
using namespace std ; 
int main(){
    int max , len , n , i , j , t = 1 , s , flag = 0 , maxn ; 
    cin >> max >> len >> n ; 
    vector <int> in (len); 
    stack <int> temp ;  
    for ( i = 0 ; i < n ; i++ ){
        temp.empty() ;
        for ( j = 0 ; j < len ; j ++ ){
            cin >> in[j] ; 
        }
        maxn = max ; 
        cout << endl ; 
        for ( t = 1 ,  s = 0 , flag = 0  ;   ; s++ ){
            if ( in[s] > maxn ){
                cout  << in[s] << " " << maxn << endl ;
                flag = 1 ; 
                break ; 
            }
            while ( temp.empty() ||(temp.size() < maxn && !temp.empty() && temp.top() != in[s]) ){
               // cout << t << endl ; 
                temp.push(t++) ; 
            }
            if ( temp.top() != in[s] ){
                cout << in[s] << endl ; 
                flag = 1 ; 
                break ; 
            }
            temp.pop() ; 
            maxn++ ; 
        }
        if ( flag == 0 ){
            cout << "YES" << endl ; 
        } 
        else {
            cout << "NO" << endl ;
        }
    }
    return 0 ;
}
