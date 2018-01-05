#include<iostream>
using namespace std ;
struct node {
    int val ;
    struct node *left ,*right ;
    node(int v) : val(v), left(NULL), right(NULL) {} 
} ; 

int pre[1002] ; 
bool BST = true ; 
int  flag = 0, n ; 
bool cmp1 (int a, int b ) {                  // 比较函数，用于比较是不是二叉搜索树
    return a < b ; 
} 

bool cmp2 (int a, int b ) {                  // 比较函数，用于比较是不是二叉搜索树的镜面树 
    return a >= b ; 
}

struct node *build(int s, int e, bool cmp(int,int)) {
    if ( !BST || (s > e) ) 
        return NULL ;
    struct node *root = new struct node (pre[s]) ; 
    if ( s == e ) 
        return root ; 
    int index = s + 1 ; 
    for ( ; index <= e ; index++ ) {
        if ( !cmp(pre[index],pre[s])) 
            break ;  
    }
    root->left = build(s+1,index-1,cmp) ;            // 找到左子树的根节点 
    int other = index ; 
    for ( ; other <= e ; other++ ) {                 // 检查右子树中的节点是否规范，不规范的话，就停止建树 
        if ( cmp(pre[other],pre[s]) ) {
            BST = false ;
            return NULL ; 
        }
    } 
    root->right = build(index,e,cmp) ; 
    return root ; 
}

void postorder(struct node *root) {
    if ( root->left) 
        postorder(root->left) ;
    if ( root->right) 
        postorder(root->right) ; 
    flag++ ; 
    cout << root->val << ((flag == n)?"":" ") ;
} 

int main() {
    int i ;
    cin >> n ;
    for ( i = 0 ; i < n ; i++ ) 
        cin >> pre[i] ; 
    struct node *root = NULL ; 
    root = build(0,n-1,cmp1) ; 
    if ( BST ) {                               // 判断是不是二叉搜索树 
        cout << "YES" << endl ; 
        postorder(root) ;  
        cout << endl ; 
        return 0 ; 
    }
    BST = true ; 
    root = build(0,n-1,cmp2) ;                 // 判断是不是二叉搜索树的镜面树  
    if ( BST ) {
        cout << "YES" << endl ; 
        postorder(root) ; 
        cout << endl ; 
        return 0 ; 
    }
    cout << "NO" << endl ;
    return 0 ; 
}