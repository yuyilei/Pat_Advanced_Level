#include<cstdio>
#include<algorithm>
#include<cstring> 
#include<vector> 
using namespace std ; 

typedef struct node {
    char name[10] ; 
    int age, net_worth ; 
} node ; 

bool cmp( node a, node b ) {
    if ( a.net_worth != b.net_worth )   
        return a.net_worth > b.net_worth ; 
    if ( a.age != b.age ) 
        return a.age < b.age ; 
    return strcmp(a.name,b.name) < 0 ; 
}

int main() {
    int n, k, i, j, t, m, maxx , minn ; 
    scanf("%d %d",&n,&k) ; 
    vector<node> people (n) ; 
    for ( int i = 0 ; i < n ; i++ ) 
        scanf("%s %d %d",people[i].name,&people[i].age,&people[i].net_worth) ; 
    sort(people.begin(),people.end(),cmp) ; 
    for ( int i = 0 ; i < k ; i++ ) {
        scanf("%d %d %d",&m,&minn,&maxx) ; 
        printf("Case #%d:\n",i+1) ; 
        int count  = 0 ; 
        for ( int j = 0 ; count < m && j < n ; j++ ) {
            if ( people[j].age > maxx || people[j].age < minn ) 
                continue ; 
            count++ ; 
            printf("%s %d %d\n",people[j].name,people[j].age,people[j].net_worth) ; 
        }
        if ( count == 0 ) 
            printf("None\n") ; 
    }
    return 0 ; 
}
