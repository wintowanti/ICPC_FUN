#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MX = 1e5+10;
int vis[MX];
vector<int>  graph[MX];
int value[MX];
long long max_value[MX];
long long res;
long long dfs(int u){
    if(max_value[u] != -1) return max_value[u];

    long long tmp = 0;
    for(int i = 0; i < graph[u].size();i++){
        int v = graph[u][i];
        long long val = dfs(v);
        tmp = max(tmp,val);
    }
    for(int i = 0; i < graph[u].size();i++){
        int v = graph[u][i];
        long long val = dfs(v);
        res += (tmp - val);
    }

    max_value[u] = value[u]+tmp;
    return max_value[u];
}
int main(){
    int n;
    while(cin>>n){
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n;i++) scanf("%d",&value[i]),graph[i].clear();
        for(int i = 1; i < n; i++){
            int u,v;scanf("%d%d",&u,&v);
            vis[v] = 1;
            graph[u].push_back(v);
        }
        memset(max_value, -1, sizeof(max_value));
        for(int i = 1; i <= n; i++){
            if(vis[i] == 0){
                res = 0;
                dfs(i);
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
