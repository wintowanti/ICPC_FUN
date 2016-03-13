#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#define M 300
using namespace std;
map<string,int> map1;
int dp[M][2];
int mark[M][2];
int en;
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M*M];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int find(char *p){
    if(map1[p]==0){
        map1[p]=en++;
    }
    return map1[p];
}
char str1[M];
char str2[M];
void dfs(int u){
    if(g1.head[u]==-1){
        dp[u][0]=0;
        dp[u][1]=1;
        mark[u][0]=1;
        mark[u][1]=1;
        return ;
    }
    else{
        int flag0=1;
        int flag1=1;
        dp[u][0]=0;
        dp[u][1]=1;
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            dfs(v);
            dp[u][1]+=dp[v][0];
            if(mark[v][0]==0) flag1=0;
            int tmax=max(dp[v][0],dp[v][1]);
            dp[u][0]+=tmax;
            if(dp[v][0]==dp[v][1]) flag0=0;
            if(dp[v][0]==tmax&&mark[v][0]==0) flag0=0;
            if(dp[v][1]==tmax&&mark[v][1]==0) flag0=0;
        }
        mark[u][0]=flag0;
        mark[u][1]=flag1;
        return ;
    }
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        map1.clear();
        en=1;
        scanf("%s",str1);find(str1);
        g1.init();
        for(int i=0;i<n-1;i++){
            scanf("%s%s",str1,str2);
            int t1=find(str1);
            int t2=find(str2);
            g1.add(t2,t1);
        }
        memset(dp,0,sizeof(dp));
        dfs(1);
        int tmax=max(dp[1][0],dp[1][1]);
        int flag=1;
        if(dp[1][0]==dp[1][1]) flag=0;
        if(dp[1][0]==tmax){
            if(mark[1][0]==0) flag=0;
        }
        if(dp[1][1]==tmax){
            if(mark[1][1]==0) flag=0;
        }
        printf("%d ",tmax);
        if(flag){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }
}
