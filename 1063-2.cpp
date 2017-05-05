#include<cstdio>
#include<vector> 
#include<set>
using namespace std ;
float get_similary(set<int> a , set<int> b){
    float t = 0 , c = b.size() ; 
    for ( auto it = a.begin() ; it != a.end() ; it++ ){
        if ( b.find(*it) != b.end() ){
            t++ ; 
        }
        else {
            c++ ; 
        }
    }
    float out = ( t / c ) * 100 ; 
    return out ; 
}
int main() {
    int n , m , i , j , temp , cnt , a , b , k ; 
    float t , c  ; 
    scanf("%d",&n) ; 
    vector<set<int> > in (n); 
    for ( i = 0 ; i < n ; i++ ){
        scanf("%d",&temp) ;
        for ( j = 0 ; j < temp ; j++ ){
            scanf("%d",&cnt) ; 
            in[i].insert(cnt) ; 
        }
    }
    scanf("%d",&k) ; 
    for ( i = 0 ; i < k ; i++ ){
        scanf("%d%d",&a,&b) ; 
        float res = get_similary(in[a-1],in[b-1]) ; 
        printf("%.1f%%\n",res) ;
    }
    return 0 ; 
}
