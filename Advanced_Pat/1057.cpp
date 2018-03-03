#include<cstdio>
#include<iostream>
#include<stack>
#include<vector>
using namespace std ; 

// 感觉有点难啊，借助了别人的代码
// stack 不是重点，重点是在一个数据流中获取一个中位数，10^5的数据量比较大，如果每次pop或push都进行排序，或维持一个有序的数列会超时。 
// 原本的想法是维持一个count[100001] 的数组，进入一个t，就让count[t]++ ，反之则，count[t]-- ，获取size个数字中的中位数时，就是获取前缀和为 (size+1)/2 的位置的下标。
// 但是每次求取count数组的前缀和也会超时，所有就引入一个“树状数组“的概念。
// 树状数组(Binary Indexed Tree(B.I.T), Fenwick Tree)是一个查询和修改复杂度都为log(n)的数据结构。
// 主要用于查询任意两位之间的所有元素之和，但是每次只能修改一个元素的值；经过简单修改可以在log(n)的复杂度下进行范围修改。 
// 所以，下面这个tree就是一个树状数组。 

struct node {
    stack<int> s ; 
    int num ; 
} ; 

int tree[100005] = {0} ; 

int lowbit(int x) {
    return x & (-x) ; 
} 

void update_nodes(int index, int value) {                              // tree[index] 处的元素 + value，在log(n)的时间复杂度下，更新tree数组 
    for ( int i = index ; i < 100005 ; i += lowbit(i) ) {
        tree[i] += value ; 
    }
}

int getsum(int right) {                                                // 利用树状数组tree 计算 原数组中 [1-right]
    int res = 0 ; 
    for ( int i = right ; i >= 1 ; i -= lowbit(i) ) 
        res += tree[i] ; 
    return res ; 
}

int getmid(int size) { 
    int index = (size+1)/2 ; 
    int left = 1, right = 100000, mid ; 
    while ( left != right ) {                                            // 二分查找  
        mid = ( left+right ) / 2 ;
        if ( getsum(mid) >= index )                                      // getsum(mid) == index 不代表找到这个点了，因为前缀可能会相等（中间有点为0）  
            right = mid ;                                                // 只有 left == right 才说明找到这个点了  
        else 
            left = mid + 1 ; 
    } 
    return left ;                                                        // 此left满足 tree[left] >= index && tree[left-1] < index  
}

int main() {
    int n, i, j, t ; 
    scanf("%d",&n) ; 
    struct node one ; 
    char input[12] ; 
    one.num = 0 ;  
    for ( i = 0 ; i < n ; i++ ) {
        scanf("%s",input) ; 
        if ( input[1] == 'o' ) {
            if ( one.num == 0 ) {
                printf("Invalid\n") ; 
                continue ; 
            }
            t = one.s.top() ; 
            one.s.pop() ; 
            printf("%d\n",t) ; 
            one.num-- ; 
            update_nodes(t,-1) ; 
        }  
        else if ( input[1] == 'e' ) {
            if ( one.num == 0 ) {
                printf("Invalid\n") ; 
                continue ; 
            } 
            int index = getmid(one.num) ; 
            printf("%d\n",index) ; 
        } 
        else if ( input[1] == 'u' ) {
            cin >> t ; 
            one.s.push(t) ; 
            one.num++ ; 
            update_nodes(t,1) ; 
        }
    }
    return 0 ; 
}