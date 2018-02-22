#include<iostream>
#include<cstdio>
using namespace std ;  

// 求最长的公共序列，序列中可以有重复
// stripe是彩带的映射，like是喜欢的颜色的映射，maxlen[i]是以i结尾的彩带的最大长度
int main() {
    int stripe[10001], like[201], maxlen[201] = {0}, maxx ; 
    int n, m, len, i, j, t, l ; 
    cin >> n >> m ; 
    for ( i = 1 ; i <= m ; i++ ) {
        cin >> t ; 
        like[t] = i ;  
    }   
    cin >> l ; 
    for ( i = 1 ; i <= l ; i++ ) {
        cin >> t ; 
        stripe[i] = like[t] ; 
    }
    for ( i = 1 ; i <= l ; i++ ) {
        maxx = 0 ; 
        for ( j = 1 ; j <= stripe[i] ; j++ )  
            maxx = max(maxx,maxlen[j]) ; 
        maxlen[stripe[i]] = maxx + 1 ; 
    } 
    maxx = 0 ; 
    for ( i = 1 ; i <= n ; i++ ) 
        maxx = max(maxx,maxlen[i]) ; 
    cout << maxx << endl ;
    return 0 ; 
}