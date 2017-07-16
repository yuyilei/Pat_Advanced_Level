#include<cstdio>
#include<vector> 
#include<set>
using namespace std ;
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
        t = 0 , c = in[b-1].size() ;
        for ( auto it = in[a-1].begin() ; it != in[a-1].end() ; it++){ // 不知道为什么把这部分写成函数，就会超时！而且auto比  iterator 不容易超时？？ 
            if (in[b-1].find(*it) != in[b-1].end()){
                t++ ;    
            }
            else {
                c++ ;
            }
        }
        printf("%.1f%%\n",t/c*100) ; 
    }
    return 0 ; 
}
