#include<cstdio>
#include<iostream>
#include<cstring>
#define M 100
#define inf 0x3f3f3f3f
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,cap,cost,next;
    }e[M<<6];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int cap,int cost){
        e[en].u=u;e[en].v=v;e[en].cap=cap;e[en].cost=cost;e[en].next=head[u];head[u]=en++;
        e[en].u=v;e[en].v=u;e[en].cap=0;  e[en].cost=-cost;e[en].next=head[v];head[v]=en++;
    }
}g1;
int dis[M],pp[M];
bool vis[M];
int stk[M],top;
int spfa(int sp,int tp){
    memset(dis,inf,sizeof(dis));
    memset(vis,1,sizeof(vis));
    memset(pp,-1,sizeof(pp));
    top=-1;dis[sp]=0;
    stk[++top]=sp;
    while(top>=0){
        int u=stk[top--];
//        printf("%d!!!!\n",u);
        for(int i=g1.head[u];~i;i=g1.e[i].next){
            int v=g1.e[i].v;
            int cost=g1.e[i].cost;
            if(g1.e[i].cap>0){
                if(dis[v]>dis[u]+cost){
                    dis[v]=dis[u]+cost;
                    pp[v]=i;
                    if(vis[v]){
                        vis[v]=0;
                        stk[++top]=v;
                    }
                }
            }
        }
        vis[u]=1;
    }
    if(dis[tp]==inf) return 0;
    return 1;
}
int mcmf(int sp,int tp){
    int tmax=0;
    int mincost=0,flow=0;
    while(spfa(sp,tp)){
//        puts("!!!");
        int minflow=inf;
        int next;
        for(int i=pp[tp];~i;i=pp[next]){
            minflow=min(minflow,g1.e[i].cap);
            next=g1.e[i].u;
        }
        for(int i=pp[tp];~i;i=pp[next]){
            g1.e[i].cap-=minflow;
            g1.e[i^1].cap+=minflow;
            next=g1.e[i].u;
        }
        mincost+=dis[tp]*minflow;
        flow+=minflow;
    }
//    printf("flow is %d\n",flow);
    return mincost;
}
int map1[M][M];
int num1[20000];
int num2[20000];
int build(){
    int sp=0,tp=26*2+1;
    g1.init();
    for(int i=1;i<=26;i++){
        g1.add(sp,i,1,0);
        g1.add(i+26,tp,1,0);
    }
    for(int i=1;i<=26;i++){
        for(int j=1;j<=26;j++){
            if(map1[i][j]){
                g1.add(i,j+26,1,-map1[i][j]);
            }
        }
    }
    int ans=mcmf(sp,tp);
    return ans;
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            int n,m,k;scanf("%d%d%d",&n,&k,&m);
            char str[10];
            for(int i=0;i<n;i++){
                scanf("%s",str);int t1=str[0]-'A'+1;
                num1[i]=t1;
            }
            for(int i=0;i<m;i++){
                memset(map1,0,sizeof(map1));
                for(int j=0;j<n;j++){
                    scanf("%s",str);int t1=str[0]-'A'+1;
                    map1[num1[j]][t1]++;
                }
                int ans=-build();
                printf("%.4lf\n",(ans*1.0)/n);
            }
        }
    }
    return 0;
}
