#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MV 20000
#define ME 600000
#define ll long long
using namespace std;
struct G{
    ll head[MV],en;
    struct E{
        ll u,v,next,cost;
    }e[ME];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(ll u,ll v,ll cost){
        e[en].u=u;e[en].v=v;e[en].cost=cost;e[en].next=head[u];head[u]=en++;
    }
}g1;
ll dis[MV];
queue<int> q1;
ll vis[MV];
ll relax(ll v,ll u,ll cost){
    if(dis[v]>dis[u]+dis[cost]){
        dis[v]=dis[u]+dis[cost];
        return 1;
    }
    return 0;
}
ll spfa(ll n){
    while(!q1.empty()) q1.pop();
    for(ll i=1;i<=n;i++){
        q1.push(i);
        vis[i]=1;
    }
    while(!q1.empty()){
        ll u=q1.front();q1.pop();
        for(ll i=g1.head[u];i!=-1;i=g1.e[i].next){
            ll v=g1.e[i].v;
            ll cost=g1.e[i].cost;
            if(relax(v,u,cost)&&!vis[i]){
                vis[i]=1;
                q1.push(v);
            }
        }
        vis[u]=0;
    }
}
int main(){
    freopen("dwarf.in","r",stdin);
    freopen("dwarf.out","w",stdout);
    ll n,m;while(~scanf("%I64d%I64d",&n,&m)){
        for(ll i=1;i<=n;i++){
            scanf("%I64d",&dis[i]);
        }
        g1.init();
        for(ll i=0;i<m;i++){
            ll u,v,cost;
            scanf("%I64d%I64d%I64d",&v,&u,&cost);
            g1.add(u,v,cost);
            g1.add(cost,v,u);
        }
        spfa(n);
        printf("%I64d\n",dis[1]);
    }
    return 0;
}
