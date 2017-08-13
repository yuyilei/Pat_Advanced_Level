#include<iostream>
using namespace std ; // 利用先序遍历和中序遍历，得出后序遍历
struct node{
    int val ;
    struct node * right , * left ;
    node(int v) : val(v),left(NULL),right(NULL) { }
} ;
char tmp[5] ;
int num , i = 0 , temp , root_val ;
struct node * build_tree() {
    struct node * r = NULL ;
    if ( i < 2*num ) { // i小于2*num就说明节点有可能还没有都输入，大于2*num就说明节点全部输入，可以直接return了
        i++ ;
        cin >> tmp ;
        if ( tmp[1] == 'u' ) {
            cin >> temp ;
            r = new struct node(temp) ;
        }
        else
            return NULL ;
        r->left = build_tree() ;
        r->right = build_tree() ;
    }
    return r ;
}
void postorder( struct node *r ) { // 后序遍历：左子树->右子树->根结点
    if ( r != NULL ) {
        postorder(r->left) ;
        postorder(r->right) ;
        cout << r->val ;
        if ( r->val == root_val )
            return ;
        cout << " " ;
    }
}
int main() {
    cin >> num ;
    struct node *root = build_tree() ;
    root_val = root->val ;
    postorder(root) ;
    return 0 ;
}
