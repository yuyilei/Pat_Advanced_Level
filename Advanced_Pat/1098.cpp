#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

// 值得注意的是，堆排序时记得下标要从1开始！！！！
int n ; 
vector<int> before, after ; 

void print_it() {
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( i != 1 ) 
            cout << " " ; 
        cout << after[i] ; 
    }
    cout << endl ; 
}

bool tell_insert() {
    int i, now ; 
    for ( i = 1 ; i + 2 < n  && after[i] <= after[i+1] ; ) 
        i++ ;   
    now = i + 1  ; 
    for ( i = now ; i < n ; i++ ) {
        if ( before[i] != after[i] ) {
            return false ; 
        }
    }
    cout << "Insertion Sort" << endl ; 
    if ( now + 1 <= n )
        sort(after.begin()+1,after.begin()+now+1) ; 
    print_it() ; 
    return true ; 
}

void head_adjust( int e) {
    int i = 1 ;
    for ( ; 2*i <= e ; ) {
        int ch = 2*i ; 
        if ( ch < e && after[ch] < after[ch+1] ) 
            ch++ ; 
        if ( after[ch] < after[i] ) 
            break ; 
        swap(after[ch],after[i]) ;  
        i = ch ; 
    } 
}

void heap_sort() {
    int i, now ; 
    for ( i = n-1 ; i >= 1 && after[i] >= after[1] && after[i] <= after[i+1] ; )
        i-- ; 
    now = i ; 
    swap(after[1],after[now]) ; 
    head_adjust(now-1) ; 
    cout << "Heap Sort" << endl ; 
    print_it() ; 
}

int main() {
    int i ; 
    cin >> n ; 
    before.resize(n+1) ;
    after.resize(n+1) ; 
    for ( i = 0 ; i < n ; i++ ) 
        cin >> before[i+1] ; 
    for ( i = 0 ; i < n ; i++ ) 
        cin >> after[i+1] ; 
    if ( tell_insert() ) 
        return 0 ; 
    heap_sort() ; 
    return 0 ; 
}