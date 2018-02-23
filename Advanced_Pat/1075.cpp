#include<iostream>
#include<algorithm>
#include<cstring> 
#include<cstdio> 
using namespace std ;

struct ST  {
    int s[6], sd, flag, sum, id ; 
} ; 

bool cmp ( ST a, ST b) {
    if ( a.sum != b.sum ) 
        return a.sum > b.sum ; 
    if ( a.sd != b.sd ) 
        return a.sd > b.sd ; 
    return a.id < b.id ; 
}

int main() {
    int n, m, k, p[6], i, j, t, uid, pid, ob, nowrank = 1 ; 
    cin >> n >> k >> m ; 
    struct ST *st = new struct ST [n+1] ;
    for ( i = 1 ; i <= k ; i++ ) 
        cin >> p[i] ; 
    for ( i = 1 ; i <= n ; i++ ) {
        st[i].sd = st[i].flag = st[i].sum = 0 ; 
        memset(st[i].s,-1,6*sizeof(int)) ; 
        st[i].id = i ; 
    }
    for ( i = 0 ; i < m ; i++ ) {
        cin >> uid >> pid >> ob ; 
        if ( st[uid].s[pid] < ob ) {                                   // 通过编译，且获得更好的分数 
            st[uid].s[pid] = ob ; 
            if ( ob == p[pid] ) 
                st[uid].sd++ ; 
        } 
        if ( ob != -1 )                                                 // 此人有题通过编译了，可以输出 
            st[uid].flag = 1 ; 
        if ( ob == -1 && st[uid].s[pid] == -1 )                         //  此人这道题没通过编译，设为得0分
            st[uid].s[pid] = 0 ;
    }
    for ( i = 1 ; i <= n ; i++ ) {
        for ( j = 1 ; j <= k ; j++ ) {
            if ( st[i].s[j] != -1 )
                st[i].sum += st[i].s[j] ; 
        }
    }
    sort(st+1,st+n+1,cmp) ; 
    for ( i = 1 ; i <= n ; i++ ) {
        if ( st[i].flag == 0 ) 
            break ; 
        if ( i != 1 && st[i].sum != st[i-1].sum )  
            nowrank = i ; 
        printf("%d %05d %d",nowrank,st[i].id,st[i].sum) ; 
        for ( j = 1 ; j <= k ; j++ ) { 
            if ( st[i].s[j] == -1 ) 
                cout << " -" ; 
            else 
                cout << " " << st[i].s[j] ; 
        } 
        cout << endl ; 
    }
    return 0 ; 
} 
