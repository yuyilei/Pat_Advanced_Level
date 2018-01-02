#include<iostream>
#include<queue>
using namespace std ;
struct node {
    int val ;
    struct node *left, *right ; 
    node(int v) : val(v), left(NULL), right(NULL) {} 
} ; 
int post[30] ; 
int in[30] ;

struct node *buildtree(int ps, int pe, int is, int ie) {
    struct node *res = NULL ; 
    if ( ps == pe ) {
        res = new struct node (post[pe]) ;
        return res ; 
    }
    int index = is ;
    for ( ; index <= ie && in[index] != post[pe] ; index++ ) ;  
    res = new struct node (post[pe]) ; 
    int len = index - is ; 
    if ( index != is ) res->left = buildtree(ps,ps+len-1,is,index-1) ; 
    if ( index != ie ) res->right = buildtree(ps+len,pe-1,index+1,ie) ; 
    return res ; 
}

void levelorder(struct node *root ) {
    queue<struct node *> q ;
    q.push(root) ; 
    int flag = 0 ; 
    while ( !q.empty() ) {
        int len = q.size() ; 
        for ( int i = 0 ; i < len ; i++ ) {
            struct node *tmp = q.front() ;
            q.pop() ; 
            if ( flag )  
                cout << " " ; 
            cout << tmp->val ;
            if ( tmp->left ) q.push(tmp->left) ;
            if ( tmp->right ) q.push(tmp->right) ; 
            flag = 1 ; 
        }
    }
    cout << endl ; 
}

int main() {
    int i, num ; 
    cin >> num ;
    for ( i = 0 ; i < num ; i++ )   
        cin >> post[i] ;
    for ( i = 0 ; i < num ; i++ ) 
        cin >> in[i] ;
    struct node *root = buildtree(0,num-1,0,num-1) ; 
    levelorder(root) ; 
    return 0 ; 
}