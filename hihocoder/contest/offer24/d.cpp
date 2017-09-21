#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const int MX = 1e5+10;
int next_p[MX];
int dp[MX];
int n;
int vis[MX];
int change;
int dfs(int u){
    if(u > n) return 0;
    if(vis[u] == change) return dp[MX];
    dp[u] = dfs(next_p[u]) + 1;
    vis[u] = change;
    return dp[u];
}
int main(){
    while(cin>>n){
        for(int i = 1; i <= n; i++){
            int tmp;scanf("%d",&tmp);
            next_p[i] = i + tmp;
        }
        memset(vis, -1, sizeof(vis));
        memset(dp, 0, sizeof(dp));
        int m;cin>>m;
        change = 0;
        for(int i = 0; i < m; i++){
            int flag;scanf("%d",&flag);
            if(flag == 1){
                int u; scanf("%d",&u);
                int res = dfs(u);
                printf("%d\n",res);
            }
            else{
                change++;
                int u,tmp;
                scanf("%d%d",&u,&tmp);
                next_p[u] = u + tmp;
            }
        }
        
    }
    return 0;
}
