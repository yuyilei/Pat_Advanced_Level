#include<iostream>
#include<vector>
using namespace std ;
vector<vector<int> > load ; 
vector<int> team ; 
vector<int> visit ; 
int n, m, s, d, maxx = 0, res = 0, mindis = 10000000 ;

void dfs(int now, int dis, int num) {
    if ( now == d ) {
        if ( dis < mindis ) {
            mindis = dis ; 
            res = 1 ;  
            maxx = num ; 
        }
        else if ( dis == mindis ) {
            res++ ; 
            maxx = max(maxx,num) ; 
        }
        return ; 
    }
    if ( dis > mindis )  
        return ; 
    for ( int i = 0 ; i < n ; i++ ) {
        if ( load[now][i] == 0 || visit[i] )
            continue ; 
        visit[i] = 1 ; 
        dfs(i,dis+load[now][i],num+team[i]) ; 
        visit[i] = 0 ; 
    } 
}

int main() {
    cin >> n >> m >> s >> d ; 
    int i, c1, c2, l ; 
    load.resize(n) ; 
    team.resize(n) ;
    visit.resize(n) ; 
    for ( i = 0 ; i < n ; i++ ) 
        load[i].resize(n) ; 
    for ( i = 0 ; i < n ; i++ ) 
        cin >> team[i] ; 
    for ( i = 0 ; i < m ; i++ ) {
        cin >> c1 >> c2 >> l ;
        if ( load[c1][c2] == 0 || load[c1][c2] > l )
            load[c1][c2] = load[c2][c1] = l ; 
    }
    dfs(s,0,team[s]) ; 
    cout << res << " " << maxx << endl ; 
    return 0 ; 
}

