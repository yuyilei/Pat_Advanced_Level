#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std ;
struct node{ 
    int num ; 
    float  price ;
} ;
int cmp ( struct node a , struct node b ) {
    return a.price > b.price ;
}
int main () {
    int n , all , i  ;
    float res = 0 ,b  ; 
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
        if ( all > p[i].num  ) {
            res += ( p[i].num *  p[i].price ) ;
            all -= p[i].num ; 
        } 
        else  {
            res += ( p[i].price * all ) ; 
            all = 0 ; 
        }
        i++ ; 
    }
    printf("%.2f",res) ;
    return 0 ; 
}
