#include<cstdio>
#include<cstring>
#include<iostream>
#define M 150033
#define lson (rt<<1)
#define rson (rt<<1|1)
#define inf 0x3f3f3f3f
#define ll int
using namespace std;
struct G{
    ll head[M],en;
    struct E{
        ll u,v,next,cost;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(ll u,ll v,ll cost){
        e[en].u=u;e[en].v=v;e[en].cost=cost;e[en].next=head[u];head[u]=en++;
    }
}g1;
struct T{
    struct E{
        ll l,r,tmax,tmin,lazy;
    }e[M<<2];
    ll value[M];
    void push_up(ll rt){
        e[rt].tmax=e[lson].tmax+e[rson].tmax;
    }
    void push_down(ll rt){
       ;
    }
    void build(ll l,ll r,ll rt){
        e[rt].l=l;e[rt].r=r;e[rt].tmax=0;
        e[rt].tmin=inf;
        e[rt].lazy=0;
        if(l==r){
            e[rt].tmax=value[l];
            return ;
        }
        ll mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
        push_up(rt);
    }
    void update1(ll ul,ll new_flag,ll rt){
        if(e[rt].l==ul&&e[rt].r==ul){
            e[rt].tmax=new_flag;
            e[rt].tmin=new_flag;
            e[rt].lazy=0;
            return ;
        }
        push_down(rt);
        ll mid=(e[rt].l+e[rt].r)>>1;
        if(ul<=mid) update1(ul,new_flag,lson);
        else update1(ul,new_flag,rson);
        push_up(rt);
    }
    void update2(ll ul,ll ur,ll rt){
       ;
    }
    ll query(ll ul,ll ur,ll rt){
        if(ul<=e[rt].l&&ur>=e[rt].r){
            return e[rt].tmax;
        }
        ll ans=0;
        push_down(rt);
        ll mid=(e[rt].l+e[rt].r)>>1;
        if(ur<=mid) ans=query(ul,ur,lson);
        else if(ul>mid) ans=query(ul,ur,rson);
        else{
            ll t1=query(ul,ur,lson);
            ll t2=query(ul,ur,rson);
            ans=t1+t2;
        }
        push_up(rt);
        return ans;
    }
}tr;
ll my_que[M<<2],top[M],son[M],en,sz[M],fa[M],dep[M],hash[M],value[M];
void build_tree(){
    ll l=0,r=-1;
    my_que[++r]=1;
    dep[1]=1;
    sz[0]=0;
    fa[1]=0;
    while(l<=r){
        ll u=my_que[l++];son[u]=0;sz[u]=1;
        for(ll i=g1.head[u];i!=-1;i=g1.e[i].next){
            ll v=g1.e[i].v;
            if(v==fa[u]) continue;
            fa[v]=u;
            value[v]=g1.e[i].cost;
            dep[v]=dep[u]+1;
            my_que[++r]=v;
        }
    }
    for(ll i=r;i>=0;i--){
        ll u=my_que[i];
        for(ll j=g1.head[u];j!=-1;j=g1.e[j].next){
            ll v=g1.e[j].v;
            if(v==fa[u]) continue;
            sz[u]+=sz[v];
            if(sz[son[u]]<sz[v]) son[u]=v;
        }
    }
    for(ll i=0;i<=r;i++){
        ll u=my_que[i];
        if(son[fa[u]]==u) top[u]=top[fa[u]];
        else top[u]=u;
    }
}
void re_build(ll n){
    en=1;
    for(ll i=1;i<=n;i++){
        if(top[i]!=i) continue;
        hash[i]=en;
        tr.value[en++]=value[i];
        for(ll j=i;j;j=son[j]){
            if(son[j]==0) continue;
            hash[son[j]]=en;
            tr.value[en++]=value[son[j]];
        }
    }
    tr.build(1,en,1);
}
void work(ll n){
    build_tree();
    re_build(n);
}
void change(ll l,ll new_flag){
    ll u=g1.e[(l<<1)-1].u;
    ll v=g1.e[(l<<1)-1].v;
    if(dep[v]<dep[u]) swap(u,v);
    tr.update1(hash[v],new_flag,1);
}
ll query(ll x,ll y){
    ll ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans=ans+tr.query(hash[top[x]],hash[x],1);
        x=fa[top[x]];
    }
    if(x==y) return ans;
    if(dep[y]<dep[x]) swap(x,y);
    ans=ans+tr.query(hash[son[x]],hash[y],1);
    return ans;
}
int main(){
    ll n,m;
    ll sp;
    ll cas;while(~scanf("%d%d%d",&n,&m,&sp)){
        {
            g1.init();
            for(ll i=0;i<n-1;i++){
                ll u,v,cost;scanf("%d%d%d",&u,&v,&cost);
                g1.add(u,v,cost);
                g1.add(v,u,cost);
            }
            work(n);
            char str[100];
            while(m--){
                scanf("%s",str);
//                if(str[0]=='D') break;
                if(str[0]=='1'){
                    ll t1,t2;scanf("%d%d",&t1,&t2);
                    change(t1,t2);
                }
                if(str[0]=='0'){
                    ll t1;scanf("%d",&t1);
                    ll ans=query(sp,t1);
                    printf("%d\n",ans);
                    sp=t1;
                }
            }
        }
    }
    return 0;
}
/*
1

3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 3
QUERY 1 2
Ne  2 3
Q 2 3
DONE



2 10
1 2 1
1 1 2
0 1 2
1 2 1
*/
