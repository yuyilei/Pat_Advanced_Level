#include<iostream>
#include<vector>
using namespace std ; 
int tell_insert(vector<int> a , vector<int> b) {
    int len = a.size() , i  , j  ; 
    for ( i = len -1 ; i >= 0 ; i-- ) {
        if ( a[i] != b[i] ){
            break ; 
        }
    }
    for ( j = 0 ; j < len ; j++ ){
        if ( b[j] > b[j+1]) {
            break ; 
        }
    }
    return (j>=i)?j:0 ; 
}
int equal(vector<int> &a, vector<int> b) {
    int len = b.size() , i ; 
    for ( i = 0 ; i < len ; i++ ){
        if ( a[i] != b[i] )
            return 0 ; 
    }
    return 1 ;
}
void merge( vector<int> &c , int left , int middle , int right , int len) {
    int k = left , j = middle+1 , i  ;
    vector<int> temp(len) ; 
    for ( i = 0 ; i < len ; i++){
        temp[i] = c[i] ; 
    }
    for ( i = left ; i <= right ; i++ ){
        if ( k > middle ) {
            c[i] = temp[j++] ; 
        }
        else if ( j > right ) {
            c[i] = temp[k++] ;
        }
        else if ( temp[k] > temp[j]) {
            c[i] = temp[j++] ;
        }
        else {
            c[i] = temp[k++] ; 
        }
    } 
}
void merge_sort(vector<int> &c , vector<int> b) {
    int len = b.size() , n , i , right ,flag = 0  ;
    for ( n = 1 ; n < len ; n*=2 ){
        for ( i = 0 ; i < len - n ; i += 2*n ){
            right  = (i+2*n)>(len) ? len-1 : i+2*n-1 ;
            merge(c,i,i+n-1,right,len) ;
        }
        if ( flag == 1 ) {
            return ;
        }
        else if ( equal(c,b) == 1 ) {
            flag = 1 ;
        }
    }
}
int main() {
    int n , i , k , j ; 
    cin >> n ; 
    vector<int> a(n) ; 
    vector<int> b(n) ;
    for ( i = 0 ; i < n ; i++ ){
        cin >> a[i] ;
    }
    for ( i = 0 ; i < n ; i++ ){
        cin >> b[i] ;
    }
    int temp = tell_insert(a,b) , t ; 
    if ( temp != 0 ){
        for ( i = 0 ; i <= temp ; i++ ){
            for ( j = 0 ; j + i <= temp  ; j++ ){
                if (b[j] > b[j+1]){
                    int tp = b[j] ;
                    b[j] = b[j+1] ;
                    b[j+1] = tp ; 
                }
            }
        }
        cout << "Insertion Sort" << endl ; 
        cout << b[0]  ; 
        for ( i = 1 ; i < n ; i++ ){
            cout << " " << b[i]  ; 
        }
        return 0 ; 
    }
    merge_sort(a,b) ; 
    cout << "Merge Sort" << endl ; 
    cout << a[0] ;
    for ( i = 1 ; i < n ; i++) {
        cout << " " << a[i] ; 
    }
    return 0  ; 
}
