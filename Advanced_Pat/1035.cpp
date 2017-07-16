#include<iostream>
#include<string>
using namespace std ;
struct node {

    string name ; // 真的好奇怪,为什么 设为char name[10] 和password[10] 再用scanf("%s%s",name,passowrd) name 会变成name + password , 为什么啊,非得用string???  
    string password ;
} ;

int main (){

    int n , i ; 
    scanf("%d",&n) ;
    struct node *p = new struct node [n] ;
    int out = 0 ;
    int mark[n] = {0} ;
    for ( i = 0 ; i < n ; i++ ) {
    
        cin >> p[i].name >> p[i].password ; 
    }

    for ( i = 0 ; i < n ; i++ ){
    
        for ( int j = 0 ; j < 10 ; j++ ) {
        
            switch ( p[i].password[j]) {
            
                case '1' : p[i].password[j] = '@' ;
                          mark[i] = 1 ;  break ;
                case '0' : p[i].password[j] = '%' ;
                          mark[i] = 1 ;  break ;
                case 'l' : p[i].password[j] = 'L' ;
                          mark[i] = 1 ;  break ;
                case 'O' : p[i].password[j] = 'o' ; 
                          mark[i] = 1 ;  break ;
            }
        } 
    }

    int sum = 0;
    
    for ( i = 0 ; i < n ; i++){
    
        if ( mark[i] != 0 ){
        
            sum++ ;
        }
    }

    if ( sum == 0 ){
    
        if ( n == 1 ){
        
            printf("There is 1 account and no account is modified") ;
        }
        else {
        
            printf("There are %d accounts and no account is modified",n) ;
        }
        return 0 ; 
    }

    printf("%d\n",sum) ;
    
    for ( i = 0 ; i < n ; i++ ){
    
        if ( mark[i] != 0 ){
        
            cout << p[i].name << " " << p[i].password << endl ; 
        }
    }
    return 0 ; 
}
