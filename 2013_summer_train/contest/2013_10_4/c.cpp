#include<cstring>
#include<cstdio>
#include<iostream>
#define M 201000
#define lson (rt<<1)
#define rson (rt<<1|1)
struct T{
    struct E{
        int l,r,tsum;
    }e[M<<2];
    void push_up(int rt){
        e[rt].tsum=e[lson].tsum+e[rson].tsum;
    }
    void build(int l,int r,int rt){
        e[rt].l=l;e[rt].r=r;
        e[rt].tsum=0;
        if(l==r){
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
        push_up(rt);
    }
    void update(int ul,int new_flag,int rt){
        if(ul==e[rt].l&&ul==e[rt].r){
            e[rt].tsum=new_flag;
            return ;
        }
        int mid=(e[rt].l+e[rt].r)>>1;
        if(mid>=ul) update(ul,new_flag,lson);
        else update(ul,new_flag,rson);
        push_up(rt);
    }
    int query(int ul,int ur,int rt){
        if(ul<=e[rt].l&&ur>=e[rt].r){
            return e[rt].tsum;
        }
        int mid=(e[rt].l+e[rt].r)>>1;
        int ans=0;
        if(mid>=ur){
            ans=query(ul,ur,lson);
        }
        else if(mid<ul){
            ans=query(ul,ur,rson);
        }
        else{
            ans=query(ul,ur,lson);
            ans+=query(ul,ur,rson);
        }
        return ans;
    }
}tr;
int vis[M];
int ans[M];
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            int n,r;scanf("%d%d",&n,&r);
            int tsum=n+r+10;
            int tflag=0;
            tr.build(1,tsum,1);
            for(int i=n;i>=1;i--){
                vis[i]=++tflag;
                tr.update(tflag,1,1);
            }
            for(int i=0;i<r;i++){
                int t1;scanf("%d",&t1);
                int t2=vis[t1];
//                printf("%d!!\n",t2);
                int t3=tr.query(t2,tsum,1)-1;
                tr.update(t2,0,1);
                tr.update(++tflag,1,1);
                vis[t1]=tflag;
                ans[i]=t3;
            }
            for(int i=0;i<r;i++){
                if(i) printf(" %d",ans[i]);
                else printf("%d",ans[i]);
            }
            puts("");
        }
    }
    return 0;
}
