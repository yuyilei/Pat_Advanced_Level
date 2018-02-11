#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std ; 

struct ONE {
    int id, fid, mid, sets, area ; 
    int cid[6] ; 
} one[1001] ;  

int father[10001] ;
struct NODE {
    int id, num, flag ; 
    double sets, area ; 
} node[10001] ; 

int tell[10001] = {0} ; 

int root(int a) {
    if ( a != father[a] ) 
        father[a] = root(father[a]) ; 
    return father[a] ; 
}

void Union(int a, int b) {
    int x = root(a) ; 
    int y = root(b) ; 
    if ( x > y ) 
        father[x] = y ; 
    else if ( x < y ) 
        father[y] = x ; 
}

bool cmps(NODE a, NODE b) {
    if ( a.area != b.area ) 
        return a.area > b.area ; 
    return a.id < b.id ; 
}

int main() {
    int n, m, k, i, j, t, res = 0 ; 
    cin >> n ; 
    for ( i = 0 ; i < 10001 ; i++ ) 
        father[i] = i ; 
    for ( i = 0 ; i < n ; i++ ) {
        cin >> one[i].id >> one[i].fid >> one[i].mid >> k ; 
        tell[one[i].id] = 1 ; 
        if ( one[i].fid != -1 ) {
            tell[one[i].fid] = 1 ; 
            Union(one[i].fid,one[i].id) ; 
        }
        if ( one[i].mid != -1 ) {
            tell[one[i].mid] = 1 ; 
            Union(one[i].mid,one[i].id) ; 
        }
        for ( j = 0 ; j < k ; j++ ) {
            cin >> one[i].cid[j] ; 
            tell[one[i].cid[j]] = 1 ; 
            Union(one[i].cid[j],one[i].id) ; 
        }
        cin >> one[i].sets >> one[i].area ; 
    }
    for ( i = 0 ; i < n ; i++ ) {
        int r = root(one[i].id) ; 
        node[r].id = r ; 
        node[r].sets += one[i].sets ; 
        node[r].area += one[i].area ; 
        node[r].flag = 1 ; 
    }
    for ( i = 0 ; i < 10001 ; i++ ) {
        if ( tell[i] ) 
            node[root(i)].num++ ; 
        if ( node[i].flag  )  
            res++ ; 
    }
    
    for ( i = 0 ; i < 10001 ; i++ ) {
        if ( node[i].flag == 1 ) {
            node[i].area = (double)(1.0*node[i].area/node[i].num) ; 
            node[i].sets = (double)(1.0*node[i].sets/node[i].num) ; 
        }
    }
    sort(node,node+10001,cmps) ; 
    cout << res << endl ; 
    for ( i = 0 ; i < res ; i++ ) 
        printf("%04d %d %.3lf %.3lf\n",node[i].id,node[i].num,node[i].sets,node[i].area) ; 
    return 0 ; 
}