#include<cstdio>
#include<cstring>
#include<iostream>
#define M 50000
#define lson (rt<<1)
#define rson (rt<<1|1)
#define inf 0x3f3f3f3f
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next,cost;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int cost){
        e[en].u=u;e[en].v=v;e[en].cost=cost;e[en].next=head[u];head[u]=en++;
    }
}g1;
struct T{
    struct E{
        int l,r,tsum,lazy;
    }e[M<<2];
    int value[M];
    void push_down(int rt){
        int num=e[rt].r-e[rt].l+1;
        if(e[rt].lazy){
            e[lson].lazy+=e[rt].lazy;
            e[rson].lazy+=e[rt].lazy;
            e[lson].tsum+=e[rt].lazy;
            e[rson].tsum+=e[rt].lazy;
        }
        e[rt].lazy=0;
    }
    void build(int l,int r,int rt){
        e[rt].l=l;e[rt].r=r;e[rt].lazy=0;e[rt].tsum=0;
        if(l==r){
            e[rt].tsum=value[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
    }
    void update(int ul,int ur,int new_flag,int rt){
        if(ul<=e[rt].l&&ur>=e[rt].r){
            e[rt].tsum+=new_flag;
            e[rt].lazy+=new_flag;
            return ;
        }
        push_down(rt);
        int mid=(e[rt].r+e[rt].l)>>1;
        if(ur<=mid) update(ul,ur,new_flag,lson);
        else if(ul>mid ) update(ul,ur,new_flag,rson);
        else{
            update(ul,ur,new_flag,lson);
            update(ul,ur,new_flag,rson);
        }
    }
    int query(int ul,int rt){
        if(ul==e[rt].l&&ul==e[rt].r){
            return e[rt].tsum;
        }
        push_down(rt);
        int mid=(e[rt].l+e[rt].r)>>1;
        if(ul<=mid) return query(ul,lson);
        else if(ul>mid) return query(ul,rson);
    }
}tr;
int my_que[M<<2],top[M],son[M],en,sz[M],fa[M],dep[M],hash[M],value[M];
void build_tree(){
    int l=0,r=-1;
    my_que[++r]=1;
    dep[1]=1;
    sz[0]=0;
    fa[1]=0;
    while(l<=r){
        int u=my_que[l++];son[u]=0;sz[u]=1;
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            if(v==fa[u]) continue;
            fa[v]=u;
            dep[v]=dep[u]+1;
            my_que[++r]=v;
        }
    }
    for(int i=r;i>=0;i--){
        int u=my_que[i];
        for(int j=g1.head[u];j!=-1;j=g1.e[j].next){
            int v=g1.e[j].v;
            if(v==fa[u]) continue;
            sz[u]+=sz[v];
            if(sz[son[u]]<sz[v]) son[u]=v;
        }
    }
    for(int i=0;i<=r;i++){
        int u=my_que[i];
        if(son[fa[u]]==u) top[u]=top[fa[u]];
        else top[u]=u;
    }
}
void re_build(int n){
    en=1;
    for(int i=1;i<=n;i++){
        if(top[i]!=i) continue;
        for(int j=i;j;j=son[j]){
            hash[j]=en;
            tr.value[en++]=value[j];
        }
    }
    tr.build(1,en,1);
}
void work(int n){
    build_tree();
    re_build(n);
}
void update(int x,int y,int new_flag){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        tr.update(hash[top[x]],hash[x],new_flag,1);
        x=fa[top[x]];
    }
    if(dep[y]<dep[x]) swap(x,y);
    tr.update(hash[x],hash[y],new_flag,1);
}
int query(int x){
    int ans=tr.query(hash[x],1);
    return ans;
}
int main(){
    int n,m,q;
    while(~scanf("%d%d%d",&n,&m,&q)){
        for(int i=1;i<=n;i++) scanf("%d",&value[i]);
        g1.init();
        for(int i=0;i<m;i++){
            int u,v;scanf("%d%d",&u,&v);
            g1.add(u,v,0);
            g1.add(v,u,0);
        }
        work(n);
        for(int i=0;i<q;i++){
            char str[100];
            scanf("%s",str);
            if(str[0]=='Q'){
                int u;scanf("%d",&u);
                int ans=query(u);
                printf("%d\n",ans);
            }
            else if(str[0]=='I'){
                int u,v,cost;scanf("%d%d%d",&u,&v,&cost);
                update(u,v,cost);
            }
            else{
                int u,v,cost;scanf("%d%d%d",&u,&v,&cost);
                update(u,v,-cost);
            }
        }
    }
    return 0;
}
