#include<cstdio>
#include<cstring>
#include<iostream>
#define M 200000
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
int a[M];
struct T{
    struct E{
        int l,r,tmin;
    }e[M<<2];
    void push_up(int rt){
        e[rt].tmin=min(e[lson].tmin,e[rson].tmin);
    }
    void build(int l,int r,int rt){
        e[rt].l=l;e[rt].r=r;
        if(l==r){
            e[rt].tmin=a[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
        push_up(rt);
    }
    int query(int ul,int ur,int rt){
        if(ul<=e[rt].l&&ur>=e[rt].r){
            return e[rt].tmin;
        }
        int mid=(e[rt].r+e[rt].l)>>1;
        if(ur<=mid) return query(ul,ur,lson);
        else if(ul>mid) return query(ul,ur,rson);
        else{
            int t1=query(ul,ur,lson);
            int t2=query(ul,ur,rson);
            return min(t1,t2);
        }
    }
}tr;
int main(){
    int n,m;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        tr.build(1,n,1);
//        puts("~~~");
        int m;scanf("%d",&m);
        for(int i=0;i<m;i++){
            int l,r;scanf("%d%d",&l,&r);
            int ans=tr.query(l,r,1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
