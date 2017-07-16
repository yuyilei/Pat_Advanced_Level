#include<stdio.h>
int prime(int num) {
    int i ; 
    if ( num == 2 ||  num == 3 )
        return 1 ;
    for ( i = 2 ; i < num/2 ; i ++  ){
        if( num % i  == 0 ){
            return 0 ;
        } 
    }
    return 1 ;
}
int main() {

    int n ,m , k, i , check[100000] = {0} , flag[10000] ={0} ;
    scanf("%d",&n) ;
    for ( i = 0 ; i < n ; i++  ){
        scanf("%d",&k) ; 
        flag[k] = 1 + i ;
    }
    scanf("%d",&m) ; 
    for( i = 0 ; i < m ; i++) {
        scanf("%d",&k) ;
        if ( flag[k] == 0 ){
            printf("%04d: Are you kidding?\n",k) ;
        }
        else {
            if ( check[k] == 1 ){
                printf("%04d: Checked\n",k) ;
            }
            else{
                if ( flag[k] == 1 ){
                    printf("%04d: Mystery Award\n",k) ;
                    check[k] = 1 ;
                }
                else {
                    if ( prime(flag[k]) == 1 ) {
                        printf("%04d: Minion\n",k) ;
                        check[k] = 1 ;
                    }
                    else{
                        printf("%04d: Chocolate\n",k) ;
                        check[k] = 1 ;
                    }
                }
            }
        }
    }
}
