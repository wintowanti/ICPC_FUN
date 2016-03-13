#include<cstdio>
#include<iostream>
#include<cstring>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define M 200000
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<1];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
struct T{
    struct E{
        int l,r,num0,num1,lazy;
    }e[M<<2];
    void push_up(int rt){
        e[rt].num0=e[lson].num0+e[rson].num0;
        e[rt].num1=e[lson].num1+e[rson].num1;
    }
    void push_down(int rt){
        if(e[rt].lazy&1){
            swap(e[lson].num0,e[lson].num1);
            swap(e[rson].num0,e[rson].num1);
            e[lson].lazy+=e[rt].lazy&1;
            e[rson].lazy+=e[rt].lazy&1;
        }
        e[rt].lazy=0;
    }
    void build(int l,int r,int rt){
        e[rt].l=l;e[rt].r=r;
        e[rt].lazy=0;
        if(l==r){
            e[rt].num0=1;e[rt].num1=0;
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
        push_up(rt);
    }
    void update(int ul,int ur,int rt){
        if(ul<=e[rt].l&&ur>=e[rt].r){
            e[rt].lazy+=1;
            swap(e[rt].num0,e[rt].num1);
            return ;
        }
        push_down(rt);
        int mid=(e[rt].r+e[rt].l)>>1;
        if(ur<=mid) update(ul,ur,lson);
        else if(ul>mid) update(ul,ur,rson);
        else{
            update(ul,ur,lson);
            update(ul,ur,rson);
        }
        push_up(rt);
    }
    int query(int ul,int ur,int rt){
        if(ul<=e[rt].l&&ur>=e[rt].r){
            return e[rt].num1;
        }
        push_down(rt);
        int mid=(e[rt].l+e[rt].r)>>1;
        int tsum=0;
        if(ur<=mid) tsum=query(ul,ur,lson);
        else if(ul>mid) tsum=query(ul,ur,rson);
        else{
            tsum=query(ul,ur,lson);
            tsum+=query(ul,ur,rson);
        }
        push_up(rt);
        return tsum;
    }
}tr;
int dfs_clock,pre[M],last[M];
void dfs(int u){
    pre[u]=++dfs_clock;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        dfs(v);
    }
    last[u]=dfs_clock;
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=2;i<=n;i++){
            int t1;scanf("%d",&t1);
            g1.add(t1,i);
        }
        dfs_clock=0;
        dfs(1);
//        puts("!!!!!!!!!!!!!!!!!");
//        for(int i=1;i<=n;i++){
//            printf("%d %d\n",pre[i],last[i]);
//        }
        tr.build(1,n,1);
        for(int i=0;i<m;i++){
            char str[10];int t1;scanf("%s%d",str,&t1);
            if(str[0]=='o'){
                int l=pre[t1];int r=last[t1];
                tr.update(l,r,1);
            }
            else{
                int l=pre[t1];int r=last[t1];
                int ans=tr.query(l,r,1);
                printf("%d\n",ans);
            }
        }
        puts("");
    }
    return 0;
}
/*
3 2
1 2
o 2
q 3
*/
