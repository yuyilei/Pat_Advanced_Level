#include<queue>
#include<string.h>
#include<cstdio>
using namespace std ;
struct node {
    int left , right  , father  ;
    node():father(-1),left(-1),right(-1) { }
} ;
int main() {
    int num , i , j , tmp , temp , len , root , last  ;
    scanf("%d",&num) ;
    char a[5] ;
    struct node *p = new struct node [num] ;
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
        if ( p[i].father == -1 )
            root = i ;
    }
    queue < int > tree ;
    tree.push(root) ;
    for ( i = 0 ; i < num; i++ ) {
        temp = tree.front() ;
        if ( temp == -1 ) {
            break ;
        }
        last = temp ;
        tree.push(p[temp].left) ;
        tree.push(p[temp].right) ;
        tree.pop() ;
    }
    if ( i == num )
        printf("YES %d\n",last) ;
    else
        printf("NO %d\n",root) ;
    return 0 ;
}
