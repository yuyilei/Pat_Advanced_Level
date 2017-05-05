#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std ;
struct node{
    long number ;
    int score , location , all ,  part ;
} ; 
int cmp( struct node a , struct node b ){
    if ( a.score != b.score ){
        return a.score > b.score ;
    }
    else {
        return a.number < b.number ;
    }
}
int main(){
    int n , i , j , temp , k = 0 , start , end , before  ; 
    cin >> n ; 
    struct node *res = new struct node [n*300] ;
    for ( i = 0 ; i < n ; i++ ){
        cin >> temp ; 
        start = k ; 
        for ( j = 0 ; j < temp ; j++ ){
            cin >> res[k].number >> res[k].score ; 
            res[k++].location = i + 1 ; 
       }
        sort(res+start,res+k,cmp) ;
        res[start].part = 1 ; 
        for ( j = start + 1 ; j < k ; j++ ){
            res[j].part = (res[j-1].score==res[j].score)?res[j-1].part:(j-start+1) ;
        }
    }
    sort(res,res+k,cmp) ;
    res[0].all = 1 ;
    for ( i = 1   ; i < k ; i++ ){
        res[i].all = (res[i-1].score==res[i].score)?res[i-1].all:(i+1) ;
    }
    cout << k << endl ;
    for ( i = 0 ; i < k ; i++ ){
        printf("%013ld %d %d %d\n",res[i].number,res[i].all,res[i].location,res[i].part) ; // 学号要格式化输出 
    }
    return 0 ; 
}
