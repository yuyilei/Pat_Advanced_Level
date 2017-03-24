#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

int main() { 

    int n , m ;
    cin >> n >> m ; 
    vector<vector<int> > family(n+1) ; // 要比它的数量多一,否则报错 
    int k ;
    int i ;
    int root = 1 ; // 默认1是根结点 
    queue<int> one ; // 队列里面是一代人

    for ( i = 0 ; i < m ; i++) {
    
        int parent ;
        cin >> parent >> k ;
        for ( int j = 0 ; j < k ; j++ ) {
            int child ;        
            cin >> child ;
            family[parent].push_back(child) ;
          //  cout << child << endl ; 
        }  
    }

    one.push(root) ; // 放入根结点,即祖先
    int max = 1 ;
    int maxlevel = 1 ;
    int level = 1 ;
    
    while (!one.empty()) {  // 还有下一代
        
        int size = one.size() ; // 这个地方巨坑,后面one的大小会改变,所以一定要先用一个变量去存它,不要直接使用one.szie() 
        if ( size > max ){
        
            max = one.size() ;
            maxlevel = level ;
        }
        for ( int j = 0 ; j < size ; j++ ){
            int that = one.front() ; // 取出这个人  
            one.pop() ; // 销毁这个人 
            for ( vector<int>::iterator iter = family[that].begin() ; iter != family[that].end() ; iter++) {
                one.push((*iter)) ;  // 在队列中加入他的后代
             //   cout << *iter << " " << level << endl ;
            }
        }
        level++ ;
    }  

    cout << max << " " << maxlevel ;
    return 0 ;
}

