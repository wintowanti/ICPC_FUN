/*
lca tanjan Ωdfs £®n+q£©(1)
vijos 1427
*/
#include<cstdio>
#include<cstring>
#define M 200080
#define ll long long
struct G{
    ll head[M],en=0;
    struct E{
        ll u,v,next,cost;
    }e[M];
    void init(){
        memset(head,-1,sizeof(head));
    }
    void add(ll u,ll v,ll cost){
        e[en].u=u;e[en].v=v;e[en].cost=cost;
        e[en].next=head[u];head[u]=en++;
    }
}g1,g2;
ll flag[M],fa[M],ma[M];
ll findfa(ll x){
    if(x==fa[x]) return x;
    return fa[x]=findfa(fa[x]);
}
void yy_union(ll x,ll y){
    ll fa1=findfa(x);
    ll fa2=findfa(y);
    fa[fa2]=fa1;
}
ll tnum,tsum;
ll dis[M];
void lca(ll u){
    fa[u]=ma[u]=u;
    for(ll i=g1.head[u];i!=-1;i=g1.e[i].next){
        ll v=g1.e[i].v;
        lca(v);
        yy_union(u,v);
        ma[findfa(v)]=u;
    }
    flag[u]=1;
    for(ll i=g2.head[u];i!=-1;i=g2.e[i].next){
        ll v=g2.e[i].v;
        if(flag[v]){
            ll fa1=findfa(v);
            if(ma[fa1]==u){
              //  printf("%d   %d \n",u,v);
                tnum++;
                tsum+=dis[v]-dis[u];
            }
        }
    }
}
bool is_root[M];
void dfs(ll u,ll step){
    dis[u]=step;
    for(ll i=g1.head[u];i!=-1;i=g1.e[i].next){
        ll v=g1.e[i].v;
        ll cost=g1.e[i].cost;
        dfs(v,step+cost);
    }
}
int main(){
    ll n,m;while(~scanf("%I64d%I64d",&n,&m)){
        memset(is_root,1,sizeof(is_root));
        memset(flag,0,sizeof(flag));
        g1.init();g2.init();
        for(ll i=0;i<n-1;i++){
            ll t1,t2,t3;scanf("%I64d%I64d%I64d",&t1,&t2,&t3);
            g1.add(t1,t2,t3);
            is_root[t2]=0;
        }
        for(ll i=0;i<m;i++){
            ll t1,t2;
            scanf("%I64d%I64d",&t1,&t2);
            g2.add(t1,t2,1ll);
        }
        ll root;
        for(ll i=1;i<=n;i++){
            if(is_root[i]){
                root=i;break;
            }
        }
     //   printf("%d ~~~\n",root);
        dfs(root,0);
        lca(root);
        printf("%I64d\n",tnum);
        printf("%I64d\n",tsum);
    }
    return 0;
}
