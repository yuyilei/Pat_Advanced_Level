#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std ;

struct student {

    string name ;
    string id ;
    int grate ;
} ;

int cmp ( struct student a , struct student b ){
    
    return a.grate > b.grate ;
} 

int main () {

    int number ;
    int i ;
    cin >> number ;
    struct student *p = new struct student [number] ;

    for ( i = 0 ; i < number ; i++){
        cin >> p[i].name ;
        cin >> p[i].id ;
        cin >> p[i].grate ;
    }

    int high , low  ;
    cin >> low >> high ;
    sort(p,p+number,cmp) ; 
    int count = 0 ;

    for ( i = 0 ; i < number ; i++) {
    
        if ( p[i].grate >= low && p[i].grate <= high ) {
        
            cout << p[i].name << " " << p[i].id << endl ;
            count ++ ;
        }
    }

    if (count == 0 )
        cout << "NONE" << endl ;
       
    return 0 ; 
}
