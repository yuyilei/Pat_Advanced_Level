#include<iostream> // 题目的要求是1.包括所有顶点，2.初始的顶点和最后一个顶点是同一个3.相邻的两个顶点之间有路
#include<set>
using namespace std ;
int graph[201][201] = {0} ;
int main() {
    int n , m , i , j , k , tmp , a , b , flag , first , last ;
    cin >> n >> m ;
    for ( i = 0 ; i < m ; i++ ) {
        cin >> a >> b ;
        graph[a][b] = 1 ;
        graph[b][a] = 1 ;
    }
    cin >> k ;
    for ( i = 0 ; i < k ; i++ ) {
        flag = 0 ;
        cin >> tmp ;
        set<int> had ;
        if ( tmp != n+1 )   // 顶点个数必须是n+1 （包括所有顶点，出了初始点和最后一点之外不能重复
            flag = 1 ;
        cin >> a ;
        had.insert(a) ;
        for ( j = 0 , first = a ; j < tmp - 1 ; j++ ) {
            cin >> b ;
            had.insert(b) ;
            if ( graph[a][b] != 1 ) // 两点之间没路
                flag = 1 ;
            a = b ;
            last = b ;
        }
        if ( flag || had.size() != n || first != last ) // 不满足条件，就不是哈密顿图
            cout << "NO" << endl ;
        else
            cout << "YES" << endl ;
    }
}
