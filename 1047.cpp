#include<cstdio>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std ; 
char st[40000][5] ; 
vector<int> course[2500] ; 
int cmp( int a , int b ){
    return strcmp( st[a] , st[b] ) < 0 ; 
}
int main() {
    int i , j ,k , cn , sn , temp , n ; 
    scanf("%d %d",&sn,&cn); 
    for ( i = 0 ; i < sn ; i++ ) {
        scanf("%s %d",st[i],&n) ; 
        for ( j = 0 ; j < n ; j++ ){
            scanf("%d",&temp) ; 
            course[temp].push_back(i) ; 
        }
    }
    for ( i = 1 ; i <= cn ; i++ ){
        printf("%d %lu\n",i,course[i].size()) ; 
        sort(course[i].begin(),course[i].end(),cmp) ; 
        for ( j = 0 ; j < course[i].size() ; j++ ){
            printf("%s\n",st[course[i][j]]) ; 
        }
    }
    return 0 ; 
}
