// 最后两个测试点运行超时 T_T  
// 果然直接建树不行  QAQ 
#include<iostream>
#include<vector>
using namespace std ; 
struct node {
    int val ;
    struct node *left, *right ; 
    node(int v) : val(v) , left(NULL) , right(NULL) {} 
} ; 

vector<int> pre ;
vector<int> in ;  
int num, first = -1 ; 

int findindex(int value) {
    for ( int i = 0 ; i < num ; i++ ) 
        if ( in[i] == value ) 
            return i ; 
    return 0 ; 
}

struct node* buildtree(int ps, int pe, int is, int ie) {
    if ( (ps > pe ) || (is > ie )) return NULL ;
    int rval = pre[ps] ; 
    int index = findindex(rval) ; 
    int len = index - is ; 
    struct node* res = new struct node (rval) ; 
    res->left = buildtree(ps+1,ps+len,is,index-1) ; 
    res->right = buildtree(ps+len+1,pe,index+1,ie) ; 
    return res ; 
}

void postorder(struct node* root ) {
    if ( root->left && first == -1 ) postorder(root->left) ; 
    if ( root->right && first == -1 ) postorder(root->right) ; 
    if ( first == -1 )
        first = root->val ; 
    return ; 
}

int main() {
    int i, j ; 
    cin >> num ; 
    pre.resize(num) ;
    in.resize(num) ; 
    for ( i = 0 ; i < num ; i++ ) 
        cin >> pre[i] ; 
    for ( i = 0 ; i < num ; i++ ) 
        cin >> in[i] ; 
    struct node *root = buildtree(0,num-1,0,num-1) ; 
    postorder(root) ; 
    cout << first << endl ; 
    return 0 ; 
}
