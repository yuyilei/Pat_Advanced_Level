// 其实不用建树的2333
#include<iostream>
#include<vector>
using namespace std ; 
vector<int> pre ;
vector<int> in ;
int num ; 

int fistpost(int ps, int pe, int is, int ie ) {
    int index = is ; 
    for (  ; index <= ie ; index++ ) 
        if ( in[index] == pre[ps] )
            break ; 
    int len = index - is ; 
    if ( index != is ) 
        return fistpost(ps+1,ps+len,is,index-1) ;   // 如果左子树存在，postfirst就在左子树上
    if ( index != ie ) 
        return fistpost(ps+len+1,pe,index+1,ie) ;   // 如果左子树不存在，右子树存在，firstpost就在右子树上
    return pre[ps] ;                                // 都不存在， first就是根节点  
}

int main() {
    cin >> num ; 
    pre.resize(num) ;
    in.resize(num) ; 
    for ( int i = 0 ; i < num ; i++ ) 
        cin >> pre[i] ; 
    for ( int i = 0 ; i < num ; i++ ) 
        cin >> in[i] ; 
    cout << fistpost(0,num-1,0,num-1) << endl ; 
    return 0 ;  
}