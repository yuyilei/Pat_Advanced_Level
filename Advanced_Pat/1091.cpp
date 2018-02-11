#include<iostream>
#include<queue> 
using namespace std ; 

// 三维数组的 bfs 找出每一团尽可能大的像素点，如果这团像素点的体积大于 t ，就把 这团像素点的体积加入最后的结果中，
// 注意每个像素点只能使用一次，所以每次使用过了这个像素点之后，把这个点设为0  
// 查找尽可能大的像素团，用bfs 

int matrix[60][128][1286] = {0} ;  
int m, n, l, t, res = 0 ; 
int xyz[3][6] = { {1,-1,0,0,0,0}, {0,0,1,-1,0,0}, {0,0,0,0,1,-1} } ; 

struct node {
    int x, y, z ; 
    node(int a, int b, int c) : x(a), y(b), z(c) {} 
} ; 
typedef struct node node ; 

void count(int x, int y, int z) {
    matrix[x][y][z] = 0 ; 
    int num = 1 ; 
    queue<node> q ; 
    q.push(node(x,y,z)) ;  
    while ( !q.empty() ) {
        node tmp = q.front() ; 
        q.pop() ; 
        for ( int i = 0 ; i < 6 ; i++ ) {
            int xx = tmp.x + xyz[0][i] ; 
            int yy = tmp.y + xyz[1][i] ; 
            int zz = tmp.z + xyz[2][i] ; 
            if ( xx >= 0 && xx < l && yy >= 0 && yy < m && zz >= 0 && zz < n  && matrix[xx][yy][zz] == 1 ) {
                matrix[xx][yy][zz] = 0 ; 
                num++ ; 
                q.push(node(xx,yy,zz)) ; 
            }
        }        
    }
    if ( num >= t ) 
        res += num ; 
}

int main() {
    int i, j, k ; 
    cin >> m >> n >> l >> t ;
    for ( i = 0 ; i < l ; i++ ) 
        for ( j = 0 ; j < m ; j++ ) 
            for ( k = 0 ; k < n ; k++ ) 
                cin >> matrix[i][j][k] ;     
    for ( i = 0 ; i < l ; i++ ) 
        for ( j = 0 ; j < m ; j++ ) 
            for ( k = 0 ; k < n ; k++ ) 
                if ( matrix[i][j][k] == 1 ) 
                    count(i,j,k) ;    
    cout << res << endl ; 
    return 0 ; 
}