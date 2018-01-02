#include<iostream>
using namespace std ;
struct node {
    int val ; 
    struct node *left ,*right ; 
    node(int v) : val(v), left(NULL), right(NULL) {} 
} ; 

int treeheight(struct node *root ) {
    if ( !root ) 
        return 0 ; 
    return 1 + max(treeheight(root->left),treeheight(root->right)) ; 
}

struct node *L(struct node* root ){
    struct node *temp = root->right ; 
    root->right = temp->left ; 
    temp->left = root ; 
    return temp ; 
}

struct node *R(struct node* root ) {
    struct node *temp = root->left ;
    root->left = temp->right ; 
    temp->right = root ; 
    return temp ; 
}

struct node *RL(struct node* root ) {
    root->right = R(root->right) ;
    root = L(root) ; 
    return root ; 
}

struct node *LR(struct node* root ) {
    root->left = L(root->left) ; 
    root = R(root) ; 
    return root ; 
}

struct node *buildtree(struct node* root, int value ){
    if ( !root ) {
        root = new struct node(value) ; 
        return root ;  
    } 
    if ( value < root->val ) {
        root->left = buildtree(root->left,value) ; 
        int l = treeheight(root->left) ; 
        int r = treeheight(root->right) ; 
        if ( l - r >= 2 ) {
           if ( value < root->left->val ) 
                root = R(root) ; 
            else 
                root = LR(root) ; 
        } 
    }
    else { 
        root->right = buildtree(root->right,value) ; 
        int l = treeheight(root->left) ; 
        int r = treeheight(root->right) ; 
        if ( r - l >= 2 ) {
            if ( value > root->right->val ) 
                root = L(root) ; 
            else 
                root = RL(root) ; 
        }
    }
    return root ;
}

int main() {
    int num, i, tmp ; 
    cin >> num ; 
    struct node *root = NULL ;
    for ( i = 0 ; i < num ; i++ ) {
        cin >> tmp ; 
        root = buildtree(root,tmp) ; 
    }
    cout << root->val << endl ; 
    return 0 ; 
}