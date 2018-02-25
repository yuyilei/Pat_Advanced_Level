#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

struct SC {                                     // 学校
    int num ;
    vector<int> people ; 
} ; 

struct ONE {                                    // 学生 
    int ge, gi, gf, ch[5], rank, id ; 
    bool vis ; 
} ; 

typedef struct SC sc ;
typedef struct ONE one ; 

bool cmp(one a, one b) {
    if ( a.gf != b.gf ) 
        return a.gf > b.gf ; 
    return a.ge > b.ge ; 
} 

int main() {
    int n, m, k, i, j, t, now = 0, p ; 
    cin >> n >> m >> k ;
    vector<one> ap (n) ; 
    vector<sc> sch (m) ; 
    vector<int> ranks [n] ; 
    for ( i = 0 ; i < m ; i++ ) 
        scanf("%d",&sch[i].num) ; 
    for ( i = 0 ; i < n ; i++ ) {
        scanf("%d %d",&ap[i].ge,&ap[i].gi) ; 
        ap[i].vis = false ;                                 // 标示位，一旦被录取，下次就跳过这个人
        ap[i].gf = (ap[i].ge+ap[i].gi) / 2 ; 
        ap[i].id = i ;                                      // 排序之后，需要就序号不等于ID，所以需要一个ID
        for ( j = 0 ; j < k ; j++ ) 
            scanf("%d",&ap[i].ch[j]) ; 
    }
    sort(ap.begin(),ap.end(),cmp) ; 
    for ( i = 0 ; i < n ; i++ ) {
        if ( i != 0 && ((ap[i].gf < ap[i-1].gf) || ( ap[i].gf == ap[i-1].gf && ap[i].ge < ap[i-1].ge ))) 
            now++ ; 
        ranks[now].push_back(i) ;                           // 每个等级都存入这个等级相应的人的序号（不是ID）
    } 
    for ( i = 0 ; i <= now ; i++ ) {                        // 遍历每个等级
        vector<int> tmpnum (m,0) ;                          // 用于记录每个等级的所有人的录取情况
        for ( j = 0 ; j < ranks[i].size() ; j++ ) {         // 遍历每个等级中的每个人
            t = ranks[i][j] ; 
            int nowid = ap[t].id ; 
            if ( ap[t].vis == true )                        // 已经被录取，跳过
                continue ; 
            for ( p = 0 ; p < k ; p++ ) {                   // 遍历每个人的志愿   
                int w = ap[t].ch[p] ; 
                int schnum = sch[w].num ; 
                if ( schnum > 0 ) {                         // 这个人的当前志愿还有空余，就录取他
                    sch[w].people.push_back(nowid) ;        // 存入这个人的ID（不是序号） 
                    tmpnum[w]++ ; 
                    ap[t].vis = true ;                      // 设为录取 
                    break ; 
                }
            }
        }
        for ( p = 0 ; p < m ; p++ )  
            sch[p].num -= tmpnum[p] ;                       // 因为如果，同一等级，即使学校人数会超也要录取，所以所以先将每层的录取情况存入tmpnum，遍历完一个等级之后，再减去相应的名额
    }                                                       // 相同等级的人的优先级是相同的
    for ( i = 0 ; i < m ; i++ ) {
        sort(sch[i].people.begin(),sch[i].people.end()) ;   // 对ID进行排序
        for ( j = 0 ; j < sch[i].people.size() ; j++ ) {
            if ( j != 0 ) 
                cout << " " ;
            cout << sch[i].people[j] ; 
        }
        cout << endl ;
    }
    return 0 ; 
}