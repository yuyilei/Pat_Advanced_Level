#include<iostream>
#include<cstdio>
#include<map> 
#include<vector>
#include<algorithm> 
using namespace std ; 

// sort算法有个限制，利用sort算法只能对序列容器进行排序，就是线性的（如vector，list，deque）。
// map也是一个集合容器，它里面存储的元素是pair，但是它不是线性存储的(像红黑树），所以利用sort不能直接和map结合进行排序。  

int pre[1001] ;                                   // pre[i] 表示i的前驱节点 
int first[1001] = {0} ;                           // fisrt[i] 表示第i+1个人的第一个爱好的编号 
map<int,int> res ; 

int root(int a) {
    if ( pre[a] != a ) 
        pre[a] = root(pre[a]) ; 
    return pre[a] ; 
}

void Union(int a, int b) {
    int x = root(a) ; 
    int y = root(b) ; 
    if ( pre[x] != pre[y] ) 
        pre[x] = y ; 
}

int main() {
    int i, j, n, t, k, flag, num = 0 ; 
    cin >> n ; 
    for ( i = 1 ; i < 1001 ; i++ ) 
        pre[i] = i ; 
    for ( i = 0 ; i < n ; i++ ) {
        scanf("%d: %d",&k,&flag) ;  
        first[i] = flag ; 
        for ( j = 1 ; j < k ; j++ ) {
            cin >> t ; 
            Union(flag,t) ;                               // 将一个人的所有爱好连接   
        }
    } 
    
    for ( i = 0 ; i < n ; i++ ) {
        int g = root(first[i]) ;                          // 某一个人的所有爱好的根节点相同   
        if ( res.count(g) == 0 ) {                        // 出现一个新的连通分量 
            num++ ; 
            res[g] = 0 ; 
        }
        res[g]++ ; 
    }

    cout << num << endl ; 
    map<int,int> ::iterator it = res.begin() ; 
    vector<int> tmp ; 
    for ( ; it != res.end() ; it++ )  
        tmp.push_back(it->second) ; 
    sort(tmp.begin(),tmp.end()) ; 

    for ( i = tmp.size() - 1 ; i >= 0 ; i-- ) {
        if ( i != tmp.size() - 1 ) 
            cout << " " ; 
        cout << tmp[i] ; 
    }
    cout << endl ; 
    return 0 ; 
}