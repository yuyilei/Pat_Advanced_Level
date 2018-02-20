#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
using namespace std ; 
const int INF = 999999;                 // 不要用INT8_MAX！！！ 竟然会报浮点错误！！很迷  

int pre[201] ;                          // 前一个节点的下标
int hpy[201] ;                          // 每个节点的快乐值
int mosthpy[201] ;                      // 到每个节点的最大快乐值
int numofnode[201] = {0} ;              // 到每个节点的最少节点数
int mincost[201] ;                      // 到每个节点的最少花费
int vis[201] = {0} ;                    // 是否访问过该节点
int numroute[201] = {0} ;               // 到每个节点的路径的条数    
int way[201][201] = {0} ;               // 邻接矩阵    
map<string,int> name2int ; 
vector<string> name ; 
int rom = 0, n, k ; 

void Dijkstra() {
    int count = 1 ; 
    while ( count < n ) {
        int nowindex, minn = INF ; 
        for ( int i = 1 ; i < n ; i++ ) {
            if ( vis[i] == 0 && mincost[i] < minn ) {
                minn = mincost[i] ; 
                nowindex = i ; 
            }
        }
        vis[nowindex] = 1 ; 
        count++ ; 
        for ( int i = 0 ; i < n ; i++ ) {
            if ( vis[i] == 1 || way[nowindex][i] == 0 ) 
                continue ; 
            int nowtoi = mincost[nowindex] + way[nowindex][i] ; 
            if ( nowtoi < mincost[i] ) {
                mincost[i] = nowtoi ; 
                pre[i] = nowindex ; 
                numofnode[i] = numofnode[nowindex] + 1 ; 
                mosthpy[i] = mosthpy[nowindex] + hpy[i] ; 
                numroute[i] = numroute[nowindex] ; 
            }
            else if ( nowtoi == mincost[i] ) {
                numroute[i] += numroute[nowindex] ; 
                int nowhpy = mosthpy[nowindex] + hpy[i] ; 
                if ( (nowhpy > mosthpy[i]) || 
                        (nowhpy == mosthpy[i] && numofnode[i] > numofnode[nowindex] + 1) ) {
                    pre[i] = nowindex ; 
                    numofnode[i] = numofnode[nowindex] + 1 ; 
                    mosthpy[i] = nowhpy ; 
                }
            }
        }
    } 
}

int main() {
    int i, j, h, c, t ; 
    string n1, n2, start, res = "->ROM" ; 
    cin >> n >> k >> start ; 
    name2int[start] = 0 ; 
    name.push_back(start) ; 
    for ( i = 1 ; i < n ; i++ ) {
        cin >> n1 >> h ; 
        name.push_back(n1) ; 
        if ( n1 == "ROM" ) 
            rom = i ; 
        name2int[n1] = i ; 
        hpy[i] = h ; 
    }
    for ( i = 0 ; i < k ; i++ ) {
        cin >> n1 >> n2 >> c ; 
        way[name2int[n1]][name2int[n2]] = c ; 
        way[name2int[n2]][name2int[n1]] = c ; 
    }
    
    for ( i = 1 ; i < n ; i++ ) {
        if ( way[0][i] != 0 ) {
            mincost[i] = way[0][i] ; 
            numofnode[i] = 1 ;  
            pre[i] = 0 ; 
            mosthpy[i] = hpy[i] ; 
            numroute[i] = 1 ; 
        }        
        else 
            mincost[i] = INF ; 
    }
    vis[0] = 1 ; 
    Dijkstra() ;  
    cout << numroute[rom] << " " << mincost[rom] << " " << mosthpy[rom] << " " << mosthpy[rom]/numofnode[rom] << endl ;  
    t = rom ; 
    while ( pre[t] != 0 ) {
        res = "->" + name[pre[t]] + res ; 
        t = pre[t] ; 
    }
    res = start + res ; 
    cout << res << endl ; 
    return 0 ; 
}

