#include<cstdio>
#include<cstring>
using namespace std ; 

int n, indexnot01 = -1, indexnot02 = -1, indexpoint1 = -1, indexpoint2 = -1; 
int k1, k2 ; 

/*
关键就是找出第一个非零的数，以及小数点的位置。 
*/

void deal(char t[], int &index1, int &index2, int &k) {
    for ( index1 = 0 ; index1 < strlen(t) ; index1++ ) {          // 找第一个非0数
        if ( t[index1] != '.' && t[index1] != '0' ) {
            break ; 
        }
    }
    for ( index2 = 0 ; index2 < strlen(t) ; index2++ ) {           // 找小数点
        if ( t[index2] == '.' ) {
            break ; 
        }
    }
    if ( index1 == strlen(t) )                                      // 这个数是0，所以把k设为0 
        k = 0 ;
    else if ( index1 < index2 )                                     // k为 正数
        k = index2 - index1 ; 
    else if  ( index1 > index2 )                                    // k 为负数, 要减去小数点的影响 
        k = index2 - index1 + 1 ; 
} 

void printit(char t[], int index1, int index2, int k) {
    printf("0.") ; 
    int i, num = 0 ; 
    for ( i = index1 ; i < strlen(t) && num < n ; i++ ) {            
        if ( t[i] != '.') {                                            // 输出的时候消除小数点的影响 
            printf("%c",t[i]) ; 
            num++ ; 
        } 
    }
    while ( num < n ) {                                                // 不够的位数，补0 
        printf("0") ; 
        num++ ; 
    }
    printf("*10^%d",k) ; 
}

int main() {
    int i, j, k1, k2, flag = 0, t ; 
    char a[110], b[110] ; 
    scanf("%d %s %s",&n,a,b) ; 
    deal(a,indexnot01,indexpoint1,k1) ; 
    deal(b,indexnot02,indexpoint2,k2) ; 
    i = indexnot01; j = indexnot02; t = 0 ; 
    flag = ( k1 == k2 ) ? 0 : 1 ; 
    while ( k1 == k2 && t < n && i < strlen(a) && j < strlen(b) ) {                 // 位数和基数都相同时，才算相等 
        if ( a[i] != b[j] ) {
            flag = 1 ; 
        }
        i++ ; j++ ; t++ ; 
    } 
    printf("%s ",flag?"NO":"YES") ; 
    if ( !flag ) {
        printit(a,indexnot01,indexpoint1,k1) ; 
    }
    else {
        printit(a,indexnot01,indexpoint1,k1) ; 
        printf(" ") ; 
        printit(b,indexnot02,indexpoint2,k2) ; 
    }
    printf("\n") ; 
    return 0 ; 
}