#include<stdio.h>
#include<string.h>
int main() {

     char a[1000] ;
     char b[1000] ;
     int n1[128] = {0} ;
     int n2[128] = {0} ;
     int i ;
     gets(a) ;
     gets(b) ;
     int sum = 0 ;
     int flag = 0 ;
     int len1 = strlen(a) ;
     int len2 = strlen(b) ;

     for ( i = 0 ; i < len1 ; i++)
        n1[(int)(a[i])]++ ;
     
     for ( i = 0 ; i < len2 ; i++)
        n2[(int)(b[i])]++ ;

     for ( i = 0 ; i < 128 ; i++){
         if ( n1[i] < n2[i] ){
             sum += n2[i] - n1[i] ;
         }
     }
     if  ( sum ) {
         printf("No %d",sum) ;
     }

     else {
         printf("Yes %d",len1-len2) ;
     }
     return 0 ; 
}
