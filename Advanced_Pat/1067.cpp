#include<cstdio>
using namespace std ;
void swap(int & a , int & b ) { int t = a ; a = b ; b = t ; }
int main() {
    int num , i , j , temp = 0 , tmp , flag = 1 , res = 0  ;
    scanf("%d",&num) ;
    int *p = new int [num] ;
    for ( i = 0 ; i < num ; i++ ) {
        scanf("%d",&tmp) ;
        p[tmp] = i ;  // 记住每个数字的位子
        if ( tmp != i && i != 0 ) temp++ ; // 除0之外不在位子上的数字之和
    }
    for ( i = 0 ; i < temp  ; i++ , res++ ) { // 把除0外所有数字放回原位，0自然就放回了原位
        if ( p[0] != 0 ) {      // 0不在0位上，直接交换
            swap(p[0],p[p[0]]) ;
        }
        else {      // 0在0位上，0与能最快找到不在原位上的数字交换，这步没有让任何一个数字回归原位，所以i--
            for ( j = flag ; j < num ; j++ ) {
                if ( p[j] != j ) {
                    swap(p[0],p[j]) ;
                    flag = j + 1  ; //  记录不在原位的起始数字
                    break ;
                }
            }
            i-- ;
        }
    }
    printf("%d\n",res) ;
    return 0 ;
}
