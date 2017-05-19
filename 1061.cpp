#include<iostream>
using namespace std ;
int main() {
    char  tmp1 , tmp2 ;
    string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "} , in[4] ;
    int i , j , k = 0 , t = 0 , flag = 0 , day , hours , min ; 
    for ( i = 0 ; i < 4 ; i++ ){
        cin >> in[i] ; 
    }
    for ( ; k < in[0].length() && k < in[1].length() ; k++){
        tmp1 = in[0][k] ; 
        tmp2 = in[1][k] ; 
        if ( flag == 0 && tmp1 >= 'A' && tmp1 <= 'G' && tmp1 == tmp2 ){
            day = tmp1 - 'A' ;
            flag = 1 ;
        }        
        else if ( flag == 1 && tmp1 == tmp2 && ((tmp1 >='0' && tmp1 <= '9') || (tmp1 >='A' && tmp1 <= 'N'))){  
            if ( tmp1 >= '0' && tmp1 <= '9'){
                hours = tmp1 - '0' ;
            }
            else if ( tmp1 >= 'A' && tmp1 <= 'N'){
                hours = tmp1 -'A' + 10  ; 
            }
            break ; 
        }
    }
    for ( k = 0  ; k < in[2].length() && k < in[3].length() ; k++ ){
        tmp1 = in[2][k] ; 
        tmp2 = in[3][k] ;
        if ( (tmp1 == tmp2) && (( tmp1 >= 'a'  && tmp1 <= 'z' ) ||(tmp1 >='A'&& tmp2 <= 'Z'))){
            min = k ; 
            break ; 
        }
    }
    cout << week[day]  ;
    if ( hours >= 0 && hours <= 9 ){
        cout << "0" ; 
    }
    cout << hours << ":" ; 
    if ( min >= 0 && min <= 9 ){
        cout << "0" ;
    }
    cout << min ; 
    return 0 ; 
}
