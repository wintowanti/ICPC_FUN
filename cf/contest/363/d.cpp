#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;
const int MX = 10000000;
int pa[MX];
int vis[MX];
vector< int > ans;
int dfs(int u,int flag){
    vis[u] = flag;
    if(vis[pa[u]] == flag) return u;
    if(vis[pa[u]] != 0) return -1;
    if(vis[pa[u]] == 0) return dfs(pa[u], flag);
}
int main(){
    int n;
    cin>>n;
    memset(vis, 0 ,sizeof(vis));
    int flag = -1;
    for(int i = 1; i <= n; i++){
        scanf("%d",&pa[i]);
        if(pa[i] == i) flag = pa[i];
    }
    ans.clear();
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
           int tmp = dfs(i, i);
           if(tmp != -1){
               ans.push_back(tmp);
           }
        }
    }
    if(flag != -1) printf("%d\n", ans.size() -1);
    else printf("%d\n", ans.size());
    if(flag == -1) flag = ans[0];
    for(int i = 0; i < ans.size(); i++){
        pa[ans[i]] = flag;
    }
    for(int i = 1; i <= n; i++){
        if(i == 1) printf("%d",pa[i]);
        else printf(" %d",pa[i]);
    }
    puts("");
    return 0;
}

