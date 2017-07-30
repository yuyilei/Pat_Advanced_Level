#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std ;
struct node {
    int val , father , left , right ;
    node():father(-1),left(-1),right(-1) { }
} ;
vector<struct node> p ;
vector<int > v ;
int now = 0 ;
void to_order( int root) { // 中序遍历
    if ( p[root].left != -1 )
        to_order(p[root].left) ;
    p[root].val = v[now++] ;
    if ( p[root].right != -1 )
        to_order(p[root].right) ;
}
int main() {
    int num , i , j , tmp , temp , root ;
    scanf("%d",&num) ;
    p.resize(num) ;
    v.resize(num) ;
    for ( i = 0 ; i < num ; i++ ) {
        scanf("%d",&tmp) ;
        if ( tmp != -1 ){
            p[tmp].father = i ;
            p[i].left = tmp ;
        }
        scanf("%d",&tmp) ;
        if ( tmp != -1 ){
            p[tmp].father = i ;
            p[i].right = tmp ;
        }
    }
    for ( i = 0 ; i < num ; i++ )
        scanf("%d",&v[i]) ;
    sort(v.begin() , v.end() ) ;
    for ( i = 0 ; i < num ; i++ ) {
        if ( p[i].father == -1) {
            root = i ;
            break ;
        }
    }
    to_order(root) ;
    queue <int > q ;
    q.push(root) ;
    while ( !q.empty() ) {
        temp = q.front() ;
        q.pop() ;
        if ( temp != root )
            printf(" ") ;
        printf("%d",p[temp].val) ;
        if ( p[temp].left != -1 )
            q.push(p[temp].left ) ;
        if ( p[temp].right != -1 )
            q.push(p[temp].right ) ;
    }
    return 0 ;
}
