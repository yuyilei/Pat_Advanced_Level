#include<vector>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std ; 

bool isfriend[10001][10001] = {false} ; 
vector<int> same_gender[10001] ; 
struct help {
    int x, y ; 
} ; 

bool cmp(struct help a, struct help b) {
    if ( a.x != b.x ) 
        return a.x < b.x ; 
    return a.y < b.y ; 
}

int main() {
    int i, j, n, m, t, p, q, k ; 
    char aa[6], bb[6] ; 
    scanf("%d %d",&n,&m) ; 
    for ( i = 0 ; i < m ; i++ ) {
        scanf("%s %s",aa,bb) ; 
        p = abs(atoi(aa)) ; 
        q = abs(atoi(bb)) ;   
        //cout << p << " " << q << endl ; 
        isfriend[q][p] = isfriend[p][q] = true ; 
        if ( strlen(aa) == strlen(bb) ) {
            same_gender[p].push_back(q) ; 
            same_gender[q].push_back(p) ; 
        }
    }
    scanf("%d",&k) ; 
    for ( i = 0 ; i < k ; i++ ) {
        vector<struct help> res ; 
        scanf("%s %s",aa,bb) ; 
        p = abs(atoi(aa)) ; 
        q = abs(atoi(bb)) ; 
        for ( j = 0 ; j < same_gender[p].size() ; j++ ) {
            if ( same_gender[p][j] == p || same_gender[p][j] == q )  
                continue ; 
            for ( t = 0 ; t < same_gender[q].size() ; t++ ) {
                if ( same_gender[q][t] == p )
                    continue ; 
                int a = same_gender[p][j] ; 
                int b = same_gender[q][t] ; 
                if ( isfriend[a][b] == true ) {
                    struct help h ;  
                    h.x = a ; h.y = b ; 
                    res.push_back(h) ; 
                }
            }
        }    
        sort(res.begin(),res.end(),cmp) ; 
        printf("%lu\n",res.size()) ; 
        for ( j = 0 ; j < res.size() ; j++ ) {
            printf("%04d %04d\n",res[j].x,res[j].y) ; 
        }
    }
}
