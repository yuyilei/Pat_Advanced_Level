#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring> 
using namespace std ; 

vector<int> mapp [1020] ; 
int ways[1020][1020] = {0} ; 
int maxlen = -1, mintime = 99999 ; 
int resid = -2, n, m, ds; 

void dijkstra(int index) {
    int dis[1020] = {0} ; 
    int vis[1020] = {0} ; 
    int i, j, t ; 
    vis[index] = 1 ; 
    for ( i = 1 ; i <= n+m ; i++ ) 
        dis[i] = 99999 ; 
    for ( i = 0 ; i < mapp[index].size() ; i++ ) {
        dis[mapp[index][i]] = ways[index][mapp[index][i]] ;  
    }
    int num = 1, minlen = 99999, alltime = 0 ; 
    while ( num < n + m ) {
        int tmpid, minn = 99999 ; 
        for ( i = 1 ; i <= n+m ; i++ ) {
            if ( !vis[i] && minn > dis[i] ) {
                minn = dis[i] ; 
                tmpid = i ; 
            }
        } 
        if ( tmpid <= n && minn > ds )                                     // 到house的距离超出最大ds，直接不用找了，不符合条件。
            return ; 
        if ( tmpid <= n ) {                                                 
            alltime += minn ; 
            minlen = min(minlen,minn) ; 
        } 
        vis[tmpid] = 1 ; 
        num++ ; 
        for ( i = 0 ; i < mapp[tmpid].size() ; i++ ) {
            int next = mapp[tmpid][i] ; 
            if ( !vis[next] && dis[next] > dis[tmpid] + ways[next][tmpid] ) 
                dis[next] = dis[tmpid] + ways[next][tmpid] ; 
        }
    }
    if ( (minlen > maxlen) || (minlen == maxlen && alltime < mintime) ) {   // 因为查找是用ID小的到ID大的，只有满足条件时才更新，所以最后找的是相同条件下ID比较小的。
        maxlen = minlen ; 
        mintime = alltime ; 
        resid = index - n ; 
    }
}

/*
要注意这个格式啊！之前一直把所有ID默认当作0到9，然后一直有个样例过不了。。。！！！ id可以是很大的！
*/
int toid(char a[]) {
    int res = 0 ; 
    if ( a[0] == 'G' ) {
        sscanf(a+1,"%d",&res) ; 
        res += n ; 
    }
    else {
        sscanf(a,"%d",&res) ; 
    }
    return res ; 
}

int main() {
    int i, j, k, t ; 
    scanf("%d %d %d %d",&n,&m,&k,&ds) ; 
    char a[10], b[10] ; 
    for ( i = 0 ; i < k ; i++ ) {
        scanf("%s %s %d",a,b,&t) ; 
        int aid, bid ; 
        aid = toid(a) ; bid = toid(b) ; 
        ways[aid][bid] = ways[bid][aid] = t ; 
        mapp[aid].push_back(bid) ; 
        mapp[bid].push_back(aid) ; 
    }
    for ( i = n + 1 ; i <= n + m ; i++ ) {       //从 n+1到n+m 的每个点进行dijkstra 
        dijkstra(i) ; 
    }
    if ( resid < 0 ) 
        printf("No Solution\n") ; 
    else {
        printf("G%d\n",resid) ; 
        printf("%0.1f %0.1f\n",1.0*maxlen,mintime*1.0/n) ; 
    }
    return 0 ; 
}