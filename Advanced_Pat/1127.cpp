#include<iostream>
#include<vector>
#include<deque>
using namespace std ;
struct  node {
    int val ;
    struct node * left , * right ;
    node( int v ) : val(v) , left(NULL) , right(NULL) { }
} ;
int postorder[30] , inorder[30] ;
int num , i , j = 0  , root  , flag = 0 ;
int find_index( int val ) {
    for ( i = 0 ; i < num ; i++ )
        if ( inorder[i] == val )
            return i ;
}
struct node *build ( int  part[] , int number, int index ) { // number是节点数目,index是子树开始的位置
    if ( number <= 0 )
        return  NULL ;
    root = part[number-1] ;
    i = find_index(root) - index ;
    cout << i << endl ;
    struct node * r = new struct node(root) ;
    r->left = build( part , i , index ) ;
    r->right = build( part+i , number-1-i , index+i+1 ) ;
    return r ;
}
int main() {
    cin >> num ;
    deque<struct node*> out (num) ;
    for ( i = 0 ; i < num ; i++ )
        cin >> inorder[i] ;
    for ( i = 0 ; i < num ; i++ )
        cin >> postorder[i] ;
    struct node * r = build(postorder,num,0) ;
    struct node *tmp ;
    out.push_back(r) ;
    int number = out.size() ;
    while ( j < num ) {
        number = out.size() ;
        if ( flag ) {
            for  ( i = 0 ; i < number ; i++ , j++ ) {
                tmp = out.front() ;
                out.pop_front() ;
                if ( j != 0 )
                    cout << " " ;
                cout << tmp ;
                if ( tmp->left != NULL )
                    out.push_front(tmp->left) ;
                if ( tmp->right != NULL )
                    out.push_front(tmp->right) ;
            }
            flag = 0 ;
        }
        else {
            for  ( i = 0 ; i < number ; i++ , j++ ) {
                tmp = out.front() ;
                out.pop_front() ;
                if ( j != 0 )
                    cout << " " ;
                cout << tmp ;
                if ( tmp->right != NULL )
                    out.push_front(tmp->right) ;
                if ( tmp->left != NULL )
                    out.push_front(tmp->left) ;
            }
            flag = 1 ;
        }
    }
}
