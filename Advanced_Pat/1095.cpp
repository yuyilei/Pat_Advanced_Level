#include<cstdio>
#include<map>
#include<algorithm>
#include<vector> 
#include<iostream> 
using namespace std ; 

struct record {
    int status, time ; 
    string name ;  
    record (string a, int b, int c) :name(a), status(b), time(c) {} 
    bool operator < (const record& other) const {
        return time < other.time ; 
    }
} ; 

struct timequery {
    int num, time ; 
    timequery (int b, int c) : num(b), time(c) {}  
    bool operator < ( const timequery& other ) const {
        return time < other.time ; 
    }
} ; 

struct car {
    int valid, intime, outtime, sum ; 
    string name ;  
    car() :  valid(0), intime(-1), outtime(-1), sum(0) {}   
    bool operator < ( const car & other ) const {
        return sum > other.sum ; 
    }
} ; 

typedef struct record record ; 
typedef struct timequery timequery ;
typedef struct car car ; 

int main() {
    int i, j, k, t, n, hh, mm, ss ; 
    string tmpname, status ; 
    map<string,car> mapp ;  
    cin >> n >> k ; 
    vector<record> r ; 
    vector<timequery> tq ; 
    vector<car> cars ; 
    vector<string> carname ; 
    for ( i = 0 ; i < n ; i++ ) {
        cin >> tmpname ; 
        scanf("%d:%d:%d",&hh,&mm,&ss) ;  
        cin >> status ; 
        t = hh*3600 + mm*60 + ss ;
        j = ( status[0] == 'i' ) ? 1 : 0 ;   
        r.push_back(record(tmpname,j,t)) ; 
    }
    sort(r.begin(),r.end()) ;                                           // 将record以time为主序升序排序 
    for ( i = 0 ; i < n ; i++ ) {
        if ( r[i].status == 1 ) {                                      // 状态为 in 
            if ( mapp.find(r[i].name) == mapp.end() ) {
                car c = car() ; 
                c.name = r[i].name ; 
                c.intime = r[i].time ; 
                mapp[r[i].name] = c ;
            }
            else {
                car &c = mapp[r[i].name] ; 
                c.intime = r[i].time ; 
            }
        }
        else if ( mapp.find(r[i].name) != mapp.end() ) {               // 状态为out，且在这之前有配对的in 
            car &c = mapp[r[i].name] ; 
            c.outtime = r[i].time ; 
            if ( c.intime != -1 && c.intime < c.outtime ) {
                timequery t1 = timequery(1,c.intime) ;                 // 入停车场 
                timequery t2 = timequery(-1,c.outtime ) ;              // 出停车场 
                tq.push_back(t1) ; 
                tq.push_back(t2) ; 
                c.sum += (c.outtime-c.intime) ; 
                c.intime = c.outtime = -1 ;
                c.valid = 1 ; 
            }
        }
    }
    sort(tq.begin(),tq.end()) ;                                        // 将每一个时间节点以time为主序升序排序 
    int index = 0, count = 0 ; 
    for ( i = 0 ; i < k ; i++ ) {                                      // 每个时间是升序输入的，所以可以接着上面一个算 
        scanf("%d:%d:%d",&hh,&mm,&ss) ;                   
        t = hh*3600 + mm*60 + ss ; 
        while ( index < tq.size() && t >= tq[index].time ) {
            count += tq[index].num ; 
            index++ ; 
        } 
        printf("%d\n",count) ; 
    }
    for ( map<string,car> :: iterator it = mapp.begin() ; it != mapp.end() ; it ++ ) {
        if ( it->second.valid == 1 ) 
            cars.push_back(it->second) ;       
    }
    sort(cars.begin(),cars.end()) ;                                      // 将每个有效的车，以sum为主序升序排序 
    int maxx = cars[0].sum ; 
    carname.push_back(cars[0].name) ; 
    index = 1 ; 
    while ( index < cars.size() && cars[index].sum == maxx ) {
        carname.push_back(cars[index].name) ; 
        index++ ; 
    }
    sort(carname.begin(),carname.end()) ;                                // 将停车时间最大的车的名字以字母顺序升序排序  
    for ( i = 0 ; i < carname.size() ; i++ ) 
        cout << carname[i] << " " ; 
    hh = maxx / 3600 ; 
    mm = ( maxx - hh * 3600 ) / 60 ; 
    ss = maxx % 60 ; 
    printf("%02d:%02d:%02d\n",hh,mm,ss) ; 
    return 0 ; 
}
 