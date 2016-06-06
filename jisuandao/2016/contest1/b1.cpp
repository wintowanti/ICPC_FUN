#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MX = 50000;

int n;
int ans;
int value[MX];
vector<int> graph[MX];
int gcd(int a, int b){
    if(b > 0){
        return gcd(b, a%b);
    }
    return a;
}
void dfs(int start,int u, int fa, int level){
    if(start != u){
        if(gcd(value[start], value[u]) == 1) ans += level;
    }
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(v != fa){
            dfs(start, v, u, level + 1);
        }
    }
}
void solve(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&value[i]),graph[i].clear();
    for(int i = 1; i < n; i++){
        int u,v; scanf("%d%d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ans = 0;
    for(int i = 1; i <= n; i++) dfs(i, i,-1, 0);
    cout<<ans/2<<endl;
}
int main(){
    solve();
    return 0;
}
