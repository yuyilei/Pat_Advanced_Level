#include<iostream>
#include<string> //  使用string头文件可以让字符串相加
#include<map>
#include<cctype>
using namespace std ;
int main() {
    string in , temp ;
    getline(cin,in) ;
    int i , j , t , res = 0 ;
    map < string , int >  num  ;
    for ( j = 0 , i = 0 ; j != in.length() ; j++ ) {
        if ( isalnum(in[j]) ) { // 判断是否是数字和字母
            temp += tolower(in[j]) ;
        }
        else {
            if ( temp.length() != 0   )
                num[temp]++ ;
            temp = "" ;
        }
    }
    if ( temp.length() != 0 ) // 把最后一个单词加上去
        num[temp]++ ;
    for ( map<string, int>::iterator t = num.begin() ; t != num.end() ; t++ ) {
        if ( (*t).second > res ) { // map 默认以key为升序排列
            res = (*t).second ;
            temp = (*t).first ;
        }
    }
    cout << temp << " " << res <<  endl ;
}
