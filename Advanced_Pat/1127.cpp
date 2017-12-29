#include<iostream>
#include<queue>
#include<stack>
using namespace std ;
struct  node {
    int val ;
    struct node * left , * right ;
    node( int v ) : val(v) , left(NULL) , right(NULL) { }
} ;
int postorder[30] , inorder[30] ;
int num , root ;
int find_index( int val ) {
    for ( int i = 0 ; i < num ; i++ )
        if ( inorder[i] == val )
            return i ;
}
struct node *build ( int  part[] , int number, int index ) { // number是节点数目,index是子树开始的位置
    if ( number <= 0 )
        return  NULL ;
    root = part[number-1] ;
    int i = find_index(root) - index ;
    struct node * r = new struct node(root) ;
    r->left = build( part , i , index ) ;
    r->right = build( part+i , number-1-i , index+i+1 ) ;
    return r ;
}
int main() {
    int i, j, flag = 1, k ; 
    cin >> num ;
    for ( i = 0 ; i < num ; i++ )
        cin >> inorder[i] ;
    for ( i = 0 ; i < num ; i++ )
        cin >> postorder[i] ;
    struct node * r = build(postorder,num,0) ;
    queue<struct node*> q ; 
    stack<int> t ; 
    q.push(r) ; 
    k = r->val ; 
    while ( !q.empty() ) {
        int len = q.size() ; 
        for ( i = 0 ; i < len ; i++ ) {
            struct node* tmp = q.front() ; 
            q.pop() ; 
            if ( flag ) 
                t.push(tmp->val) ; 
            else { 
                if ( tmp->val != k )
                    cout << " " ; 
                cout << tmp->val ; 
            }
            if ( tmp->left ) q.push(tmp->left) ; 
            if ( tmp->right ) q.push(tmp->right) ; 
        }
        if ( flag ) {
            while ( !t.empty() ) {
                if ( t.top() != k ) 
                    cout << " " ; 
                cout << t.top() ; 
                t.pop() ; 
            }
        }
        flag = !flag ; 
    } 
    return 0 ; 
}
