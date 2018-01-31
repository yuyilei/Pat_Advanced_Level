#include<iostream>
#include<vector>
using namespace std ;
vector<vector<int> > load ;             // 路径的图  
vector<vector<int> > cost ;             // 花费的图 
vector<int> path ;                      // 到每个节点的最短路径
vector<int> pay ;                       // 到每个节点的最少花费 （前提是路径都是最短的）
vector<int> parent ;                    // 每个节点的父节点 
int n, m, s, d ; 

void dfs(int now ) {
    if ( now == d ) 
        return ; 
    for ( int i = 0 ; i < n ; i++ ) {
        if ( load[now][i] == 0 ) { 
            continue ; 
        }
        if ( (path[i] > path[now] + load[now][i] )                     // 如果路径更短  
                || ( (path[i] == path[now] + load[now][i] ) && ( pay[i] > pay[now] + cost[now][i] )) ) {  // 如果路径相同，但是花费更少 
            path[i] = min(path[i], path[now]+load[now][i]) ;           // 更新路径 
            pay[i] = min(pay[i], pay[now]+cost[now][i]) ;              // 更新花费
            parent[i] = now ;                                          // 更新父节点
            dfs(i) ;                                                   
        } 
    }
}

int main() {
    cin >> n >> m >> s >> d ; 
    int i, c1, c2, dis, costs ; 
    load.resize(n) ; 
    cost.resize(n) ; 
    path.resize(n) ; 
    pay.resize(n) ; 
    parent.resize(n) ; 
    for ( i = 0 ; i < n ; i++ ) {
        load[i].resize(n) ; 
        cost[i].resize(n) ; 
        path[i] = pay[i] = 10000000 ;                                   // 初始化为无穷大   
        parent[i] = -1 ;                                                // 每个节点的父节点初始化为-1 
    }
    path[s] = pay[s] = 0 ;                                              // 起点的路径和花费初始化为0  
    for ( i = 0 ; i < m ; i++ ) {
        cin >> c1 >> c2 >> dis >> costs ; 
        if ( load[c1][c2] == 0 || load[c1][c2] > dis ) {
            load[c1][c2] = load[c2][c1] = dis ; 
            cost[c1][c2] = cost[c2][c1] = costs ; 
        } 
        else if ( load[c1][c2] == dis && cost[c1][c2] > costs ) 
            cost[c1][c2] = cost[c2][c1] = costs ; 
    }
    dfs(s) ; 
    int k = parent[d] ;       // 从终点开始找每个节点的父节点  
    vector<int> res ;         // 最后倒置一下，就得到了这条路径
    res.push_back(d) ; 
    while ( k != -1 ) {
        res.push_back(k) ; 
        k = parent[k] ; 
    }
    for ( i = res.size()-1 ; i >= 0 ; i-- ) 
        cout << res[i] << " " ; 
    cout << path[d] << " " << pay[d] << endl ; 
    return 0 ; 
}
