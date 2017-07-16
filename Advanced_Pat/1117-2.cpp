#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std ;
int cmp( int a , int b ){
    return a > b ; 
}
int main() {
    int n ,i, m , res ,t = 0 ,all , sum ;
    scanf("%d",&n) ;
    vector<int> a (n,0) ;
    vector<int> num (100000,0) ;
    vector<int> count (100000,0) ; 
    set<int> had ;
    for ( i = 0 ; i < n ; i++ ){
        scanf("%d",&m) ;
        if ( had.count(m) == 0 ){
            had.insert(m) ; 
            a[t++] = m ; 
        }
        count[m]++ ; 
    }
    for ( i = 0 ; i < t ; i++ ){
        all += count[a[i]] ;
    }
    a.resize(t) ; 
    sort(a.begin(),a.end(),cmp) ; 
    for ( i = 1 ; i < t ; i++) {
        sum += count[a[i-1]] ;
            if ( sum >= a[i] ){
                printf("%d",sum) ; 
                return 0 ; 
            }
    }
    printf("0") ; 
    return 0 ; 
}
