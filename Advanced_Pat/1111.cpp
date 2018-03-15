#include<cstdio>
#include<vector>
#include<queue> 
#include<algorithm> 
using namespace std ; 

/*
Dijkstra算法+bfs。。。
对于最短路径（距离），就直接Dijkstra就行了，题目要求对于路径一样短的路，选出其中花费时间最短时间的路径，所以只要在Dijkstra中加入新的限制条件，就可以得到题目要求的最短路径。 
对于最短时间路径，题目要求如果时间一样短，就用二维pre的数组存下所有的可能性，然后再用bfs得出最少节点的路径（本质就是邻接表的bfs。。）·
*/

int dispre[501], dvisit[501], tvisit[501], dd[501][501], tt[501][501], dis[501], times[501], dt[501] = {0} ;  
int n, m ; 
int start, finish, resdis = 0, restime = 0 ; 
int to[501] ; 
const int most = 100000000 ; 
vector<int> res1, res2 ; 
vector<int> timepre[501] ; 

void bfs() {                                            // 一个图的bfs 
    for ( int i = 0 ; i < n ; i++ ) 
        to[i] = -1 ;                                    // to[i] 表示 i 的 目的地 
    queue<int> q ; 
    q.push(finish) ; 
    int flag = 0 ; 
    while ( !flag ) { 
        int len = q.size() ; 
        for ( int i = 0 ; i < len ; i++ ) {
            int tmp = q.front() ; 
            q.pop() ; 
            for ( int j = 0 ; j < timepre[tmp].size() ; j++ ) {
                if ( to[timepre[tmp][j]] != -1 )                               // 如果to[i]已经被修改，说明i到finish的节点最少的路径已经被找到，就直接跳过。                       
                    continue ; 
                to[timepre[tmp][j]] = tmp ;  
                q.push(timepre[tmp][j]) ; 
                if ( timepre[tmp][j] == start ) {                              // 如果已经达到 start ，说明已经结束啦，直接跳出就行了。                
                    flag = 1 ; 
                    break ; 
                } 
            } 
            if ( flag == 1 ) 
                break ; 
        }
    } 
    int index = start ; 
    while ( index != -1 ) {                                                    // 利用to数组，求出最短路径和最短时间，求出来的res2的顺序是对的，不用倒置。
        res2.push_back(index) ; 
        restime += tt[index][to[index]] ; 
        index = to[index] ; 
    }
}

void toprintf(vector<int> v) {
    for ( int i = 0 ; i < v.size() ; i++ ) {
        if ( i != 0 ) 
            printf(" -> ") ;
        printf("%d",v[i]) ; 
    }
    printf("\n") ; 
}

int main() {
    int i, j, v1, v2, ow, d, t ; 
    scanf("%d %d",&n,&m) ; 
    for ( i = 0 ; i < m ; i++ ) {
        scanf("%d %d %d %d %d",&v1,&v2,&ow,&d,&t) ;  
        if ( ow == 0 ) {
            dd[v2][v1] = d ; 
            tt[v2][v1] = t ; 
        }
        dd[v1][v2] = d ; 
        tt[v1][v2] = t ; 
    }
    scanf("%d %d",&start,&finish) ; 
    dispre[start] = -1 ; 
    for ( i = 0 ; i < n ; i++ ) 
        dis[i] = most ; 
    dis[start] = 0 ; 
    dt[start] = 0 ; 
    for ( i = 0 ; i < n ; i++ ) {
        int minn = most, index = -1 ;  
        for ( j = 0 ; j < n ; j++ ) {
            if ( !dvisit[j] && dis[j] < minn ) {
                minn = dis[j] ; 
                index = j ;  
            }
        }
        if ( index == -1 ) 
            break ; 
        dvisit[index] = 1 ;
        for ( j = 0 ; j < n ; j++ ) {
            if ( dd[index][j] == 0 || dvisit[j] ) 
                continue ; 
            if ( dis[j] > dis[index] + dd[index][j] ) {       //  距离短，马上更新
                dis[j] = dis[index] + dd[index][j] ; 
                dt[j] = dt[index] + tt[index][j] ; 
                dispre[j] = index ;                     
            }
            else if ( dis[j] == dis[index] + dd[index][j] && dt[j] > dt[index] + tt[index][j] ) {     // 距离一样长，但是时间比较短，也更新 . 
                dt[j] = dt[index] + tt[index][j] ; 
                dispre[j] = index ;  
            } 
        }
    }

    int now = finish ; 
    while ( now != -1 ) {                                                 // 利用pre数组求出路径和最短路径的长度。 但是要注意，这个路径是倒置的。
        res1.push_back(now) ; 
        resdis += dd[dispre[now]][now] ; 
        now = dispre[now] ; 
    }
    reverse(res1.begin(),res1.end()) ; 

    for ( i = 0 ; i < n ; i++ ) 
        times[i] = most ; 
    times[start] = 0 ;  
    for ( i = 0 ; i < n ; i++ ) {
        int minn = most, index = -1 ; 
        for ( j = 0 ; j < n ; j++ ) {
            if ( !tvisit[j] && times[j] < minn ) {
                minn = times[j] ; 
                index = j ;
            } 
        } 
        if ( index == -1 ) 
            break ; 
        tvisit[index] = 1 ; 
        for ( j = 0 ; j < n ; j++ ) {
            if ( tt[index][j] == 0 || tvisit[j] ) 
                continue ; 
            if ( times[j] > times[index] + tt[index][j] ) {                  // 时间短，立刻更新
                times[j] = times[index] + tt[index][j] ;  
                timepre[j].clear() ; 
                timepre[j].push_back(index) ; 
            }
            else if ( times[j] == times[index] + tt[index][j] ) {             // 时间一样短，存入二维数组
                timepre[j].push_back(index) ; 
            }
        }
    }
    bfs() ;                                                                   // 所有可能的路径是一个邻接表，对它进行广度优先遍历 
    if ( res1 != res2 ) {                                                     // 对于简单类型，vector竟然可以直接比较 　！！! 
        printf("Distance = %d: ",resdis) ; 
        toprintf(res1) ; 
        printf("Time = %d: ",restime) ; 
        toprintf(res2) ; 
    }
    else {
        printf("Distance = %d; Time = %d: ",resdis,restime) ; 
        toprintf(res1) ; 
    }
    return 0 ; 
} 