#include<iostream>
using namespace std ; 

int pre[10001] = {0} ; 
int maxx = 0 ; 

int root(int a) {
    if ( pre[a] != a ) 
        pre[a] = root(pre[a]) ;                    // 找出一个联通分支的根节点  
    return pre[a] ;  
}

void Union(int a, int b) {                         // 合并两个节点 
    int x = root(a) ; 
    int y = root(b) ;  
    if ( x != y ) 
        pre[x] = y ; 
}

int main() {
    int n, m, i, j, t, k, flag, a, b, tree = 0 ; 
    cin >> n ; 
    for ( i = 1 ; i < 10001 ; i++ ) 
        pre[i] = i ; 
    for ( i = 0 ; i < n ; i++ ) {
        cin >> k >> flag ;                         // 把所有在同一棵树上的鸟合并为一棵树上的鸟 
        maxx = max(maxx,flag) ; 
        for ( j = 1 ; j < k ; j++ ) {               
            cin >> t ; 
            maxx = max(maxx,t) ; 
            Union(flag,t) ; 
        }
    }  
    for ( i = 1 ; i <= maxx ; i++ ) {
        if ( pre[i] == i ) 
            tree++ ; 
    }
    cout << tree << " " << maxx << endl ; 
    cin >> m ; 
    for ( i = 0 ; i < m ; i++ ) {
        cin >> a >> b ; 
        if ( root(a) == root(b) )                           // 根相同  
            cout << "Yes" << endl ; 
        else 
            cout << "No" << endl ; 
    }   
    return 0 ; 
}