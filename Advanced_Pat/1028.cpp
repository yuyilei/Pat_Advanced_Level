#include<algorithm>
#include<string.h> // 最好用string.h ，不要用string ！！！
using namespace std ; 
struct node {
    int id , score ; 
    char name[9] ; 
} ; 
int cmp1 ( struct node a , struct node b ){
    return a.id < b.id ; 
}
int cmp2 ( struct node a , struct node b ){
    if ( a.name != b.name ){
        return strcmp(a.name,b.name)>0 ? 0 : 1   ; 
    }
    return a.id < b.id ; 
}
int cmp3 ( struct node a , struct node b ){
        if ( a.score != b.score ){
            return a.score < b.score ;
        }
    return a.id < b.id ; 
}
int main(){
    int i , j , k , n , c ; 
    scanf("%d%d",&n,&c) ; 
    struct node *p = new struct node [n] ; 
    for ( i = 0 ; i < n ; i ++ ){
        scanf("%d%s%d",&p[i].id,p[i].name,&p[i].score) ; 
    }
    if ( c == 1 ) {
        sort(p,p+n,cmp1) ; 
    }   
    else if ( c == 2 ){
        sort(p,p+n,cmp2) ; 
    }
    else {
        sort(p,p+n,cmp3) ; 
    }
    for ( i = 0 ; i < n ; i++ ){
        printf("%06d %s %d\n",p[i].id,p[i].name,p[i].score) ; 
    }
    return 0 ; 
}
