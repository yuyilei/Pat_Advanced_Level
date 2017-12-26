// 对于一个图，有n个定点，m条边，给出一个点的集合，判断是这个集合中的点是否全部覆盖全部的边 
// 我现在只想到很简单的很直接的算法 
#include<iostream>
#include<vector> 
#include<set> 
using namespace std ; 
typedef struct node {
    int s, e ; 
} ; 
int main() {
    int n, m, i, k, t, j, p, flag ; 
    cin >> n >> m ;  
    vector<node> edge (m) ; 
    for ( i = 0 ;i < m ; i++ ) {
        cin >> edge[i].s >> edge[i].e ; 
    }
    cin >> k ; 
    for ( i = 0 ; i < k ; i++ ) {
        cin >> t ; 
        set<int> tmp ; 
        for ( j = 0 ; j < t ; j++ ) {
            cin >> p ; 
            tmp.insert(p) ; 
        }                                         // 对每个点，它的起始点和终点必然至少有一个在点集合中，否则不满足
        for ( flag = 0, j = 0 ; j < m ; j++ ) {  // vector没有自己的find函数，所以还是用 set比较好   
            if ( tmp.find(edge[j].s) == tmp.end() && tmp.find(edge[j].e) == tmp.end() ) {
                flag = 1 ; 
                break ; 
            }
        }
        cout << ((flag)?"No":"Yes") << endl ;  
    }
    return 0 ; 
}