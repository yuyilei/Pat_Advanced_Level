#include<iostream>
#include<algorithm>
#include<deque>
using namespace std ;
struct node {
    string name ;
    int height ;
} ;
int cmp ( struct node a , struct node b ){
    if ( a.height != b.height) {
        return a.height >  b.height ;
    }
    else 
        return a.name < b.name ;
}
int main() {
    int n , i,  m , each , last ,num  ;
    cin >> n >> m ; 
    each = n / m ;
    last = each + n % m ;
    struct node *p = new struct node [n] ;
    for ( i = 0 ; i < n ; i++) {
        cin >> p[i].name >> p[i].height ;
    }
    sort(p,p+n,cmp) ;
    i = 0 ; 
    int all = m ;  
    while ( all > 0 ) {
        if ( all == m ) {
            num = last ;       
        }
        else  {
            num = each ;
        }
        deque<string> st ; 
        for ( int t = 0 ;  t < num ; t ++) {
            if ( t % 2 == 1 ){
                st.push_front(p[i++].name) ;
            }
            else {
                st.push_back(p[i++].name) ;
            }
        }
        cout << st.front() ;
        st.pop_front() ;
        while ( !st.empty() ){
            cout << " " << st.front() ; 
            st.pop_front() ;
        }
        cout << endl ; 
        all--; 
    }
    return  0 ; 
}
