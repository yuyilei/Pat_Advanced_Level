#include<iostream>
#include<map>
#include<set>
#include<cstdio>
using namespace std ; 

map<string, set<int> > auther, title, pub, year, keys ; 
// 主要是各种形式的输入 ，getchar, getline 等。。。 
// 我不是很清楚，还要再学一学 
// 字符串的处理好麻烦啊。。。。

void search(map<string, set<int> > &m, string k) {                       // 使用引用，减少函数运行时间 
    if ( m.find(k) == m.end() ) {
        printf("Not Found\n") ; 
        return ;  
    }  
    set<int> :: iterator it = m[k].begin() ; 
    for ( ; it != m[k].end() ; it++ ) {
        printf("%07d\n",*it) ; 
    }
}

int main() {
    int n, m, i, t, tid ; 
    string tmp, query ; 
    char f ;
    scanf("%d",&n) ; 
    for ( i = 0 ; i < n ; i++ ) {
        scanf("%d",&tid) ; 
        getchar() ; 
        getline(cin,tmp) ; 
        title[tmp].insert(tid) ; 
        getline(cin,tmp) ; 
        auther[tmp].insert(tid) ; 
        while ( cin >> tmp ) {
            keys[tmp].insert(tid) ; 
            if ( ( f = getchar() ) == '\n' ) 
                break ; 
        }
        getline(cin,tmp) ; 
        pub[tmp].insert(tid) ; 
        getline(cin,tmp) ; 
        year[tmp].insert(tid) ; 
    }
    scanf("%d",&m) ; 
    for ( i = 0 ; i < m ; i++ ) {
        scanf("%d: ",&t) ;
        getline(cin,query) ; 
        printf("%d: ",t) ; 
        cout << query << endl ; 
        if ( t == 1 ) search(title,query) ; 
        if ( t == 2 ) search(auther,query) ; 
        if ( t == 3 ) search(keys,query) ; 
        if ( t == 4 ) search(pub,query) ; 
        if ( t == 5 ) search(year,query) ; 
    }
    return 0 ; 
} 

