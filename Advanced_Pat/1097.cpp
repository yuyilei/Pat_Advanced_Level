#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<set> 
#define all 100000 
using namespace std ;
struct node {
    int finall ;
    int data ; 
    int flag ; 
    int next ; 
} res[all] ; 
int cmp1 ( struct node a , struct node b ){
    return a.flag < b.flag ; 
}
int main() {
    int i , j , k , cur1 = 0 , cur2 = 0 , cur , temp , first , n  ; 
    scanf("%d%d",&first,&n) ; 
    set<int> had ; 
    for ( i = 0 ; i < n ; i++){
        scanf("%d",&temp) ; 
        res[temp].finall = temp ; 
        scanf("%d%d",&res[temp].data,&res[temp].next) ; 
    }
    for ( i = 0  ; i < all ; i++ ){
        res[i].flag = all*2 ; 
    }
    for ( i = first ; i != -1  ; i = res[i].next ){
        if ( had.count(abs(res[i].data)) == 0 ) {
            had.insert(abs(res[i].data)) ; 
            res[i].flag = cur1++ ; 
        }
        else {
            res[i].flag = all + cur2++ ; 
        }
    }
   sort(res,res+all,cmp1) ;
   cur = cur1 + cur2 ;
   for ( i = 0  ; i < cur  ; i++  ){
        if ( (i != cur1 - 1   ) && (i != cur - 1 ) ){
            printf("%05d %d %05d\n",res[i].finall,res[i].data,res[i+1].finall) ; 
        }
        else {
            printf("%05d %d -1\n",res[i].finall,res[i].data) ;
        }
   }
   return 0 ; 
}
