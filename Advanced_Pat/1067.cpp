#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std ; 
int find_one(vector<int> a ,int  n , int key  ){
    for ( int i = 0 ; i < n ; i++ ){
        if ( a[i] == key ){
            return i ; 
        }
    }
}
int find_another(vector<int> a , int n ){
    for ( int i = 1 ; i < n ; i++ ){
        if ( a[i] != i ) {
            return i ; 
        }
    }
}
void swap(vector<int> a  , int tmp1 , int tmp2 ){
    int temp = a[tmp1] ; 
    a[tmp1] = a[tmp2] ; 
    a[tmp2] = temp ; 
}
int main() {
    int n , i ,j , temp = -1 , k , s ,  count = 0 , t = 0 ; 
    scanf("%d",&n) ; 
    vector<int> a (n) ; 
    for ( i = 0 ; i < n ; i++ ){
        scanf("%d",&a[i]) ;
        if ( a[i] != i ){
            temp ++ ; 
        }
    }
    while ( t <= temp ) {
        k = find_one(a,n,0) ; 
        if  ( k == 0 ){
            s = find_another(a,n) ; 
            swap(a,k,s) ; 
            count ++ ; 
        } 
        else {
            s = find_one(a,n,k) ; 
            swap(a,k,s) ; 
            t++ ; 
        }
    }
    printf("%d\n",count+temp) ; 
    return 0 ; 
}
