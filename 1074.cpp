#include<cstdio>
typedef struct  {
    int data , now , next ; 
} node  ; 
int main() {
    int start , n , every , i = 0  , j = 0 , k = 0  , temp , all , tmp1 , tmp2 ; 
    scanf("%d%d%d",&start,&n,&every) ; 
    node in[100000] ; 
    node  *out  = new node [n]; 
    for ( i = 0 ; i < n ; i++ ){
        scanf("%d",&temp) ; 
        in[temp].now = temp ; 
        scanf("%d%d",&in[temp].data,&in[temp].next) ; 
    }
    for ( i = start , all = -1  ; i != -1 ; i = in[i].next ){
        all++ ;
    }
    k = start ; 
    while ( j <= all ){
        if ( (all + 1  - j) >= every ){
            for ( i = j + every - 1  ; i >= j   ; i-- , k = in[k].next){
                out[i].now = in[k].now ;                       
                out[i].data = in[k].data ; 
            } 
            j += every ; 
        }
        else {
            for ( i = j ; j <= all ; j ++ , k = in[k].next) {
                out[j].now = in[k].now ; 
                out[j].data = in[k].data ; 
            }
        }
    }
    for ( i = 0 ; i < all ; i++ ){
        printf("%05d %d %05d\n",out[i].now,out[i].data,out[i+1].now) ; 
    }
    printf("%05d %d -1\n",out[all].now,out[all].data) ; 
    return 0 ; 
}
