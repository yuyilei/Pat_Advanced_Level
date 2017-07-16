#include<cstdio>
#include<algorithm>
using namespace std ;
struct node{
    int number, de, cai  ; 
} ;
int cmp ( struct node a , struct node b ){
    if ( a.cai+a.de != b.cai+b.de ){
        return  a.cai+a.de > b.cai+b.de ;
    }
    else if (a.de != b.de ){
        return a.de > b.de ; 
    }
    else {
        return a.number < b.number ; 
    }
}
int main(){
    int n , i , h , l  , v1= 0  , v2=0 , v3=0 , v4=0 , tmp1 , tmp2 , no  ; 
    scanf("%d%d%d",&n,&l,&h) ; 
    struct node *first = new struct node [100000] ; 
    struct node *second = new struct node [100000] ; 
    struct node *third  = new struct node [100000] ; 
    struct node *fourth = new struct node [100000] ; 
    for ( i = 0 ; i < n ; i++ ) {
        scanf("%d%d%d",&no,&tmp1,&tmp2) ; 
        if (  tmp1 >= h && tmp2 >= h ){
            first[v1].number = no ; 
            first[v1].de = tmp1 ; 
            first[v1++].cai = tmp2 ;
        }
        else if ( tmp1 >= h && tmp2 < h && tmp2 >= l ){
            second[v2].number = no ; 
            second[v2].de = tmp1 ;
            second[v2++].cai = tmp2 ; 
        }
        else if ( tmp1 >=l && tmp2 >= l && tmp1 >= tmp2 ){
            third[v3].number = no ; 
            third[v3].de = tmp1 ; 
            third[v3++].cai = tmp2 ;
        }
        else if ( tmp1 >= l && tmp2 >= l && tmp1 < tmp2 ){
            fourth[v4].number = no ; 
            fourth[v4].de = tmp1 ;
            fourth[v4++].cai = tmp2 ;
        }
    }
    sort(first,first+v1,cmp) ; 
    sort(second,second+v2,cmp) ; 
    sort(third,third+v3,cmp) ;
    sort(fourth,fourth+v4,cmp) ; 
    printf("%d\n",v1+v2+v3+v4) ; 
    for ( i = 0 ; i < v1 ; i++ ){
        printf("%d %d %d\n",first[i].number,first[i].de,first[i].cai) ; 
    } 
    for ( i = 0 ; i < v2 ; i++ ){
        printf("%d %d %d\n",second[i].number,second[i].de,second[i].cai) ; 
    }
    for ( i = 0 ; i < v3 ; i++ ){
        printf("%d %d %d\n",third[i].number,third[i].de,third[i].cai) ; 
    }
    for ( i = 0 ; i < v4 ; i++ ){
        printf("%d %d %d\n",fourth[i].number,fourth[i].de,fourth[i].cai) ; 
    }
    return 0 ; 
}
