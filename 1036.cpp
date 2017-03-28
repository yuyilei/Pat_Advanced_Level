#include<iostream>
#include<algorithm>
using namespace std ;

struct st{

    string name ; 
    string classes ;
    int grade ;
} ;

int cmp ( struct st a , struct st b ){

    return a.grade > b.grade ;
}

int main () {

    int n ,i ;
    cin >> n ; 
    struct st *m = new struct  st [n] ;
    struct st *f = new struct  st [n] ;
    int gm = 0 , gf = 0 ;
    for ( i = 0 ; i < n ; i ++){
    
        string name1 , sex1 , class1 ;
        int grade1 ;
        cin >> name1 >> sex1 >> class1 >> grade1 ;
        if ( sex1 == "M"){
        
            m[gm].name = name1 ;
            m[gm].classes = class1 ;
            m[gm++].grade = grade1 ;
        }

        else {
        
            f[gf].name = name1 ;
            f[gf].classes = class1 ;
            f[gf++].grade = grade1 ;
        }
    }

    sort(m,m+gm,cmp) ;
    sort(f,f+gf,cmp) ;
    int flag = 0 ;
    if ( gf == 0 ){
    
        cout << "Absent" << endl ;
        flag = 1 ; 
    }
    else {
    
        cout << f[0].name<<" "<<f[0].classes <<endl ;
    }
    if ( gm == 0){
    
        cout << "Absent" << endl ;
        flag = 1 ;
    }
    else {
    
        cout << m[gm-1].name<<" "<<m[gm-1].classes <<endl ;
    }
    if ( flag ){
    
        cout << "NA" << endl ;
    }
    else {
    
        cout << f[0].grade - m[gm-1].grade << endl ;
    }

    return 0 ;


}
