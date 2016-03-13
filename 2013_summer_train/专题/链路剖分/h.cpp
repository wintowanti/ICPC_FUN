#include<cstdio>
#include<cstring>
#include<iostream>
#define M 40000
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
struct A{
    int tsum,tmax;
    A(){
        tsum=0;
        tmax=-inf;
    }
};
struct T{
    struct E{
        int l,r,tmax,tsum;
    }e[M<<2];
    int value[M];
    void push_up(int rt){
        e[rt].tmax=max(e[lson].tmax,e[rson].tmax);
        e[rt].tsum=e[lson].tsum+e[rson].tsum;
    }
    void build(int l,int r,int rt){
        e[rt].l=l;e[rt].r=r;e[rt].tmax=-inf;e[rt].tsum=0;
        if(l==r){
            e[rt].tmax=value[l];
            e[rt].tsum=value[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
        push_up(rt);
    }
    void update(int ul,int new_flag,int rt){
        if(e[rt].l==ul&&e[rt].r==ul){
            e[rt].tmax=new_flag;
            e[rt].tsum=new_flag;
            return ;
        }
        int mid=(e[rt].l+e[rt].r)>>1;
        if(ul<=mid) update(ul,new_flag,lson);
        else update(ul,new_flag,rson);
        push_up(rt);
    }
    A query(int ul,int ur,int rt){
        if(ul<=e[rt].l&&ur>=e[rt].r){
            A a1;a1.tmax=e[rt].tmax;
            a1.tsum=e[rt].tsum;
            return a1;
        }
        int mid=(e[rt].l+e[rt].r)>>1;
        if(ur<=mid) return query(ul,ur,lson);
        else if(ul>mid) return query(ul,ur,rson);
        else{
            A a1=query(ul,ur,lson);
            A a2=query(ul,ur,rson);
            a1.tmax=max(a1.tmax,a2.tmax);
            a1.tsum+=a2.tsum;
            return a1;
        }
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
void change(int l,int new_flag){
    tr.update(hash[l],new_flag,1);
}
A query(int x,int y){
    A ans,a1;;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        a1=tr.query(hash[top[x]],hash[x],1);
        ans.tmax=max(ans.tmax,a1.tmax);
        ans.tsum+=a1.tsum;
        x=fa[top[x]];
    }
    if(dep[y]<dep[x]) swap(x,y);
    a1=tr.query(hash[x],hash[y],1);
    ans.tmax=max(ans.tmax,a1.tmax);
    ans.tsum+=a1.tsum;
    return ans;
}
int main(){
    int cas;
    int tt=1;
    while(~scanf("%d",&cas)){
        tt=1;
        while(cas--){
            int n;scanf("%d",&n);
            g1.init();
            for(int i=1;i<=n;i++) scanf("%d",&value[i]);
            for(int i=0;i<n-1;i++){
                int u,v;scanf("%d%d",&u,&v);
                u++;v++;
                g1.add(u,v,0);
                g1.add(v,u,0);
            }
            work(n);
            printf("Case %d:\n",tt++);
            int q;scanf("%d",&q);
//            puts("~~~~***~~~~");
            for(int i=0;i<q;i++){
                char str[100];
                scanf("%s",str);
                if(str[0]=='1'){
                    int t1,t2;scanf("%d%d",&t1,&t2);
                    t1++;
                    change(t1,t2);
                }
                else{
                    int t1,t2;scanf("%d%d",&t1,&t2);t1++;t2++;
                    A ans;ans=query(t1,t2);
                    printf("%d\n",ans.tsum);
                }
            }
        }
    }
    return 0;
}
