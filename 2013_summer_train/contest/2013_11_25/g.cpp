#include<cstdio>
#include<cstring>
#include<iostream>
#define M 1100000
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
struct T{
    struct E{
        int l,r,flag,lazy;
    }e[M<<2];
    void build(int l,int r,int rt){
        e[rt].l=l;e[rt].r=r;
        e[rt].flag=0;e[rt].lazy=0;
        if(l==r){
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
    }
    void push_down(int rt){
        if(e[rt].lazy){
            e[lson].lazy=1;
            e[rson].lazy=1;
            e[lson].flag=1;
            e[rson].flag=1;
        }
        e[rt].lazy=0;
    }
    int query(int ul,int rt){
        if(e[rt].l==ul&&e[rt].r==ul){
            return e[rt].flag;
        }
        push_down(rt);
        int mid=(e[rt].l+e[rt].r)>>1;
        if(ul<=mid) return query(ul,lson);
        else return query(ul,rson);
    }
    void update(int ul,int ur,int rt){
        if(ul<=e[rt].l&&ur>=e[rt].r){
            e[rt].flag=1;
            e[rt].lazy=1;
            return ;
        }
        push_down(rt);
        int mid=(e[rt].l+e[rt].r)>>1;
        if(ur<=mid) update(ul,ur,lson);
        else if(ul>mid) update(ul,ur,rson);
        else{
            update(ul,ur,lson);
            update(ul,ur,rson);
        }
    }
}tr;
int main(){
    int n,a,b;
    while(~scanf("%d%d%d",&n,&a,&b)){
        if(a>b) swap(a,b);
        tr.build(1,n+3,1);
        for(int i=1;i<=n;i++){
            int t1=tr.query(i,1);
            if(t1==0){
                int ll=min(n+2,a+i);
                int rr=min(n+2,b+i);
                tr.update(ll,rr,1);
            }
        }
        int ans=tr.query(n+1,1);
        if(ans) puts("Alice");
        else puts("Bob");
    }
    return 0;
}
