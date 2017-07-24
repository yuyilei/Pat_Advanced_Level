#include<cstdio>
using namespace std ;
void swap(int & a , int & b ) { int t = a ; a = b ; b = t ; }
int main() {
    int num , i , j , temp = 0 , tmp , flag = 0 , res = 0  ;
    scanf("%d",&num) ;
    int *p = new int [num] ;
    for ( i = 0 ; i < num ; i++ ) {
        scanf("%d",&tmp) ;
        p[tmp] = i ;
        if ( tmp != i && i != 0 ) temp++ ;
    }
    for ( i = 0 ; i < temp  ; i++ ) {
        if ( p[0] != 0 ) {
            swap(p[0],p[p[0]]) ;
        }
        else {
            for ( j = flag ; j < num ; j++ ) {
                if ( p[j] != j ) {
                    swap(p[0],p[j]) ;
                    flag++ ;
                    break ;
                }
            }
            i-- ;
        }
        res++ ;
    }
    printf("%d\n",res) ;
    return 0 ;
}
