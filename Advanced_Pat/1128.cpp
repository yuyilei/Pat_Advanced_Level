#include<cstdio>
#include<set>
#include<vector>
using namespace std ;
int main() {
    int i , j , num ,tmp , temp ;
    scanf("%d",&num) ;
    for ( i = 0 ; i < num ; i++ ) {
        scanf("%d",&tmp) ;
        vector<int> b (tmp,0) ;
        set<int> a , c ;
        for ( j = 0 ; j < tmp ; j++ ) {
            scanf("%d",&temp) ;
            if ( b[temp-1] == 1 || temp > tmp ) { continue ; }
            b[temp-1] = 1 ;
            a.insert(temp+j) ;
            c.insert(temp-j) ;
        }
        printf("%s\n",((a.size()!=tmp)||(c.size()!=tmp))?"NO":"YES") ;
    }
    return 0 ;
}
