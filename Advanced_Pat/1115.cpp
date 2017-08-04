#include<iostream>
#include<queue>
using namespace std ;
struct node {
    int val ;
    struct node *left , *right ;
    node(int v): left(NULL) , right(NULL) , val(v)  { }
} ;
void insert( struct node * &root , int v ) {
    if ( root == NULL ) {
        root = new  node(v) ;
        return ;
    }
    else if ( v <= root->val )
        insert(root->left,v) ;
    else
        insert(root->right,v) ;
}
int main() {
    int i , res1 , res2 , num , tmp ;
    cin >> num ;
    struct node *root = NULL , *temp ;
    for ( i = 0 ; i  < num ; i++ ) {
        cin >> tmp ;
        insert(root,tmp) ;   // 其实我不是很懂，如果这样建树的话，不就是把第一个输入的值当作根结点了吗，题目里有这样说吗，还是说就是默认这样？？
    }
    queue<struct node*> q ;
    q.push(root) ;
    while( !q.empty() ) {
        res1 = res2 ;
        res2 = q.size() ;
        for ( i = 0 ; i < res2 ; i++ ) {
            temp = q.front() ;
            q.pop() ;
            if ( temp->left )
                q.push(temp->left) ;
            if ( temp->right )
                q.push(temp->right) ;
        }
    }
    cout << res2 << " + " << res1 << " = " << res1+res2 << endl ;
    return 0 ;
}
