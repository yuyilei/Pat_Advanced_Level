#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(char a[10] , char b[10]) {

    int yy1 = 10*(a[0]-'0') + (a[1]-'0') ;
    int yy2 = 10*(b[0]-'0') + (b[1]-'0') ;
    int mm1 = 10*(a[3]-'0') + (a[4]-'0') ;
    int mm2 = 10*(b[3]-'0') + (b[4]-'0') ;
    int ss1 = 10*(a[6]-'0') + (a[7]-'0') ;
    int ss2 = 10*(b[6]-'0') + (b[7]-'0') ;
    if ( yy1 > yy2 )
        return 1 ;
    else if ( yy1 < yy2 )
        return 0 ;
    else {
    
        if ( mm1 > mm2 ){
        
            return 1 ;
        }
        else if ( mm1 < mm2 )
            return 0 ;
        else {
        
            if (ss1 > ss2) 
                return 1 ;
            else 
                return 0 ;
        }
    }
}

int main(){

    char name[100000][20] ;
    char in[100000][10] ;
    char out[100000][10] ;
    int n ;
    int i ;
    int early = 0 ; // 最早的人的下标 
    int late = 0 ; // 最迟的人的下标

    scanf("%d",&n) ;
    for ( i = 0 ; i < n ; i++) {
    
        scanf("%s",name[i]) ;
        scanf("%s",in[i]) ;
        scanf("%s",out[i]) ;
    }
    for ( i = 0 ; i < n - 1 ; i++) {
    
        if ( cmp(in[i+1],in[early]) == 0 ) {
        
            early = i + 1 ;
        }

        if ( cmp(out[i+1],out[late]) == 1 ) {
        
            late = i + 1 ;
        }

    }
    
    printf("%s %s",name[early],name[late])  ;
    return 0 ; 
}
