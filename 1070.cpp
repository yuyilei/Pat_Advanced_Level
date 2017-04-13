#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std ;
struct node{ 
    float num ; //  月饼数量也应该是浮点型！！
    float  price ;
} ;
int cmp ( struct node a , struct node b ) {
    return a.price > b.price ;
}
int main () {
    int n , i  ;
    float res = 0 , b , all  ; 
    cin >> n >> all ;
    struct node *p = new struct node [n] ;
    for ( i = 0 ; i < n ; i++) {
        cin >> p[i].num ; 
    }
    for ( i = 0 ; i < n ; i++ ){
        cin >> b ; 
        p[i].price = b / p[i].num ; 
    }
    sort(p,p+n,cmp) ;
    i = 0 ; 
    while ( all  > 0 ) {
        int temp = ( all > p[i].num ) ? p[i].num : all ;
        res += temp*p[i++].price ;
        all -= temp ;
    }
    printf("%.2f",res) ;
    return 0 ; 
}
