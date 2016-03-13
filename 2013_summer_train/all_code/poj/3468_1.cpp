#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#define M 1050002
#define N 20050
#define inf 0x3f3f3f3f
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
struct G{
    int head[N],en;
    struct E{
        int u,v,cap,next;
    }e[M];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int cap){
        e[en].u=u;e[en].v=v;e[en].cap=cap;e[en].next=head[u];head[u]=en++;
        e[en].u=v;e[en].v=u;e[en].cap=0  ;e[en].next=head[v];head[v]=en++;
    }
}g1;
int dis[N],dinic_sp,dinic_tp,cur[N];
int my_que[N];
int bfs(){
    int hp=0,tp=-1;
    my_que[++tp]=dinic_sp;
    memset(dis,0,sizeof(dis));
    dis[dinic_sp]=1;
    while(hp<=tp){
        int u=my_que[hp++];
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            if(!dis[v]&&g1.e[i].cap>0){
                dis[v]=dis[u]+1;
                my_que[++tp]=v;
            }
        }
    }
   return dis[dinic_tp];
}
int dfs(int u,int tmax){
    if(u==dinic_tp||tmax==0){
        return tmax;
    }
    int tsum=0,f;
    for(int  & i=cur[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(dis[v]==dis[u]+1&& (f=dfs(v,min(tmax,g1.e[i].cap)))){
            g1.e[i].cap-=f;
            g1.e[i^1].cap+=f;
            tmax-=f;
            tsum+=f;
            if(!tmax) break;
        }
    }
    return tsum;
}
int dinic(int sp,int tp){
    dinic_sp=sp;dinic_tp=tp;
    int tsum=0;
    while(bfs()){
        for(int i=0;i<=tp;i++) cur[i]=g1.head[i];
        tsum+=dfs(sp,inf);
    }
    return tsum;
}
int main() {
    int sp,tp;
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        int sp=0,tp=n+1;
        g1.init();
        for(int i=1;i<=n;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            g1.add(sp,i,t1);
            g1.add(i,tp,t2);
        }
        for(int i=0;i<m;i++){
            int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);
            g1.add(t1,t2,t3);
        }
        int ans=dinic(sp,tp);
        printf("%d\n",ans);
    }
    return 0;
}

/*
2 2
1 2 2
1 2 3
9 6
1 2 5
1 3 7
1 4 4
2 3 1
2 6 3
3 4 2
3 5 5
3 6 4
4 5 4
*/
