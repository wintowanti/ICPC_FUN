#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define M 200000
#define inf 0x3f3f3f3f
using namespace std;
int ans;
int iid;
struct D{
    int value;
    int fa;
}dp[M][3];
struct G{
    int head[M],en;
    struct E{
        int u,v,next,value;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v,int value){
        e[en].u=u;e[en].v=v;e[en].value=value;e[en].next=head[u];head[u]=en++;
    }
}g1;
void dfs1(int u,int fa){
    dp[u][0].fa=u;
    dp[u][0].value=1;
    D d1;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==fa) continue;
        dfs1(v,u);
        d1=dp[v][0];
        d1.value++;
        d1.fa=v;
        if(d1.value>dp[u][2].value){
            swap(d1,dp[u][2]);
        }
        if(dp[u][2].value>dp[u][1].value){
            swap(dp[u][2],dp[u][1]);
        }
        if(dp[u][1].value>dp[u][0].value){
            swap(dp[u][1],dp[u][0]);
        }
    }
}
void dfs2(int u,int fa,int val){
    int tmax=0;
    int tmp[5];
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==fa) continue;
        int value=g1.e[i].value;
        memset(tmp,0,sizeof(tmp));
        int en=0;
        tmax=dp[v][0].value;
        if(dp[u][0].fa!=v){
            tmp[en++]=dp[u][0].value;
        }
        if(dp[u][1].fa!=v){
            tmp[en++]=dp[u][1].value;
        }
        if(dp[u][2].fa!=v){
            tmp[en++]=dp[u][2].value;
        }
        tmp[en++]=val;
        sort(tmp,tmp+en);
        int t1=tmp[en-1]+tmp[en-2]-1;
        if(tmax<t1) tmax=t1;
        if(tmax*value<ans){
            iid=(i/2)+1;
            ans=tmax*value;
        }
        else if(tmax*value==ans){
            if(iid>(i/2)+1){
                iid=(i/2)+1;
            }
        }
        dfs2(v,u,tmp[en-1]+1);
    }
}
int main(){
    int cas;while(~scanf("%d",&cas)){
       for(int q=0;q<cas;q++){
            int n;scanf("%d",&n);
            for(int i=0;i<=n;i++){
                for(int j=0;j<3;j++){
                    dp[i][j].value=0;
                    dp[i][j].fa=-1;
                }
            }
            g1.init();
            for(int i=0;i<n-1;i++){
                int u,v,cost;scanf("%d%d%d",&u,&v,&cost);
                g1.add(u,v,cost);
                g1.add(v,u,cost);
            }
            dfs1(1,-1);
            ans=inf;
            iid=0;
            dfs2(1,-1,1);
            printf("Case #%d: %d\n",q+1,iid);
        }
    }
    return 0;
}
/*
10
5
1 4 1
1 3 1
5 1 1
2 5 1
*/
