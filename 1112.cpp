#include<iostream>
using namespace std ;
int main() {
    string in ; 
    int i , j , k , tmp , flag[128] , len , count = 0 , num[129] = {0} , order[50] = {0}; 
    for ( i = 0 ; i < 128 ; i++ ){
        flag[i] = 256 ; // 很奇怪，不知道为什么设成129就是不行
    }
    cin >> k >> in ; 
    len = in.size() ; 
    for ( i = 0 ; i < len ; i++ ){
        num[in[i]]++ ; 
    }
    for ( i = 0 , j = 0 ; i < len  ; i++ ){
        if ( num[in[i]] % k == 0 && flag[in[i]] == 256 ){
            order[j] = in[i] ; 
            flag[in[i]] = j++ ;
        }
    }
    for ( i = 0 , count = j  ; i < count ; i++ ){
        for ( j = 0 ; j < len ;  ){
            if ( in[j] == order[i] ){
                num[in[j]] -= k ; 
                j += k ;
                continue ; 
            }
            j++ ;    
        }
        order[i] = ( num[order[i]] < 0 ) ? 0 : order[i] ; 
    }
    for ( i = 0 ; i < count ; i++ ){
        if ( order[i] != 0 ){
            printf("%c",order[i]) ; 
        }
    }
    printf("\n") ; 
    for ( i = 0 ; i < len ; ){
        printf("%c",in[i]) ; 
        i = (order[flag[in[i]]] != 0) ? (i + k ):(i+1) ; 
    }
    return 0 ; 
}
