#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std ;
#define all  26*26*26*10 + 26*26*10 + 26*10 + 10  
vector<int> res[all] ; // 它是一个二维数组 
int getID( char name[] ){ // 把名字变为唯一的ID
    int res = (name[3]-'0') + 10*(name[2]-'A') + 26*10*(name[1]-'A') + 26*26*10*(name[0]-'A') ; 
    return res ; 
}
int main() {
    int c , s , i , j , k , tmp1 , tmp2  ;
    char temp[5] ; // 不知道为什么memset(temp,0,5) 在pat里面会报错，编译错误  
    scanf("%d%d",&s,&c) ; 
    for ( i = 0 ; i < c ; i ++ ){
        scanf("%d%d",&tmp1,&tmp2) ; 
        for ( j = 0 ; j < tmp2 ; j++ ){
            scanf("%s",temp) ; 
            k = getID(temp) ; 
            res[k].push_back(tmp1) ; 
        }
    }
    for ( i = 0 ; i < s ; i++ ){
        scanf("%s",temp) ; 
        k = getID(temp) ; 
        sort(res[k].begin(),res[k].end()) ; // 默认升序排序 
        printf("%s %lu",temp,res[k].size()) ; 
        for ( j = 0 ; j < res[k].size()  ; j++ ){
            printf(" %d",res[k][j]) ; 
        }
        printf("\n") ; 
    }
    return 0 ; 
}
