#include<iostream>
#include<vector>
#include<set> 
using namespace std ;
int main() {
    int n , m , s ,d , i ,c1 , c2 , d , cost;
    cin >> n >> m >> s >> d ;
    vector<vector<int> > map (n ,vector <int>(n));
    vector<int> costs (n,500) ;
    set<int> had ;
    for ( i = 0 ; i < m ; i++ ){
        cin >> c1 >> c2 >> d >> cost ;
        map[c1][c2] = d ; 
        costs[c2] = cost ;
    }
}
