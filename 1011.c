#include<stdio.h>
int main() {

    char out[3] = { 'W' , 'T' , 'L'} ;
    float sum = 1 ; 
    int mark[3] = {0} ;
    int  i , j ;
    float in[3][3] ;
    float temp ;

    for ( i = 0 ; i < 3 ; i++){

            for ( j = 0 ; j < 3 ; j++){
        
            scanf("%f",&in[i][j]) ;
        }
    }

    for ( i = 0 ; i < 3 ; i++) {
    
        for ( j = 0 ; j < 3 ; j++ ){
        
            if (in[i][j] > in[i][mark[i]]) {
            
                mark[i] = j ;
            }
        }
        sum *= in[i][mark[i]] ;
    } 
    sum = (sum*0.65-1)*2 ;
    sum = (int)(100.0 * sum + 0.5) / 100.0 ; // 对保留2位,并对最后一位四舍五入  
    printf("%c %c %c %.2f",out[mark[0]],out[mark[1]],out[mark[2]],sum) ;
    return 0 ; 
}
