#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define M 1030
using namespace std;
int dp[M];
bool can_walk[M];
bool vis[2][M];
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M*M];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;
        e[en].next=head[u];head[u]=en++;
    }
}g1;
int dfs(int x){
//    printf("%d!!!\n",x);
//    system("pause");
    int tmin=1;
    if(dp[x]!=-1) return dp[x];
    for(int i=g1.head[x];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        int t1=dfs(v);
        if(t1<tmin) tmin=t1;
    }
    return dp[x]=!tmin;
}
char str1[2][10]={"wind","lolanv"};
int dfs1(int u,int first){
    if(vis[first][u]==1){
        vis[first][u]=0;
    }else return dp[u];
    int t1=!dp[u];
    if(first==1){
        can_walk[u]=1;
    }
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(dp[v]==t1){
            dfs1(v,!first);
        }
    }
}
int main(){
    int n,m;
//    puts(str1[0]);
//    puts(str1[1]);
    while(~scanf("%d%d",&n,&m)){
        int first;
        memset(dp,-1,sizeof(dp));
        memset(can_walk,0,sizeof(can_walk));
        scanf("%d",&first);
        g1.init();
        for(int i=0;i<m;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            if(t1>t2) swap(t1,t2);
            g1.add(t1,t2);
        }
        int ans=(first+dfs(1)+1)%2;
        puts(str1[ans]);
        memset(vis,1,sizeof(vis));
        dfs1(1,first);
        int pflag=0;
        for(int i=1;i<=n;i++){
            if(dp[i]==first){
                if(pflag) printf(" %d",i);
                else pflag=1,printf("%d",i);
            }
        }
        puts("");
    }
    return 0;
}
/*
10 6
1
1 2
1 3
1 4
2 5
3 6
4 7
*/
