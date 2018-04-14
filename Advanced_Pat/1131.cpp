#include<cstdio>
#include<vector>
using namespace std ; 
int mapp[10000][10000] = {0} ; 
vector<int> resPath, nowPath ; 
vector<int> g[10000] ; 
int v[10000] = {0} ; 
int minstop, mintrans ; 

int counttrans(vector<int> path) {
    int res = 0 ; 
    for ( int i = 0 ; i < path.size() - 2 ; i++ ) {
        if ( mapp[path[i]][path[i+1]] != mapp[path[i+1]][path[i+2]] ) 
            res++ ;  
    }
    return res ; 
}

void dfs(int s, int e, int stopcount, int transcount) {
    if ( s == e ) {
        if ( (stopcount < minstop ) || (stopcount == minstop && counttrans(nowPath) < mintrans )) {
            resPath = nowPath ; 
            minstop = stopcount ; 
            mintrans = counttrans(nowPath) ; 
        }
        return ; 
    }
    for ( int i = 0 ; i < g[s].size() ; i++ ) {
        int next = g[s][i] ; 
        if ( v[next] == 0 ) {
            v[next] = 1 ; 
            nowPath.push_back(next) ; 
            dfs(next,e,stopcount+1,transcount) ; 
            nowPath.pop_back() ;
            v[next] = 0 ; 
        }
    }
}

void printstop() {
    int lastline = mapp[resPath[0]][resPath[1]] ; 
    printf("Take Line#%d from %04d to ",lastline,resPath[0]) ; 
    for ( int i = 1 ; i < resPath.size() ; i++ ) {
        if ( lastline != mapp[resPath[i]][resPath[i-1]] ) 
            printf("%04d.\nTake Line#%d from %04d to ",resPath[i-1],mapp[resPath[i]][resPath[i-1]],resPath[i-1]) ; 
        lastline = mapp[resPath[i]][resPath[i-1]] ; 
    }
    printf("%04d.\n",resPath[resPath.size()-1]) ; 
}

int main() {
    int n, i, j, k, t, last ; 
    scanf("%d",&n) ; 
    for ( i = 0 ; i < n ; i++ ) {
        scanf("%d",&k) ; 
        scanf("%d",&last) ; 
        for ( j = 0 ; j < k - 1 ; j++ ) {
            scanf("%d",&t) ; 
            mapp[last][t] = mapp[t][last] = i+1 ;
            g[last].push_back(t) ; 
            g[t].push_back(last) ; 
            last = t ; 
        }
    }
    scanf("%d",&k) ; 
    for ( i = 0 ; i < k ; i++ ) {
        int s, e ;
        scanf("%d %d",&s,&e) ; 
        resPath.clear() ; nowPath.clear() ; 
        minstop = mintrans = 99999 ; 
        v[s] = 1 ; 
        nowPath.push_back(s) ; 
        dfs(s,e,0,0) ; 
        v[s] = 0 ; 
        printf("%d\n",minstop) ; 
        printstop() ; 
    }
    return 0 ; 
}