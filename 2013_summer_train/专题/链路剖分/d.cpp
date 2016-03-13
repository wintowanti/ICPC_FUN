#include<cstdio>
#include<cstring>
#include<iostream>
#define M 140000
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
    int tsum,lc,rc;
    A(){
        tsum=0;
        lc=-1;
        rc=-1;
    }
};
struct T{
    struct E{
        int l,r,lc,rc,tsum,lazy;
    }e[M<<2];
    int value[M];
    void push_up(int rt){
        e[rt].lc=e[lson].lc;e[rt].rc=e[rson].rc;
        e[rt].tsum=e[lson].tsum+e[rson].tsum;
        e[rt].tsum-=(e[lson].rc==e[rson].lc);
    }
    void push_down(int rt){
        if(e[rt].lazy){
            e[lson].lc=e[lson].rc=e[lson].lazy=e[rt].lazy;e[lson].tsum=1;
            e[rson].lc=e[rson].rc=e[rson].lazy=e[rt].lazy;e[rson].tsum=1;
        }
        e[rt].lazy=0;
    }
    void build(int l,int r,int rt){
        e[rt].l=l;e[rt].r=r;e[rt].lazy=0;e[rt].tsum=0;
        if(l==r){
            e[rt].lc=e[rt].rc=value[l];
            e[rt].tsum=1;
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
        push_up(rt);
    }
    void update(int ul,int ur,int new_flag,int rt){
        if(ul<=e[rt].l&&ur>=e[rt].r){
            e[rt].lazy=new_flag;
            e[rt].lc=new_flag;
            e[rt].rc=new_flag;
            e[rt].tsum=1;
            return ;
        }
        push_down(rt);
        int mid=(e[rt].l+e[rt].r)>>1;
        if(ur<=mid) update(ul,ur,new_flag,lson);
        else if(ul>mid) update(ul,ur,new_flag,rson);
        else{
            update(ul,ur,new_flag,lson);
            update(ul,ur,new_flag,rson);
        }
        push_up(rt);
    }
    A query(int ul,int ur,int rt){
        if(ul<=e[rt].l&&ur>=e[rt].r){
            A a1;a1.tsum=e[rt].tsum;
            a1.lc=e[rt].lc;a1.rc=e[rt].rc;
            return a1;
        }
        push_down(rt);
        A a1,a2;
        int mid=(e[rt].l+e[rt].r)>>1;
        if(ur<=mid) a1=query(ul,ur,lson);
        else if(ul>mid) a1=query(ul,ur,rson);
        else{
            a1=query(ul,ur,lson);
            a2=query(ul,ur,rson);
            a1.tsum+=a2.tsum-(a1.rc==a2.lc);
            a1.rc=a2.rc;
        }
        push_up(rt);
        return a1;
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
void change(int x,int y,int new_flag){
     while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        tr.update(hash[top[x]],hash[x],new_flag,1);
        x=fa[top[x]];
    }
    if(dep[y]<dep[x]) swap(x,y);
    tr.update(hash[x],hash[y],new_flag,1);
}
int query(int x,int y){
    A ans[2],a1;
    int flag=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y),flag^=1;
        a1=tr.query(hash[top[x]],hash[x],1);
        ans[flag].tsum+=a1.tsum-(ans[flag].lc==a1.rc);ans[flag].lc=a1.lc;
        x=fa[top[x]];
    }
    if(dep[x]<dep[y]) swap(x,y),flag^=1;
    a1=tr.query(hash[y],hash[x],1);
    ans[flag].tsum+=a1.tsum-(ans[flag].lc==a1.rc);ans[flag].lc=a1.lc;
    ans[0].tsum+=ans[1].tsum-(ans[0].lc==ans[1].lc);
    return ans[0].tsum;
}
int main(){
//    tr.build(1,2,1);
//    tr.update(1,1,2,1);
//    tr.update(2,2,3,1);
//    tr.update(1,1,6,1);
//    A ans1=tr.query(2,2,1);
//    printf("%d  %d   %d  %d\n",ans1.lc,ans1.rc,ans1.tsum);
    int n,m;while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=1;i<=n;i++) scanf("%d",&value[i]);
        for(int i=0;i<n-1;i++){
            int u,v;scanf("%d%d",&u,&v);
            g1.add(u,v,0);
            g1.add(v,u,0);
        }
        work(n);
        for(int i=0;i<m;i++){
            char str[100];
            scanf("%s",str);
            if(str[0]=='C'){
                int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);
                change(t1,t2,t3);
            }
            else{
                int t1,t2;scanf("%d%d",&t1,&t2);
                int tt=query(t1,t2);
                printf("%d\n",tt);
            }
        }
    }
    return 0;
}
/*
6 100



2 2 1 2 1 1



1 2



1 3



2 4



2 5



2 6*/
