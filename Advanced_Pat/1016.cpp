#include<cstdio>
#include<vector>
#include<algorithm>
#include<string> 
#include<iostream> 
using namespace std ;

struct record {
    int now, status ; 
    string name ; 
    int dd, hh, mm ; 
} ; 

struct user {
    string name ; 
    vector<int> on, off ; 
} ;

int s[25] = {0}, n ;
float oneday = 0 ;  
vector<struct record> r ; 
vector<struct user> u ; 
int month ;
bool cmp ( struct record a, struct record b) {
    if ( a.name != b.name ) 
        return a.name < b.name ; 
    return a.now < b.now ; 
}

int formattime(int dd, int hh, int mm) {
    return (dd-1)*24*60 + hh*60 + mm ; 
}

float tmpbill(int hh, int mm) {                             // tmpbill返回 一天内打电话从 00:00到hh:mm所需的时间 
    float res = 0 ; 
    for ( int i = 0 ; i < hh ; i++ ) {
        res += 60*s[i]/100.0 ; 
    }
    res += mm*s[hh]/100.0 ; 
    return res ; 
}

float deal(int p, int q) {
    int onid = u[p].on[q] ; 
    int offid = u[p].off[q] ; 
    int d1 = r[onid].dd, h1 = r[onid].hh, m1 = r[onid].mm ; 
    int d2 = r[offid].dd, h2 = r[offid].hh, m2 = r[offid].mm ; 
    printf("%02d:%02d:%02d %02d:%02d:%02d %d ",d1,h1,m1,d2,h2,m2,r[offid].now-r[onid].now) ; 
    float tmpbill1 = tmpbill(h1,m1) ; 
    float tmpbill2 = tmpbill(h2,m2) ; 
    float res = (d2-d1)*oneday - tmpbill1 + tmpbill2 ;         // (oneday-tmpbill1) + (d2-d1-1)*oneday + tmpbill2 , 分别是 第一天 + 中间的整天 + 最后一天  
    return res ;            
}
 
int main() {
    int i, j, t, mm, dd, hh ; 
    for ( i = 0 ; i < 24 ; i++ ) {
        scanf("%d",&s[i]) ; 
        oneday += 60*s[i]/100.0 ; 
    }
    scanf("%d",&n) ; 
    r.resize(n) ; 
    char ss[20] ; 
    for ( i = 0 ; i < n ; i++ ) {
        cin >> r[i].name ; 
        scanf("%d:%d:%d:%d %s",&month,&r[i].dd,&r[i].hh,&r[i].mm,ss) ; 
        r[i].now = formattime(r[i].dd,r[i].hh,r[i].mm) ;
        r[i].status = ( ss[1] == 'f' ) ? 1 : 0 ; 
    }
    sort(r.begin(),r.end(),cmp) ; 
    struct user tmpuser ; 
    for ( i = 0 ; i < n ; i++ ) {
        if ( i == 0 || r[i].name != r[i-1].name ) {                                                 // 遇到新的用户
            if ( i != 0 )
                u.push_back(tmpuser) ;  
            tmpuser.name = r[i].name ; 
            tmpuser.on.clear() ;
            tmpuser.off.clear() ; 
        }
        if ( i != 0 && r[i].name == r[i-1].name && r[i].status == 1 && r[i-1].status == 0 ) {        // 对于同一个用户，前后两条分别是 on, off
            tmpuser.on.push_back(i-1) ; 
            tmpuser.off.push_back(i) ; 
        }
    }
    u.push_back(tmpuser) ; 
    for ( i = 0 ; i < u.size() ; i++ ) {
        if ( u[i].off.size() == 0 )                      // 如果用户的账号里面一条有效记录都没有，就跳过这个用户，不输出。  
            continue ; 
        cout << u[i].name << " " ; 
        printf("%02d\n",month) ; 
        float res = 0, one = 0 ; 
        for ( j = 0 ; j < u[i].off.size() ; j++ ) {
            one = deal(i,j) ; 
            res += one ; 
            printf("$%.02lf\n",one) ; 
        }
        printf("Total amount: $%.02lf\n",res) ; 
    }
    return 0 ; 
}