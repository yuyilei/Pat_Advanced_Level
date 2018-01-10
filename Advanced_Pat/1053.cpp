#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
struct node {
    int isleaf, *nums, num ; 
    node() : isleaf(1) {} 
} ; 
int n, m, key ; 
int keys[101] = {0} ; 
struct node *tree = new struct node [101] ; 

bool cmp (int a, int b) {
    return keys[a] > keys[b] ; 
} 

void getres(int rindex, int value, vector<int> &tmp) {
    if ( value == 0 ) {
        if ( tree[rindex].isleaf == 0 )
            return ;
        int len = tmp.size() ; 
        for ( int i = 0 ; i < len ; i++ ) 
            cout << tmp[i] << ( (i != len -1 ) ? " " : "\n" ) ; 
        return ; 
    }
    for ( int i = 0 ; i < tree[rindex].num ; i++ ) {
        int key = keys[tree[rindex].nums[i]] ; 
        if ( ( value - key ) < 0 ) 
            continue ;  
        tmp.push_back(key) ; 
        getres(tree[rindex].nums[i],value-key,tmp) ; 
        tmp.pop_back() ; 
    }
}

int main() {
    int i, j, r, k ; 
    cin >> n >> m >> key ;
    for ( i = 0 ; i < n ; i++ ) 
        cin >> keys[i] ; 
    for ( i = 0 ; i < m ; i++ ) {
        cin >> r >> k ; 
        tree[r].isleaf = 0 ; 
        tree[r].nums = new int [k] ; 
        tree[r].num = k ; 
        for ( j = 0 ; j < k ; j++ ) 
            cin >> tree[r].nums[j] ; 
        sort(tree[r].nums,tree[r].nums+k,cmp) ; 
    }
    vector<int> tmp ; 
    tmp.push_back(keys[0]) ; 
    getres(0,key-keys[0],tmp) ; 
    return 0 ; 
}