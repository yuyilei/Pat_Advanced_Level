#include<iostream>
#include<map> 
#include<vector>
#include<algorithm>
using namespace std ; 

const int len = 26*26*26 + 26*26 + 26 ; 
vector<int> Time[len] ; 
vector<int> Sum(len,0) ; 
vector<int> heads ; 
vector<bool> visited (len,false) ; 
vector<int> gang ; 
map<int,string> mapp ; 
int n, k ; 

struct node {
    int head, num ; 
    node(int a, int b) : head(a), num(b) {} 
} ; 

bool cmp(struct node a, struct node b) {
    return mapp[a.head] < mapp[b.head] ; 
}

int Hash(string name) {
    return 26*26*(name[0]-'A') + 26*(name[1]-'A') + name[2]-'A' ; 
}

void dfs(int now ) {
    if ( visited[now] == true ) 
        return ; 
    visited[now] = true ; 
    for ( int i = 0 ; i < Time[now].size() ; i++ ) 
        dfs(Time[now][i]) ; 
    gang.push_back(now) ; 
}

int isGang(vector<int> gang) {
    if ( gang.size() <= 2 )  
        return -1 ; 
    int res = gang[0] ; 
    int sum = 0 ; 
    for ( int i = 0 ; i < gang.size() ; i++ ) {
        sum += Sum[gang[i]] ; 
        if ( Sum[res] < Sum[gang[i]] ) 
            res = gang[i] ; 
    }
    if ( sum/2 > k ) 
        return res ; 
    return -1 ; 
}

int main() {
    int i, j, t, intname1, intname2 ; 
    cin >> n >> k ; 
    string name1 , name2 ; 
    vector<struct node> res ; 
    for ( i = 0 ; i < n ; i++ ) {
        cin >> name1 >> name2 >> t ; 
        intname1 = Hash(name1) ; 
        intname2 = Hash(name2) ; 
        Time[intname1].push_back(intname2) ; 
        Sum[intname1] += t ; 
        Sum[intname2] += t ; 
        mapp[intname1] = name1 ; 
        mapp[intname2] = name2 ; 
        heads.push_back(intname1) ; 
    }

    for ( i = 0 ; i < heads.size() ; i++ ) {
        gang.clear() ; 
        dfs(heads[i]) ; 
        int head = isGang(gang) ; 
        if ( head == -1 )
            continue ;  
        res.push_back(node(head,gang.size())) ; 
    }

    sort(res.begin(),res.end(),cmp) ; 
    cout << res.size() << endl ; 
    for ( i = 0 ; i < res.size() ; i ++ ) 
        cout << mapp[res[i].head] << " " << res[i].num << endl ; 
    return 0 ; 
}
