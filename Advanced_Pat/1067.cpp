#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std ;
int find_one(vector<int> a , int key  ){
    for ( int i = 0 ; i < a.size() ; i++ ){
        if ( a[i] == key ){
            return i ;
        }
    }
}
int find_another(vector<int> a ){
    for ( int i = 1 ; i < a.size() ; i++ ){
        if ( a[i] != i ) {
            return i ;
        }
    }
    return -1 ;
}
int main() {
    int n , i ,j , temp = 0 , k , s ,  count = 0 , t = 0 ;
    scanf("%d",&n) ;
    vector<int> a (n) ;
    for ( i = 0 ; i < n ; i++ ){
        scanf("%d",&a[i]) ;
        if ( a[i] != i ){
            temp ++ ;
        }
    }
    if ( temp == 0 ) {
        printf("0\n") ;
        return 0 ;
    }
    int tmp = temp ;
    while ( t < temp - 1  ) {
        k = find_one(a,0) ;
        if  ( k == 0 ){
            s = find_another(a) ;
        //    swap(a[k],a[s]) ;
            printf("1\n" )  ;
            count ++ ;
        }
        else {
            s = find_one(a,k) ;
        //    swap(a[k],a[s]) ;
            t++ ;
            printf("2\n" )  ;
        }
        printf("swqp: %d %d\n",a[s],a[k]) ;
     //   printf("t : %d  k : %d  s : %d \n",t,k,s) ;
        int t = a[s] ;
        a[s] = a[k] ;
        a[k] = t ;
      //  if ( k == 0 )
           // break ;
    }
    printf("%d\n",count+tmp-1) ;
    return 0 ;
}
