#include<cstdio>
#include<stack>
using namespace std ;
int main() {
    int i , j , m , n , k , tmp , temp , t , flag = 0 , last ;
    scanf("%d %d %d",&n,&m,&k) ;
    for ( i = 0 , flag = 0 ; i < k ; i++ ) {
        stack<int> s ;
        for ( j = 0 , flag = 0 , tmp = 1 , last = 1 ; j < m ; j++ ) {
            scanf("%d",&t) ;
            if ( t >= tmp ) { // 如果输入的数字比当前栈顶的数字小，就把数字压入栈入，直到输入的数字等于当前栈顶
                while  ( flag == 0 && tmp <= m ) {
                    s.push(tmp) ;
                    if ( s.size() > n  ) {   // 栈中数字多于n
                        flag = 1 ;
                        break ;
                    }
                    last = tmp ;
                    tmp++ ;
                    if ( last == t ) {  // 栈顶的数字等于输入的数字
                        s.pop() ;
                        break ;
                    }
                }
            }
            else if ( flag == 0 ) { // 输入的数字大于等于栈顶的数字，直接pop出栈顶的数字，如果不等于输入的数字，说明不符合要求
                temp = s.top() ;
                s.pop() ;
                if ( temp != t ) {
                    flag = 1 ;
                }
            }
        }
        if ( flag == 1 )
            printf("NO\n") ;
        else
            printf("YES\n") ;
    }
    return 0 ;
}
