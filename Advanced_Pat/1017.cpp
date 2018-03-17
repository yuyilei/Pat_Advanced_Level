#include<cstdio>
#include<queue>
#include<vector> 
#include<algorithm>
using namespace std ; 

struct one {
    int at, wait ;
} ; 
const int clock_17 = 17*60*60 ; 
const int clock_8 = 8*60*60 ;  

int tosecond(int h, int m, int s ) {
    int tmp = h*60*60 + m*60 + s ; 
    if ( tmp > clock_17 ) 
        return -1 ; 
    return tmp ; 
}

vector<struct one> all ; 

bool cmp(struct one a, struct one b) {
    return a.at < b.at ;  
}

int main() {
    int i, j, n, k, h, m, s, w ; 
    float res = 0.0 ; 
    scanf("%d %d",&n,&k) ; 
    for ( i = 0 ; i < n ; i++ ) {
        scanf("%d:%d:%d %d",&h,&m,&s,&w) ; 
        int times = tosecond(h,m,s) ;  
        if ( times == -1 ) 
            continue ; 
        struct one tmp ; 
        tmp.at = times ; 
        tmp.wait = ( w > 60 ) ? 60*60 : w*60 ;  
        all.push_back(tmp) ; 
    }
    sort(all.begin(),all.end(),cmp) ; 
    priority_queue<int, vector<int>, greater<int> > q ;      
    for ( i = 0 ; i < k ; i++ ) 
        q.push(8*60*60) ;                                          // 现在优先队列中放入k个8点。 
    for ( i = 0 ; i < all.size() ; i++ ) {
        struct one tmp = all[i] ; 
        int t = q.top() ; 
        q.pop() ; 
        if ( t > tmp.at ) {                                        // 顾客到的时间迟，需要等待
            res += (float)(t-tmp.at) ; 
            t += tmp.wait ; 
        }
        else  
            t = tmp.at + tmp.wait ;                                // 顾客到的时间早，不需要等待。 
        q.push(t) ; 
    } 
    printf("%.1f\n",res/(all.size()*60)) ; 
    return 0 ; 
}