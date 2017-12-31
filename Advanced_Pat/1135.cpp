#include<iostream>
#include<cmath>
using namespace std ; 
struct node {
    int val ; 
    struct node *left, *right ; 
    node(int v) : val(v), left(NULL) , right(NULL) {}
} ; 

struct node *buildtree(struct node* root, int value) {
    if ( !root ) 
        root = new struct node(value) ; 
    else if ( abs(root->val) > abs(value) )
        root->left = buildtree(root->left,value) ; 
    else 
        root->right = buildtree(root->right,value) ; 
    return root ; 
}

bool tell_red_child(struct node* root ) {
    if ( !root ) 
        return true ; 
    if  ( root->val < 0 ) {
        if ( root->left && root->left->val < 0 ) 
            return false ; 
        if ( root->right && root->right->val < 0 ) 
            return false ; 
    } 
    return tell_red_child(root->left) && tell_red_child(root->right) ; 
}

int get_path(struct node* root ) {
    if ( !root ) 
        return 0 ; 
    int l = get_path(root->left) ; 
    int r = get_path(root->right) ; 
    return ( root->val > 0 ) ? 1 + max(l,r) : max(l,r) ; 
}

bool tell_path(struct node *root ) {
    if ( !root ) 
        return true ; 
    if ( get_path(root->left) != get_path(root->right) ) 
        return false ; 
    return tell_path(root->left) && tell_path(root->right) ; 
}

int main() {
    int all, i, j, n, tmp ;
    cin >> all ; 
    for ( i = 0 ; i < all ; i++ ) {
        cin >> n ; 
        struct node *root = NULL ; 
        for ( j = 0 ; j < n ; j++ ) {
            cin >> tmp ;
            root = buildtree(root,tmp) ; 
        }
        if ( (root->val > 0 ) && tell_red_child(root) && tell_path(root) ) 
            cout << "Yes" << endl ; 
        else 
            cout << "No" << endl ; 
    }
}   
