#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

const int MX = 1e6;
const int MN = 19;
int dis[MX];
vector< int > number;
queue< int >  q1;
int n,m;

void init(){
   number.clear();
   while(!q1.empty()) q1.pop();
}
void bfs(){
    memset(dis, -1, sizeof(dis));
    dis[0] = 0;
    q1.push(0);
    while(!q1.empty()){
        int u = q1.front(); q1.pop();
        for(int i = 0; i < number.size(); i++){
            int v = number[i];
            int next = v ^ u;
            if(dis[next] == -1){
                dis[next] =  dis[u] + 1;
                q1.push(next);
            }
        }
        for(int i = 0; i < MN; i++){
            int v = 1 << i;
            int next = v ^ u;
            if(dis[next] == -1){
                dis[next] =  dis[u] + 1;
                q1.push(next);
            }
        }
    }
    
}
void solve(){
    init();
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        int tmp; cin>>tmp;
        number.push_back(tmp);
    }
    bfs();
    long long ans = 0;
    for(int i = 1; i <= m; i++) {
       int u,v; scanf("%d%d",&u,&v);
       long long tmp = dis[u ^ v];
       //cout<<tmp<<endl;
       ans += tmp * (long long)i;
    }
    cout<<ans<<endl;
}
int main(){
    int cas; cin>>cas;
    while(cas--){
        solve();
    }
    return 0;
}

