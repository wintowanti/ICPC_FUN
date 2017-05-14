#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MX 12
using namespace std;
struct XY{
    int x,y;
    int cost;
    int flag;
    XY(int x,int y,int cost, int flag);
};
XY::XY(int x,int y,int cost, int flag){
        this->x = x;
        this->y = y;
        this->cost = cost;
        this->flag = flag;
}
int o[4][2]={ 0,1, 0,-1, 1,0, -1,0 };
char map[MX][MX];
bool ok[MX][MX][2];
int n,m,d,r;
int is_out(int x,int y){
    if(x < 0 || y < 0 || x > n -1 || y > m -1) return 0;
    return 1;
}
int main(){
    cin>>n>>m>>d>>r;
    for(int i = 0; i <n; i++) scanf("%s",map[i]);
    memset(ok, 0, sizeof(ok));
    queue<XY> queue1;
    queue1.push(XY(0,0,0,0));
    while(!queue1.empty()){
        XY now = queue1.front();
        queue1.pop();
        if(now.x == n-1 && now.y == m-1){
            cout<<now.cost<<endl;
            return 0;
        }
        for(int i = 0; i < 4; i++){
            int xx = now.x + o[i][0];
            int yy = now.y + o[i][1];
            if(is_out(xx, yy) && map[xx][yy]=='.'){
                if(ok[xx][yy][now.flag]) continue;
                ok[xx][yy][now.flag] = true;
                XY next(xx, yy, now.cost+1, now.flag);
                queue1.push(next);
            }
        }
        if(now.flag == 0){
            int xx = now.x + d;
            int yy = now.y + r;
            if(is_out(xx, yy) && map[xx][yy]=='.'){
                if(ok[xx][yy][1]) continue;
                ok[xx][yy][1] = true;
                XY next(xx, yy, now.cost+1, 1);
                queue1.push(next);
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}
