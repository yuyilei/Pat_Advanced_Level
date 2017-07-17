#include<cstdio>
#include<algorithm>
#include<map>
using namespace std ;
struct st {
    int score[4] , rank[4] , id , best ;
} ;
int t = 4  ;
int cmp ( struct st a , struct st b ) { return a.score[t] > b.score[t] ; }
int main() {
    int num , i , j , tmp ,  out ;
    char s[4] = {'A' , 'C' , 'M' , 'E' } ;
    scanf("%d %d",&num , &out) ;
    map <int , int > temp ;
    struct st * ps = new struct st  [num] ;
    for ( i = 0 ; i < num ; i++ ){
        scanf("%d %d %d %d",&ps[i].id,&ps[i].score[1],&ps[i].score[2],&ps[i].score[3]) ;
        ps[i].score[0]  = (ps[i].score[1] + ps[i].score[2] + ps[i].score[3] ) / 3.0 + 0.5 ;
    }
    for ( t = 0 ; t < 4  ; t++  ) {
        sort(ps,ps+num,cmp) ;
        ps[0].rank[t] = 1 ;
        for ( i = 1 ; i < num ; i ++) {
            ps[i].rank[t] = (ps[i].score[t] == ps[i-1].score[t] ) ? ps[i-1].rank[t] : i+1 ;
        }
    }
    for ( i = 0 ; i < num ; i++ ){
        temp[ps[i].id] = i ;
        ps[i].best = 0 ;
        int min = ps[i].rank[0] ;
        for ( j = 1 ; j < 4 ; j++ ) {
            if ( min > ps[i].rank[j] ) {
                ps[i].best = j ;
                min = ps[i].rank[j] ;
            }
        }
    }
    for ( i = 0 ; i < out ; i++ ) {
        scanf("%d",&tmp) ;
        if ( temp.count(tmp) == 0 )
            printf("N/A\n") ;
        else {
            tmp = temp[tmp] ;
            printf("%d %c\n",ps[tmp].rank[ps[tmp].best], s[ps[tmp].best]) ;
        }
    }
    return 0 ;
}
