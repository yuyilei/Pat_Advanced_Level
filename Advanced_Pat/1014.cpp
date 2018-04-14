#include<queue>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std ; 

struct cust{
    int spend, end ; 
} ;
struct oneline{
    queue<int> line ;                               // line是当前队伍中人的ID
    int now, top ;                                 // now是这个队伍的当前时间，top是这个队伍的第一个人所需的时间， now+top是这个队伍下一次的now
} ; 

void printtime(int end, int spend) {
    end += 60*8 ; 
    int h = end/60, m = end%60 ; 
    int start = end - spend ; 
    if ( start / 60 >= 17 ) 
        printf("Sorry\n") ;            // 如果开始时间大于17点，就不输出 
    else 
        printf("%02d:%02d\n",h,m) ; 
}

int main() {
    int n, m, k, q, i, j, t ; 
    scanf("%d %d %d %d",&n,&m,&k,&q) ; 
    vector<struct cust> c (k+1) ; 
    vector<struct oneline> lines (n+1) ;  
    vector<int> query (q) ; 
    for ( i = 1 ; i <= k ; i++ ) {
        scanf("%d",&c[i].spend) ; 
    }
    for ( i = 0 ; i < q ; i++ ) {
        scanf("%d",&query[i]) ; 
    }
    // 先给每个队伍中的人进行初始化，把尽量多的装进去 
    int waitid = 1 ; 
    for ( i = 1 ; i <= n ; i++ ) {
        lines[i].now = lines[i].top = 0 ; 
        for ( j = i ; j <= k && lines[i].line.size() < m ; j+= n ) {
            if ( lines[i].top == 0 ) 
                lines[i].top = c[j].spend ; 
            lines[i].line.push(j) ; 
            waitid = max(waitid,j) ; 
        }
    }
    waitid++ ; 
    int num = 0 ; 
    while ( num < k ) {
        int tmpid = 1 , minn = 99999, topid ; 
        for ( i = 1 ; i <= n ; i++ ) {                                        // 找出当前最快能处理完一个事物的队伍
            if ( lines[i].line.size() > 0 && lines[i].now + lines[i].top < minn ) {    // i 从 1 开始，只有 > 时，才更新 minn和tmpid，这样确保相同时间，取ID比较小的队伍
                tmpid = i ; 
                minn = lines[i].now + lines[i].top ; 
            }
        } 
        topid = lines[tmpid].line.front() ;                                  // 把那个队伍中的第一个人取出来，这个人的事务就处理完了
        c[topid].end = minn ;                                                 
        num++ ; 
        lines[tmpid].now = minn ;                                            // 更新队伍的当前时间
        lines[tmpid].line.pop() ;                              
        lines[tmpid].top = c[lines[tmpid].line.front()].spend ;              // 更新队伍的top值   
        if ( waitid <= k ) {                                                 // 如果还有人在等候，就把那个人加入到这个队伍中。
            lines[tmpid].line.push(waitid++) ; 
        }
    }
    for ( i = 0 ; i < q ; i++ ) {
        printtime(c[query[i]].end,c[query[i]].spend) ; 
    }
    return 0 ; 
}