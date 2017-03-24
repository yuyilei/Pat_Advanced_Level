#include<stdio.h>
int main() {

    // 啊,我写不出来,我觉得这题要用我没学过的数据结构!!!!!
    // 果然啊,树的遍历!!! , 寻找最大的结点和层数!!!
    // 我还是先去看看树是怎么回事吧!!!! QAQ !!  
    int man[100][100] ; 
    int n , m ;
    mamset(man,0,10000 * sizeof(int)) ;
    int fk[100] ;
    memset(fk,0,100*sizeof(int)) ;
    int fd[100] ;
    memset(fd,0,100*sizeof(int)) ;
    scanf("%d%d",&n,&m) ;
    int i , j ;
    int k , d  ;
    int sum[100] , level[100] ;
    int flag[100] ;
    memset(flag,2,100*sizeof(int)) ; //flag 为2是初始值 , flag 为1表示有后代,为0表示没后代
    memset(sum,1,100*sizeof(int)) ;
    memset(level,0,100*sizeof(int)) ;

    for ( i = 0 ; i < m ; i++) {
    
        scanf("%d%d",&k,&d) ;
        fk[k] = k ;         // 用来记录k的数组
        fd[k] = d ;         // 记录d的数值
        fd[k] = 1 ;
        for ( j = 0 ; j < d ; j++){
            scanf("%d",&man[k][j]) ;
        }
    }

    // 去除没有后代的人, 计算每个有子女的人的当代人数总和
    for ( i = 0 ; i < 100 ; i++ ){
    
        if ( flag[i] == 1 ){      // 有下一代     
            sum[i] += fd[i] ;  // 加上他的下一代 
            for ( j = 0 ; j < fd[i] ; j++) {
                int this = man[i][j] ;
                if ( man[this][0] == 0 ){  // 他的下一代绝后了
                    flag[this] = 0 ;
                }
            }
        }
    }
    
    for ( i = 0 ; i < 100 ; i++) {
    
        if ( flag[i] == 1 ) {
        
            level[i] = 2 ; // 有后代,就有2代
        }
    }

    for ( i = 0 ; i < 100 ; i++) {
    
      
    }
}
