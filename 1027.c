#include<stdio.h>
void change(int a){

    char out[2] = {'0','0'};
    int k = 1 ;
    while( a > 0 ){
    
        int  s  = a % 13 ; 
        if ( s >= 10 ){
        
            switch ( s ) {
            case 10 : out[k--] = 'A' ; break ;
            case 11 : out[k--] = 'B' ; break ;
            case 12 : out[k--] = 'C' ; break ;
            }
        }
        else {
        
            out[k--] = s + '0' ;
        }
        a  /= 13 ;
    }
  printf("%c%c",out[0],out[1]) ; 
}
int main() {

    int red , green , blue ;
    scanf("%d%d%d",&red,&green,&blue) ;
    printf("#") ;
    change(red) ;
    change(green) ;
    change(blue) ;
    return 0 ;
}
