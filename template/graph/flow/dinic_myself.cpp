#include<cstdio>
#include<iostream>
#include<cstring>
#define MV 10000
#define ME 100000
#define mt(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
using namespace std;
struct D{
    int head[MV],en;
    struct E{
        int u,v,cap,next;
    }e[ME];
    void init(){
        mt(head,-1);en=0;
    }
    void add(int u,int v,int cap){
        e[en].u=u;e[en].v=v;e[en].cap=cap;e[en].next=head[u];head[u]=en++;
        e[en].u=v;e[en].v=u;e[en].cap=0;  e[en].next=head[v];head[v]=en++;
    }
    int cur[MV],dis[MV],my_que[MV],dinic_sp,dinic_tp;
    int bfs(){
        mt(dis,0);
        dis[dinic_sp]=1;
        int hp=0,tp=-1;
        my_que[++tp]=dinic_sp;
        while(hp<=tp){
            int u=my_que[hp++];
            for(int i=head[u];i!=-1;i=e[i].next){
                int v=e[i].v;
                if(dis[v]) continue;
                if(e[i].cap==0) continue;
                dis[v]=dis[u]+1;
                my_que[++tp]=v;
            }
        }
        return dis[dinic_tp];
    }
    int dfs(int u,int tmax){
        if(u==dinic_tp||tmax==0) return tmax;
        int flow=0,f;
        for(int & i=cur[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(dis[v]==dis[u]+1&&e[i].cap>0){
                f=min(e[i].cap,tmax);
                f=dfs(v,f);
                e[i].cap-=f;
                e[i^1].cap+=f;
                tmax-=f;
                flow+=f;
                if(!tmax) break;
            }
        }
        return flow;
    }
    int Get_Flow(int sp,int tp){
        dinic_sp=sp,dinic_tp=tp;
        int ans=0;
        int t1;
        while(bfs()){
            for(int i=0;i<=tp;i++) cur[i]=head[i];
            ans+=dfs(sp,inf);
        }
        return ans;
    }
}dinic;
int main(){
    int m,n;while(~scanf("%d%d",&m,&n)){
        int sp=0,tp=n+1;
        dinic.init();
        dinic.add(sp,1,inf);
        dinic.add(n,tp,inf);
        for(int i=0;i<m;i++){
            int u,v,cap;scanf("%d%d%d",&u,&v,&cap);
            dinic.add(u,v,cap);
        }
        int ans=dinic.Get_Flow(sp,tp);
        printf("%d\n",ans);
    }
    return 0;
}
