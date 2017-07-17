#include<cstdio>
#include<algorithm>
using namespace std ;
struct node {
    double price , des ;
} ;
int cmp ( struct node a , struct node b ) { return a.des < b.des ; }
int main() {
    double C , D , A , sum = 0  , d = 0 , next , max , add , gas = 0 ,  flag ;
    int num , i , j , tmp , min ;
    scanf("%lf %lf %lf %d",&C,&D,&A,&num) ;
    max = C * A ;
    struct node *ps = new struct node [num+1] ;
    for ( i = 0 ; i < num ; i++ ) {
        scanf("%lf %lf",&ps[i].price,&ps[i].des) ;
    }
    ps[num].price = 0 ;
    ps[num].des = D ;
    sort(ps,ps+num,cmp) ;
    if ( ps[0].des != 0 ) {
        printf("The maximum travel distance = 0.00\n") ;
        return 0 ;
    }
    for ( i = 0 ; i < num && d <= D ; ) {
        tmp = i ;
        for ( j = i + 1 , min = j , flag = 0 ; d + max >= ps[j].des && j <= num ; j++ ) {
            if ( ps[tmp].price > ps[j].price && flag == 0 ) {
                flag = 1 ;
                tmp = j ;
            }
            min = ( ps[j].price < ps[min].price ) ? j : min ;
        }
        if ( tmp == i ) {  //能去的加油站的价格都比当前加油站贵
            sum += ( ( C - gas ) * ps[i].price ) ;
            d = ps[min].des  ; // 去价格最便宜的加油站
            gas = C  - ( ps[min].des - ps[i].des ) / A ; // 在当前加油站把油加满
            i = min ;
        }
        else {   // 找到当前加油站最近的且价格比当前加油站便宜的加油站
            add = (ps[tmp].des - ps[i].des) / A - gas ;
            gas = 0  ;  // 把油加到能去下一个加油站刚刚够用，到达下一个加油站时，油用完
            d = ps[tmp].des ;
            sum += ( add * ps[i].price ) ;
            i = tmp ;
        }
        if  ( gas < 0 ) {  //此时不能到达终点
            d +=  gas * A ;
            printf("The maximum travel distance = %.2f\n",d) ;
            return 0 ;
        }
    }
    printf("%.2lf\n",sum) ;
    return 0 ;
}
