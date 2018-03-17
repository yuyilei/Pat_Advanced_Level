#include<cstdio>
using namespace std ; 

/*
其实根本不用遍历链表。。。拿个数组记一下就好了，遇到相同的点，就代表找到了。。。
最后要注意格式化输出。。。 
*/

int main() { 
    int i, s1, s2, n, ad ;
    char tt[2] ; 
    int exist[100001], next[100001] ; 
    scanf("%d %d %d",&s1,&s2,&n) ;  
    for ( i = 0 ; i < n ; i++ ) {
        scanf("%d %s",&ad,tt) ;
        scanf("%d",&next[ad]) ; 
    }
    while ( s1 != -1 ) {
        exist[s1] = 1 ; 
        s1 = next[s1] ; 
    } 
    while ( s2 != -1 ) {
        if ( exist[s2] == 1 ) {
            printf("%05d\n",s2) ;                       //  注意%05d ！！  
            return 0 ; 
        }
        s2 = next[s2] ; 
    }
    printf("-1\n") ; 
    return 0 ; 
}