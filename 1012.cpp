#include<cstdio>
#include<algorithm>
#include<map>
using namespace std ; 
struct st {
    int c , m , e , a , r , flag , name ;  
    char out ; 
} ; 
bool cmpC( struct st a , struct st b ) { return a.c > b.c ; }
bool cmpM( struct st a , struct st b ) { return a.m > b.m ; }
bool cmpE( struct st a , struct st b ) { return a.e > b.e ; }
bool cmpA( struct st a , struct st b ) { return a.a > b.a ; }
int main() {
    map < int , int > had ; 
    int n , s , i , temp , index , j , k ; 
    scanf("%d %d",&n,&s) ; 
    struct st *p = new struct st [n] ; 
    struct st *c = new struct st [n] ; 
    struct st *m = new struct st [n] ; 
    struct st *e = new struct st [n] ;
    struct st *a = new struct st [n] ;
    for ( i = 0 ; i < n ; i++ ){
        scanf("%d %d %d %d",&p[i].name ,&p[i].c ,&p[i].m ,&p[i].e) ; 
        p[i].a = (p[i].c + p[i].m + p[i].e ) / 3.0 + 0.5  ; 
        had[p[i].name] = i ; 
        a[i] = p[i] ; 
        c[i] = p[i] ; 
        m[i] = p[i] ; 
        e[i] = p[i] ; 
    }
    sort(a, a+n , cmpA ) ; 
    sort(c, c+n , cmpC ) ; 
    sort(m, m+n , cmpM ) ; 
    sort(e, e+n , cmpE ) ; 
    for ( i = 0 ; i < s ; i++ ){
        scanf("%d",&temp) ; 
        if ( had.count(temp) == 0 ) {
            printf("N/A\n") ; 
            continue ; 
        }
        for ( j = 0 ; j < n  ; j++ ){
            if ( a[j].name == temp ) {
                for ( k = j ; k >= 0 ; k-- ){
                    if ( a[k].a != a[j].a ) {
                        break ; 
                    }
                }
                printf("%d A\n",k+2) ; 
                break ; 
            }
            else if ( c[j].name == temp ){
                for ( k = j ; k >= 0 ; k-- ){
                    if ( c[k].c != c[j].c ) {
                        break ; 
                    }
                }
                printf("%d C\n",k+2) ; 
                break ; 
            }
            else if ( m[j].name == temp ) {
                for ( k = j ; k >= 0 ; k-- ){
                    if ( m[k].m != m[j].m ) {
                        break ; 
                    }
                }
                printf("%d M\n",k+2) ; 
                break ;
            }
            else if ( e[j].name == temp ) {
                for ( k = j ; k >= 0 ; k-- ){
                    if ( e[k].e != e[j].e ) {
                        break ; 
                    }
                }
                printf("%d E\n",k+2) ; 
                break ; 
            }       
        }
    }
    return 0 ; 
}
