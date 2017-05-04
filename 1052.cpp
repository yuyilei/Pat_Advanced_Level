#include<cstdio>
#include<algorithm>
#define all 100000
using namespace std ; 
struct node{
    int now ; 
    int data ; 
    int next ; 
} res[all] ;  
int cmp ( struct node a , struct node b ){
    return a.data <  b.data ; 
}
int main() {
    int n , i , first ,  temp , cur = 0  ; 
    scanf("%d%d",&n,&first) ; 
    if ( first == -1 ){
        printf("0 -1\n") ; 
        return 0 ; 
    }
    struct node out[all] ; 
    for ( i = 0 ; i < n ; i ++ ){
        scanf("%d",&temp) ; 
        res[temp].now = temp ; 
        scanf("%d%d",&res[temp].data,&res[temp].next ) ; 
    }
    for ( i = first ; i != -1 ; i = res[i].next ) {
        out[cur++] = res[i] ; 
    }
    sort(out,out+cur,cmp) ; 
    printf("%d %05d\n",cur,out[0].now) ; 
    for ( i = 0 ; i < cur - 1 ; i++ ){
        printf("%05d %d %05d\n",out[i].now,out[i].data,out[i+1].now) ; 
    }
    printf("%05d %d -1\n",out[cur-1].now,out[cur-1].data) ; 
    return 0 ; 
}
