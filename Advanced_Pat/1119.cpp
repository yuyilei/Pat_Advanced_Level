#include<iostream>
#include<vector>
using namespace std ;
struct node {
    int val ; 
    struct node *left, *right ; 
    node(int v) : val(v), left(NULL), right(NULL) {}
} ; 
int pre[30], post[30] ; 
int num ; 
bool can = true ; 
int flag = 0 ; 

// 默认将根节点算入左子树
struct node *buildtree(int s1, int e1, int s2, int e2 ) {
    if ( s2 > e2 ) 
        return NULL ; 
    struct node *root = new struct node(pre[s1]) ; 
    if ( s2 == e2 ) 
        return root ; 
    int nextroot = pre[s1+1] ; 
    int index ; 
    for ( index = s2 ; index < e2 ; index++ ) 
        if ( post[index] == nextroot )
            break ; 
    if ( index == e2 - 1 )                               //  子树只有一条时，不能唯一确定
        can = false ; 
    int leftlen = index - s2 + 1 ; 
    root->left = buildtree(s1+1,s1+leftlen,s2,index) ; 
    root->right = buildtree(s1+leftlen+1,e1,index+1,e2-1) ; 
    return root ; 
}

void inorder(struct node *root ) {
    if ( !root ) 
        return ; 
    inorder(root->left) ; 
    cout << ((flag) ? " " : "" ) << root->val ; 
    flag  = 1 ; 
    inorder(root->right) ; 
}

int main() {
    int i, j, tmp ; 
    cin >> num ; 
    for (  i = 0 ; i < num ; i++ )  
        cin >> pre[i] ; 
    for (  i = 0 ; i < num ; i++ ) 
        cin >> post[i] ; 
    struct node *root = buildtree(0,num-1,0,num-1) ;  
    cout << ((can == true)?"Yes" : "No") << endl ; 
    inorder(root) ; 
    cout << endl ; 
    return 0 ; 
}