#include<iostream>
#include<vector> 
using namespace std ;
struct node {
    string val ; 
    int l, r ; 
    node(int a, int b, string s) : l(a), r(b) , val(s) {}
} ; 

vector<struct node*> tree ; 
int num, root = 1 ; 

void dfs(int index ) {
    if ( index != root && ( tree[index]->l != -1 || tree[index]->r != -1 ) ) 
        cout << "(" ; 
    if ( tree[index]->l != -1 ) 
        dfs(tree[index]->l ) ;
    cout << tree[index]->val  ;
    if ( tree[index]->r != -1 ) 
        dfs(tree[index]->r ) ; 
    if ( index != root && ( tree[index]->l != -1 || tree[index]->r != -1 ) ) 
        cout << ")" ; 
}

int main() {
    int i, j, t1, t2 ;
    string t3 ; 
    cin >> num ; 
    int isRoot[21] = {0} ; 
    tree.resize(num+1) ; 
    for ( i = 0 ; i < num ; i++ ) {
        cin >> t3 >> t1 >> t2 ; 
        if ( t1 != -1 ) isRoot[t1] = 1 ; 
        if ( t2 != -1 ) isRoot[t2] = 1 ; 
        tree[i+1] = new struct node (t1,t2,t3) ; 
    }
    while ( root <= num && isRoot[root] ) 
        root++ ; 
   dfs(root) ; 
   cout << endl ; 
   return 0 ;  
}