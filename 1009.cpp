#include<vector>
#include<cstdio> //  不知道为什么这里一定要加这个头文件，不然就编译错误，以后都加上吧
using namespace std ; 
int main() {
    int num1 , num2 ,  i , j , temp , out = 0  ; 
    double tmp ; 
    vector<double>  a (1001,0.0) ; 
    vector<double>  res(2002,0.0) ; // 应该设成2002,不然不够 
    scanf("%d",&num1) ; 
    vector<int> index(num1) ; 
    for ( i = 0 ; i < num1 ; i++ ){
        scanf("%d",&temp) ; 
        scanf("%lf",&a[temp]) ; 
        index[i] = temp ; 
    } 
    scanf("%d",&num2) ; 
    for ( i = 0 ; i < num2 ; i++ ){
        scanf("%d%lf",&temp,&tmp) ; 
        for ( j = 0 ; j < num1 ; j++ ){
            res[index[j]+temp] += (tmp*a[index[j]]) ; 
        }
    }
    for ( i = 2002 ; i >= 0 ; i-- ){
        if ( res[i] != 0.0 ){
            out++ ; 
        }
    }
    printf("%d",out) ; 
    for ( i = 2002 ; i >= 0 ; i-- ){
        if ( res[i] != 0.0 ){
            printf(" %d %.1f",i,res[i]) ; 
        }
    }
    return 0 ; 
}
