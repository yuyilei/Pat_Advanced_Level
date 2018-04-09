#include<cstdio>
#include<map> 
using namespace std ;

int pre[10010] = {0} ; 
map<int,int> flag ;                   // 要用map，如果 用 flag数组的话，对于负数可能会有段错误 
int n, m ; 

struct node {
    int v ; 
    struct node *l, *r ; 
    node(int x): v(x), l(NULL), r(NULL) {} 
} ; 

struct node *r = NULL ; 

struct node *buildtree(int s, int e) {
    if ( s > e || e >= n || s < 0 ) 
        return NULL ; 
    struct node *root = new struct node(pre[s]) ;  
    int mid = s+1 ; 
    for ( ; mid <= e && pre[mid] < pre[s] ; mid++ )  
        ; 
    if ( s+1 <= mid-1 ) 
        root->l = buildtree(s+1,mid-1) ;
    if ( mid <= e )
        root->r = buildtree(mid,e) ; 
    return root ; 
}

int dfs(struct node* root, int x, int y) {
    if ( root == NULL ) 
        return -1 ; 
    if ( root->v >= x && root->v <= y ) 
        return root->v ; 
    if ( root->v > y ) 
        return dfs(root->l,x,y) ; 
    if  ( root->v < x ) 
        return dfs(root->r,x,y) ;  
} 

int main() {
    scanf("%d %d",&m,&n) ; 
    int i, j, x, y, t ; 
    for ( i = 0 ; i < n ; i++ ) {
        scanf("%d",&pre[i]) ; 
        flag[pre[i]] = 1 ; 
    }
    r = buildtree(0,n-1) ;  
    for ( i = 0 ; i < m ; i++ ) {
        scanf("%d %d",&x,&y) ; 
        if ( flag.count(x) * flag.count(y) == 0 ) {
            if ( flag.count(x) ) 
                printf("ERROR: %d is not found.\n",y) ; 
            else if ( flag.count(y) ) 
                printf("ERROR: %d is not found.\n",x) ; 
            else 
                printf("ERROR: %d and %d are not found.\n",x,y) ; 
            continue ; 
        }
        int p = ( x > y ) ? y : x ; 
        int q = ( x > y ) ? x : y ;  
        int res = dfs(r,p,q) ; 
        if ( res == x ) 
            printf("%d is an ancestor of %d.\n",x,y) ; 
        else if ( res == y ) 
            printf("%d is an ancestor of %d.\n",y,x) ; 
        else 
            printf("LCA of %d and %d is %d.\n",x,y,res) ; 
    }
    return 0 ; 
}