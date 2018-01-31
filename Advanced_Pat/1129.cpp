#include<set> 
#include<iostream>
using namespace std ; 

struct node {
    int num, count ; 
    node(int n, int c) : num(n),count(c) {}
    bool operator < (const node &a)const{       // 重载符号，插入set的时候，自动进行非递增的排序 
        if ( count != a.count ) 
            return count > a.count ; 
        return num < a.num ; 
    }
} ; 

int mapp[50001] = {0} ; 
int main() {
    int n, k, t ; 
    cin >> n >> k >> t ; 
    set<node> sett ; 
    sett.insert(node(t,1)) ; 
    mapp[t] = 1 ; 
    for ( int i = 1 ; i < n ; i++ ) {
        cin >> t ; 
        cout << t << ":" ; 
        set<node>:: iterator it = sett.begin() ; 
        for ( int now = 0 ; now < k && it != sett.end() ; it++ , now++ ) 
            cout << " " << it->num ; 
        cout << endl ; 
        if ( (it = sett.find(node(t,mapp[t]))) != sett.end() )  
            sett.erase(it) ; 
        mapp[t]++ ; 
        sett.insert(node(t,mapp[t])) ; 
    } 
    return 0 ; 
}