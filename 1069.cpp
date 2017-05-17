#include<cstdio>
#include<algorithm>
using namespace std ; 
int change(int n){
    int a[4] = {0} , i = 0 , res = 0  , ten = 1 ; 
    while ( n > 0 ){
        a[i++] = n % 10 ; 
        n /= 10 ; 
    } 
    sort(a,a+4) ; 
    for ( i = 0 ; i < 4 ; i ++ ){
        res += (ten*a[i]) ; 
        ten *= 10 ; 
    }
    return res ; 
}
int main() {
    int  tmp1 , tmp2 , tmp3 ;
    scanf("%d",&tmp3) ; 
    do {
         tmp1 = change(tmp3) ;  
         tmp2 = 0 ;
         tmp3 = tmp1  ; 
         while ( tmp1 > 0 ){
            tmp2 = 10*tmp2 + tmp1 % 10 ; 
            tmp1 /= 10 ;
         } 
         printf("%04d - %04d = %04d\n",tmp3,tmp2,tmp3-tmp2) ; 
         tmp3 = tmp3 -tmp2 ;
         if ( tmp3 == 0 ){
            break ; 
         }
    } while ( tmp3 != 6174  ) ; 
    return 0 ; 
}
