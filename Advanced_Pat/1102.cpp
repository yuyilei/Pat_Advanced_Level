#include<cstdio>
#include<queue>
#include<stack>
#include<vector>
#include<string.h>
using namespace std ;
struct node {
    int left , right , father ;
    node() : left(-1) , right(-1) , father(-1) { }
} ;
vector<struct node > p ;
stack<int > k;
void to_order(int root) {    // 利用中序遍历对其进行排序
    if ( p[root].left == -1 && p[root].right == -1 ) {
        k.push(root) ;
        return ;
    }
    if ( p[root].left != -1 )
        to_order(p[root].left) ;
    k.push(root) ;
    if ( p[root].right != -1 )
        to_order(p[root].right) ;
}
int main () {
    int num , i , tmp , root , last , parent ;
    char a[6] ;
    scanf("%d",&num) ;
    p.resize(num) ;
    for ( i = 0 ; i < num ; i++ ) {
        scanf("%s",a) ;
        if ( a[0] != '-' ){
            sscanf(a,"%d",&tmp) ;
            p[tmp].father = i ;
            p[i].left = tmp ;
        }
        scanf("%s",a) ;
        if ( a[0] != '-' ){
            sscanf(a,"%d",&tmp) ;
            p[tmp].father = i ;
            p[i].right = tmp ;
        }
    }
    for ( i = 0 ; i < num ; i++ ) {
        if ( p[i].father == -1 ) {
            root = i ;
            break ;
        }
    }
    queue <int > q ;
    q.push(root) ;
    while ( !q.empty() ) {
        tmp = q.front() ;
        if ( tmp != root )
            printf(" ") ;
        printf("%d",tmp) ;
        q.pop() ;
       if ( p[tmp].right != -1 ) {
            q.push(p[tmp].right) ;
            last = p[tmp].right ;
       }
       if ( p[tmp].left != -1 )
            q.push(p[tmp].left) ;
    }
    printf("\n") ;
    to_order(root) ;
    for ( i = 0 ; i < num ; i++ ) {
        if ( i != 0 )
            printf(" ") ;
        tmp = k.top() ;
        printf("%d",tmp) ;
        k.pop() ;
    }
    return 0 ;
}
