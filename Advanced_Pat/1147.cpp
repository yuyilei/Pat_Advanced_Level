#include<vector>
#include<cstdio>
using namespace std ; 

vector<int> heap ; 
vector<int> post ; 
int m, indexs ; 

int judge(int flag ) {
    int res = 1 ; 
    if ( flag == 1 ) {
        for ( int i = 1 ; i <= m/2 ; i++ ) {
            int left = 2*i, right = 2*i+1 ; 
            if ( (heap[left] > heap[i]) || (right <= m && heap[right] > heap[i] )) {
                res = 0 ;
                break ; 
            }
        }  
    }
    else {
        for ( int i = 1 ; i <= m/2 ; i++ ) {
            int left = 2*i, right = 2*i+1 ; 
            if ( (heap[left] < heap[i]) || (right <= m && heap[right] < heap[i] )) {
                res = 0 ;
                break ; 
            }
        }  
    }
    return res ; 
}

void post_order(int now) {
    post.push_back(heap[now]) ; 
    if ( 2*now+1 <= m ) 
        post_order(2*now+1) ;  
    if ( 2*now <= m ) 
        post_order(2*now) ; 
}
 
int main() {
    int i, j, n ;
    scanf("%d %d",&n,&m) ; 
    heap.resize(m+1) ; 
    post.resize(m+1) ; 
    for ( i = 0 ; i < n ; i++ ) {
        int res = 0 ; 
        heap.clear() ; 
        post.clear() ; 
        for ( j = 1 ; j <= m ; j++ ) {
            scanf("%d",&heap[j]) ; 
        }
        if ( heap[1] < heap[2] ) { 
            res = judge(0) ;  
            if ( res ) {
                printf("Min Heap\n") ; 
            }
            else 
                printf("Not Heap\n") ; 
        }
        else { 
            res = judge(1) ;
            if ( res ) {
                printf("Max Heap\n") ; 
            }
            else 
                printf("Not Heap\n") ; 
        }  
        post.clear() ; 
        post_order(1) ; 
        for ( j = m-1 ; j >= 0 ; j-- ) {
            printf("%d",post[j]) ; 
            if ( j != 0 ) 
                printf(" ") ; 
        }
        printf("\n") ; 
    }
    return 0 ; 
}