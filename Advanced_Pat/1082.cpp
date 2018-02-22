#include<cstring>
#include<iostream>
#include<cstdio>
#include<vector> 
using namespace std ; 

string num2chinese[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"} ; 
string weishu[9] = {"","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi"} ; 

// 感觉这题超烦的。。。。本来分4位4位。。但是那个0感觉好麻烦。。。
// 借鉴了别人的代码。。但是那个人的代码有点问题。。。。
int main() {
    long num, tmp ; 
    int i, j, t, len, f0 = 0, index ; 
    vector<int> dig ; 
    vector<string> res ; 
    cin >> num ; 
    if ( num == 0 ) {
        cout << "ling" << endl ; 
        return 0 ; 
    }
    if ( num < 0 ) {
        cout << "Fu " ; 
        num = -num ; 
    }
    while ( num ) {
        dig.push_back(num%10) ; 
        num /= 10 ; 
    }
    len = dig.size() ; 
    for ( index = 0 ; index < len && dig[index] == 0 ; index++ ) ;     // 从低位开始找第一个不为0的位。。。 
    if ( index > 4 && index != 8 )                                     // 如果从低位开始第一个不为0的位在万位之前，且不是亿位，需要手动加一个“万” 
        res.push_back("Wan") ; 
    for ( i = index ; i < len ; i++ ) {
        if ( i != 0 && ( dig[i] != 0 || i == 4 || i == 8 ) ) {         // 不是个位，此位不是0，或者是万位或亿位，加入位数 
            res.push_back(weishu[i]) ; 
        }
        res.push_back(num2chinese[dig[i]]) ; 
    }
    for ( i = res.size() - 1 ; i >= 0 ; i-- ) {
        if ( i != res.size() - 1 ) 
            cout << " " ; 
        int flag = 0 ; 
        while ( i >= 0 && res[i] == "ling" ) {                          // 收缩相邻的0
            i-- ; 
            flag = 1 ; 
        }
        if ( flag && res[i] != "Wan")                                   // 万位和亿位之前0要忽略，这里不会出现亿位的情况  
            cout << "ling " ; 
        cout << res[i] ; 
    }
    cout << endl ; 
    return 0 ; 
}