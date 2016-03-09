#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
const int MX = 1e5+8;
const int MOD = 1e9+7;

int dis[6][MX];
vector< int > graph[MX];
queue< int> q1;

int n,m;
int abs(int x){
    if(x < 0) return -x;
    return x;
}

void bfs(int sp,int id){
    memset(dis[id],-1,sizeof(dis[id]));
    while(!q1.empty()) q1.pop();
    q1.push(sp);
    dis[id][sp] = 0;
    while(!q1.empty()){
        int u = q1.front();q1.pop();
        for(int i = 0; i < graph[u].size(); i++){
            int v =graph[u][i];
            if(dis[id][v] == -1){
                dis[id][v] = dis[id][u] + 1;
                q1.push(v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i = 0; i <= n; i++) graph[i].clear();
    for(int i = 1; i < n; i++){
        graph[i].push_back(i+1);
        graph[i+1].push_back(i);

    }
    int u1,u2,u3,v1,v2,v3;
    scanf("%d%d",&u1,&v1); graph[u1].push_back(v1);graph[v1].push_back(u1);
    scanf("%d%d",&u2,&v2); graph[u2].push_back(v2);graph[v2].push_back(u2);
    scanf("%d%d",&u3,&v3); graph[u3].push_back(v3);graph[v3].push_back(u3);
    bfs(u1,0);
    bfs(u2,1);
    bfs(u3,2);
    bfs(v1,3);
    bfs(v2,4);
    bfs(v3,5);
    long long ans = 0;
    for(int i = 1; i <= m; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        long long tmp = abs(u - v);
        for(int j = 0; j < 6; j++){
            if(dis[j][u] + dis[j][v] < tmp) tmp = dis[j][u] + dis[j][v];
        }
        ans += (long long)i * tmp;
        ans %= MOD;
        //cout<<tmp<<endl;
    }
    cout<<ans<<endl;

}
int main(){
    int cas;
    cin>>cas;
    while(cas--){
        solve();
    }
    return 0;
}
