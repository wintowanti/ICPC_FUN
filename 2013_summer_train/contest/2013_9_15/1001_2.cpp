#include<cstdio>
#include<cstring>
#include<iostream>
#define ll int
#define inf 0x3f3f3f3f
#define M 1080
using namespace std;
ll map1[M][M];
struct G{
    ll head[M],en;
    struct E{
        ll u,v,next,cost;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(ll u,ll v,ll cost){
        e[en].u=u;e[en].v=v;e[en].cost=cost;e[en].next=head[u];head[u]=en++;
    }
}g1;
int pre[M],low[M],subid[M],dfs_clock,sub_num,is_cut[M],is_brige[M*M*5];
int stk[M],top;
void init(){
    memset(pre,-1,sizeof(pre));
    memset(is_cut,0,sizeof(is_cut));
    memset(is_brige,0,sizeof(is_brige));
    dfs_clock=0;sub_num=0;
    top=-1;
}
void dfs(int u,int id){
    pre[u]=low[u]=++dfs_clock;
    stk[++top]=u;
    int child=0;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        if((i^1)==id) continue;
        int v=g1.e[i].v;
        child++;
        if(pre[v]==-1){
            dfs(v,i);
            if(low[v]<low[u]) low[u]=low[v];
            if(low[v]>pre[u]){
                is_brige[i]=1;
            }
            if(low[v]>=pre[u]){
                is_cut[u]++;
            }
        }
        else{
            if(pre[v]<low[u]) low[u]=pre[v];
        }
    }
    if(pre[u]==low[u]){
        sub_num++;
        while(top>=0){
            int t1=stk[top--];
            subid[t1]=sub_num;
            if(t1==u) break;
        }
    }
    if(child==1&&id==-1) is_cut[u]=0;
}
int tarjan(int n){
    init();
    for(int i=1;i<=n;i++){
        if(pre[i]==-1){
            dfs(i,-1);
        }
    }
    return sub_num;
}
ll fa[M];
ll find_fa(ll u){
    if(u==fa[u]) return fa[u];
    return fa[u]=find_fa(fa[u]);
}
void un(ll u,ll v){
    ll fa1=find_fa(u);
    ll fa2=find_fa(v);
    fa[fa2]=fa1;
}
ll mark;
int main(){
//    printf("%I64d\n",3300000000000ll);
    ll n,m;while(~scanf("%d%d",&n,&m)&&(n+m)){
        for(ll i=0;i<=n;i++) fa[i]=i;
        g1.init();
        memset(map1,-1,sizeof(map1));
        mark=map1[0][0];
        for(ll i=0;i<m;i++){
            ll u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            un(u,v);
            if(v<u) swap(u,v);
            if(map1[u][v]==-1){
                map1[u][v]=cost;
            }
            else{
                if(cost<map1[u][v]) map1[u][v]=cost;
//                map1[u][v]+=cost;
            }
            g1.add(u,v,cost);
            g1.add(v,u,cost);
        }
//        for(ll i=1;i<=n;i++){
//            for(ll j=i+1;j<=n;j++){
//                if(map1[i][j]!=-1){
////                    printf("%I64d!!   %I64d!\n",i,j);
//                    g1.add(i,j,map1[i][j]);
//                    g1.add(j,i,map1[i][j]);
//                }
//            }
//        }
        ll flag=0;
        for(ll i=1;i<=n;i++){
            if(fa[i]==i){
                flag++;
            }
        }
        if(flag>1){
            puts("1");
        }
        else{
            tarjan(n);
            ll tmin=inf;
            int flag=0;
            for(ll i=0;i<g1.en;i+=2){
                if(is_brige[i]==1){
                    flag=1;
                    if(g1.e[i].cost<tmin) tmin=g1.e[i].cost;
                }
                if(is_brige[i+1]==1){
                    flag=1;
                    if(g1.e[i+1].cost<tmin) tmin=g1.e[i+1].cost;
                }
            }
            if(flag==0){
                puts("-1");
            }
            else{
                if(tmin==0) tmin=1;
                printf("%d\n",tmin);
            }
        }
    }
    return 0;
}
/*
5 6
1 3 2
1 3 1
2 3 3
3 4 4
3 5 5
4 5 6
1 2 4
*/
