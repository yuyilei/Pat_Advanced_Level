#include<iostream>
#include<vector>
#include<queue>
using namespace std ; 

struct node {
    int val ; 
    struct node *left, *right ; 
} ; 

struct node *root ; 
int n ; 

int treehight(struct node *tree ) {
    if ( !tree ) 
        return 0 ; 
    return 1 + max(treehight(tree->left),treehight(tree->right)) ; 
}

struct node* L(struct node* tree ) {
    struct node *tmp = tree->right ; 
    tree->right = tmp->left ; 
    tmp->left = tree ; 
    return tmp ; 
}

struct node* R(struct node* tree ) {
    struct node *tmp = tree->left ; 
    tree->left = tmp->right ; 
    tmp->right = tree ;
    return tmp ; 
}

struct node* RL(struct node* tree ) {
    tree->right = R(tree->right) ; 
    tree = L(tree) ; 
    return tree ; 
}

struct node* LR(struct node* tree ) {
    tree->left = L(tree->left) ; 
    tree = R(tree) ; 
    return tree ; 
}

struct node* buildtree(struct node *tree, int value ) {
    if ( !tree ) {
        tree = new struct node () ; 
        tree->val = value ; 
    }  
    else if ( value < tree->val ) {
        tree->left = buildtree(tree->left,value) ; 
        int lheight = treehight(tree->left) ;
        int rheight = treehight(tree->right) ; 
        if ( lheight - rheight >= 2 ) {
            if ( value < tree->left->val ) 
                tree = R(tree) ; 
            else 
                tree = LR(tree) ; 
        }
    }
    else {
        tree->right = buildtree(tree->right,value) ; 
        int lheight = treehight(tree->left) ;
        int rheight = treehight(tree->right) ; 
        if ( rheight - lheight >= 2 ) {
            if ( value > tree->right->val ) 
                tree = L(tree) ; 
            else 
                tree = RL(tree) ; 
        } 
    }
    return tree ; 
}

void level_order() {
    queue<struct node*> q ; 
    int flag = 1, num = 0 ; 
    q.push(root) ; 
    while ( !q.empty() ) {
        int len = q.size() ; 
        for ( int i = 0 ; i < len ; i++ ) {
            struct node* tmp = q.front() ; 
            q.pop() ; 
            if ( !tmp ) {
                 if ( num  < n ) flag = 0 ; 
                 continue ; 
            } 
            q.push(tmp->left) ;
            q.push(tmp->right) ; 
            if ( tmp->val != root->val ) 
                cout << " " ; 
            cout << tmp->val ; 
            num++ ; 
        }
    } 
    cout << "\n" << ((flag)?"YES":"NO") << endl ; 
}

int main() {
    int i, tmp ; 
    cin >> n ; 
    for ( i = 0 ; i < n ; i++ ) {
        cin >> tmp ;  
        root = buildtree(root,tmp) ; 
    }
    level_order() ; 
    return 0 ; 
} 