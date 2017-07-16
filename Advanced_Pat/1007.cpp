#include<cstdio>
#include<vector>
using namespace std ; 
int main() {
    int n , max = -1 , tmp = 0 , i , flag = 0 , first , last , tmp2 = 0 ; // 一定要给定初始值！！否则他就随机乱来！！
    scanf("%d",&n) ; 
    vector<int> in (n,0) ; 
    for ( i = 0 ; i < n ; i++ ){
        scanf("%d",&in[i]) ; 
        tmp += in[i] ; 
        if ( in[i] >= 0 ) {
            flag = 1 ; 
        }
        if ( tmp > max ){
            max = tmp ; 
            first = tmp2 ; 
            last = i ;
        }
        else if ( tmp < 0 ){
            tmp = 0 ;
            tmp2 = i + 1 ; 
        }
    }
    if ( flag == 0 ){
        printf("0 %d %d\n",in[0],in[n-1]) ; 
        return 0 ; 
    }
    printf("%d %d %d\n",max,in[first],in[last]) ; 
    return 0 ; 
}

