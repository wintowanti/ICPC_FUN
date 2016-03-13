#include<cstdio>
#include<cstring>
#include<iostream>
#define M 20000
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
        int l,r,tmax;
    }e[M<<2];
    int value[M];
    void push_up(int rt){
        e[rt].tmax=max(e[lson].tmax,e[rson].tmax);
    }
    void build(int l,int r,int rt){
        e[rt].l=l;e[rt].r=r;e[rt].tmax=0;
        if(l==r){
            e[rt].tmax=value[l];
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
            return ;
        }
        int mid=(e[rt].l+e[rt].r)>>1;
        if(ul<=mid) update(ul,new_flag,lson);
        else update(ul,new_flag,rson);
        push_up(rt);
    }
    int query(int ul,int ur,int rt){
//        printf("%d   %d_____\n",ul,ur);
        if(ul<=e[rt].l&&ur>=e[rt].r){
            return e[rt].tmax;
        }
        int mid=(e[rt].l+e[rt].r)>>1;
        if(ur<=mid) return query(ul,ur,lson);
        else if(ul>mid) return query(ul,ur,rson);
        else{
            int t1=query(ul,ur,lson);
            int t2=query(ul,ur,rson);
            return max(t1,t2);
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
            value[v]=g1.e[i].cost;
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
        hash[i]=en;
        tr.value[en++]=value[i];
        for(int j=i;j;j=son[j]){
            if(son[j]==0) continue;
            hash[son[j]]=en;
            tr.value[en++]=value[son[j]];
        }
    }
//    for(int i=1;i<=n;i++){
//        printf("%d  fa is %d   son is %d  top is  %d  hash is  %d  size is %d \n",i,fa[i],son[i],top[i],hash[i],sz[i]);
//    }
    tr.build(1,en,1);
}
void work(int n){
    build_tree();
    re_build(n);
}
void change(int l,int new_flag){
    int u=g1.e[(l<<1)-1].u;
    int v=g1.e[(l<<1)-1].v;
    if(dep[v]<dep[u]) swap(u,v);
    tr.update(hash[v],new_flag,1);
}
int query(int x,int y){
    int ans=-inf;
    while(top[x]!=top[y]){
//        printf("%d  %d    %d   %d  **\n",x,y,top[x],top[y]);
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
//        puts("^^^^^^");
//        printf("%d   %d  \n",top[x],x);
        ans=max(ans,tr.query(hash[top[x]],hash[x],1));
        x=fa[top[x]];
    }
    if(x==y) return ans;
    if(dep[y]<dep[x]) swap(x,y);
    ans=max(ans,tr.query(hash[son[x]],hash[y],1));
    return ans;
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            int n;scanf("%d",&n);
            g1.init();
            for(int i=0;i<n-1;i++){
                int u,v,cost;scanf("%d%d%d",&u,&v,&cost);
                g1.add(u,v,cost);
                g1.add(v,u,cost);
            }
//            puts("~~~~~");
            work(n);
            char str[100];
            while(1){
                scanf("%s",str);
                if(str[0]=='D') break;
                if(str[0]=='C'){
                    int t1,t2;scanf("%d%d",&t1,&t2);
                    change(t1,t2);
                }
                if(str[0]=='Q'){
                    int t1,t2;scanf("%d%d",&t1,&t2);
                    int ans=query(t1,t2);
                    printf("%d\n",ans);
                }
            }
        }
    }
    return 0;
}
/*
1
14
1 2 9
1 3 7
1 4 1
2 5 13
2 6 10
6 11 11
6 12 12
3 7 8
4 8 6
4 9 2
4 10 5
9 13 3
13 14 4
*/
