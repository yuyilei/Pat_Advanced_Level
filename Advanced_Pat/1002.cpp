#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std ;

struct node {

    float exponent ;
    float coefficient ;
}  ;

int cmp(struct node a , struct node b) {

    return a.exponent > b.exponent ;
}

int main () {
    
    vector<node> out ; 
    int n1 , n2 ;
    cin >> n1 ;
    struct node *p1 = new struct node [n1] ;

    for ( int i = 0 ; i < n1 ; i++){
    
        cin >> p1[i].exponent >> p1[i].coefficient ;
    } 

    cin >> n2 ;
    struct node *p2 = new struct node [n2] ;

    for ( int i = 0 ; i < n2 ; i++){
    
        cin >> p2[i].exponent >> p2[i].coefficient ;
    } 

    sort(p1,p1+n1,cmp) ; // 按照指数进行降序排序
    sort(p2,p2+n2,cmp) ;
    
    int index1 = 0 ;
    int index2 = 0 ;
    
    while (  index1 < n1 && index2 < n2 ){
    
        if (p1[index1].exponent > p2[index2].exponent ) {
        
            out.push_back(p1[index1++]) ; 
        }

        else if ( p1[index1].exponent < p2[index2].exponent ){
        
            out.push_back(p2[index2++]) ;
        }
        else {
        
            p1[index1].coefficient += p2[index2].coefficient ;
            if (p1[index1].coefficient != 0 ){  // 若等于0,则不用加入数组
                out.push_back(p1[index1]) ;
            }
            index1++ ;
            index2++ ;
        }
    }

    while ( index1 < n1 ) {  // 加入末尾的元素
    
        out.push_back(p1[index1++]) ;
    }
    while (index2 < n2 ) {
    
        out.push_back(p2[index2++]) ;
    }

    cout << out.size()  ; 
    for ( vector<node>::iterator it = out.begin() ; it != out.end() ; it++ ){
        cout << " " << (*it).exponent ;
        printf(" %.1f",(*it).coefficient) ; 
    }
    return 0 ; 
}
