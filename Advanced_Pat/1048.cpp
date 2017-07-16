#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
int cmp(int a , int b ){
    return a < b  ; // 升序
} 
using namespace std ;
int main () {
    int i , num , all ,temp  ;
    map <int,int> money ; 
    map <int,int> had ; 
    vector <int> have ; 
    cin >> num >> all  ;
    for ( i = 0 ; i < num ; i++ ){
        cin >> temp ; 
        if ( temp < all ){
            if ( temp == (all - temp) && money.count(temp) == 1 ) {
                had[temp] = 2 ; 
            } 
            money[temp] = all - temp ; 
            have.push_back(temp) ; 
        }
    }
    sort(have.begin(),have.end(),cmp) ; 
    for ( vector <int> ::iterator it = have.begin() ; it != have.end() ; it++ ){
        temp = all - *it ; 
        if ( money.count(temp) == 1 ) { 
            if ((temp == *it && had.count(temp) == 1) || (temp != *it) ){
                cout << *it << " " << temp ; 
                return 0 ; 
            }
        }
    }
    printf("No Solution") ; 
    return 0 ; 
}
