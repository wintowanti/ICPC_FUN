#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#define M 1000000
#define N 58080
#define inf 0x3f3f3f3f
#define ll int
using namespace std;
ll min(ll x,ll y){
    if(x>y) return y;return x;
}
struct G{
    ll head[N],en;
    struct E{
        ll u,v,cap,next;
    }e[M];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(ll u,ll v,ll cap){
        e[en].u=u;e[en].v=v;e[en].cap=cap;e[en].next=head[u];head[u]=en++;
        e[en].u=v;e[en].v=u;e[en].cap=0  ;e[en].next=head[v];head[v]=en++;
    }
}g1;
ll dis[N],dinic_sp,dinic_tp;
ll bfs(){
    queue<int> q1;
    q1.push(dinic_sp);
    memset(dis,-1,sizeof(dis));
    dis[dinic_sp]=0;
    while(!q1.empty()){
        ll u=q1.front();q1.pop();
        for(ll i=g1.head[u];i!=-1;i=g1.e[i].next){
            ll v=g1.e[i].v;
            if(dis[v]==-1&&g1.e[i].cap>0){
                dis[v]=dis[u]+1;
                q1.push(v);
            }
        }
    }
    if(dis[dinic_tp]==-1) return 0;
    return 1;
}
ll dfs(ll u,ll tmax){
    if(u==dinic_tp){
        return tmax;
    }
    ll tsum=0;
    for(ll i=g1.head[u];i!=-1;i=g1.e[i].next){
        ll v=g1.e[i].v;
        if(dis[v]==dis[u]+1&&g1.e[i].cap>0){
            ll t1=min(g1.e[i].cap,tmax-tsum);
            t1=dfs(v,t1);
            g1.e[i].cap-=t1;
            g1.e[i^1].cap+=t1;
            tsum+=t1;
        }
    }
    return tsum;
}
ll dinic(ll sp,ll tp){
    dinic_sp=sp;dinic_tp=tp;
    ll tsum=0;
    while(bfs()){
        tsum+=dfs(sp,inf);
    }
    return tsum;
}
int main(){
    ll n,m;
    ll tsum=0;
    ll sp,tp;
    while(~scanf("%d%d",&m,&n)){
        g1.init();
        ll sp=0;tp=n+1;
        g1.add(sp,1,inf);
        g1.add(n,tp,inf);
        for(ll i=0;i<m;i++){
            ll u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            g1.add(u,v,cost);
//            g1.add(v,u,cost);
        }
        ll ans=dinic(sp,tp);
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
