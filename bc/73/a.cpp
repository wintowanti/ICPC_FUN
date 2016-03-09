#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MX = 108;
vector< pair<int, int> > graph[MX];
int can[MX];
int vis[MX];
int n;
int ans = 0;
void dfs(int u){
    vis[u] = 1;
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i].first;
        int id = graph[u][i].second;
        if(can[id] == 0 && vis[v] == 0){
            dfs(v);
        }
    }
}
int judge(){
    memset(vis,0,sizeof(vis));
    dfs(1);
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i]) count ++;
    }
    if(count == n) return 1;
    return 0;
}
void good(int start,int level){
    if(level > 1) return ;
    for(int i = start; i < n +1; i++){
        can[i] = 1;
        if(judge()){
            ans++;
            good(i+1,level +1);
        }
        can[i] = 0;
    }
}
void solve(){
    scanf("%d",&n);
    for(int i = 0; i < n + 1; i++) graph[i].clear();
    ans = 0;
    for(int i = 0; i < n+1; i++){
        int u,v; scanf("%d%d",&u,&v);
        graph[u].push_back( make_pair(v,i) );
        graph[v].push_back( make_pair(u,i) );
    }
    memset(can,0,sizeof(can));
    good(0,0);
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
