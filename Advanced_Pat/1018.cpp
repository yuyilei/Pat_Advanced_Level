#include<cstdio>
#include<vector>
using namespace std ; 

vector<int> tmpPath, resPath ; 
int minsend = 999999, minback = 999999, minlen = 999999 ; 
vector<int> ways [510] ; 
int mapp[510][510] = {0} ; 
int num[510] = {0} ; 
int maxc, sp, n, m, target ; 
int visit[510] = {0} ; 

void dfs(int s, int len, int send, int back, vector<int> &path) {
    if ( s == sp ) {
        if ( (len == minlen) && ((send < minsend ) || ( send == minsend && back < minback))) { 
            minsend = send ; 
            minback = back ; 
            resPath = path ; 
        }
        return ; 
    }
    for (int i = 0 ; i < ways[s].size() ; i++ ) {
        int next = ways[s][i] ; 
        if ( visit[next] == 0 ) {
            visit[next] = 1 ;
            path.push_back(next) ; 
            int next_back = back, next_send = send ; 
            if ( num[next] > target ) {
                next_back += (num[next]-target) ; 
            }
            else if ( num[next] < target ) {
                if ( target - num[next] < back ) 
                    next_back -= ( target - num[next]) ;  
                else {
                    next_send += ( target - num[next] - back ) ; 
                    next_back = 0 ; 
                }
            }
            dfs(next,len+mapp[s][next],next_send,next_back,path) ; 
            path.pop_back() ;
            visit[next] = 0 ;
        }
    } 
}

int dijstra() {
    int dis[510] = {0}, v[510] = {0} ; 
    v[0] = 1 ; 
    int i, j ; 
    for ( i = 1 ; i <= n ; i++ ) 
        dis[i] = 999999 ; 
    for ( i = 0 ; i < ways[0].size() ; i++ ) {
        dis[ways[0][i]] = mapp[0][ways[0][i]] ; 
    }
    while ( true ) {
        int minn = 999999, indexs = 1 ; 
        for ( i = 1 ; i <= n ; i++ ) {
            if ( v[i] == 0 && minn > dis[i] ) {
                minn = dis[i] ; 
                indexs = i ; 
            }
        }
        if ( indexs == sp ) 
            return minn ; 
        v[indexs] = 1 ; 
        for ( i = 1 ; i <= n ; i++ ) {
            if ( i != indexs && v[i] == 0 && mapp[i][indexs] != 0 && dis[i] > dis[indexs] + mapp[i][indexs] ) {
                dis[i] = dis[indexs] + mapp[i][indexs] ;  
            }
        }
    } 
}

int main() {
    int i, j, t, k, x, y ; 
    scanf("%d %d %d %d",&maxc,&n,&sp,&m) ; 
    target = maxc/2 ; 
    for ( i = 1 ; i <= n ; i++ ) {
        scanf("%d",&num[i]) ; 
    }
    for ( i = 0 ; i < m ; i++ ) {
        scanf("%d %d %d",&x,&y,&t) ; 
        ways[x].push_back(y) ; 
        ways[y].push_back(x) ; 
        mapp[x][y] = mapp[y][x] = t ; 
    }
    visit[0] = 1 ; 
    minlen = dijstra() ; 
    dfs(0,0,0,0,tmpPath) ; 
    printf("%d 0",minsend) ; 
    for ( i = 0 ; i < resPath.size() ; i++ ) {
        printf("->%d",resPath[i]) ; 
    } 
    printf(" %d\n",minback) ;
    return 0 ; 
}