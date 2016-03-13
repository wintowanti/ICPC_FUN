#include<cstdio>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define M 200080
int a[M];
int max(int x,int y){
    if(x>y) return x;return y;
}
struct T{
    struct E{
        int tmax,l,r;
    }e[M<<2];
    void push_up(int rt){
        e[rt].tmax=max(e[lson].tmax,e[rson].tmax);
    }
    void build(int l,int r,int rt){
        e[rt].l=l;e[rt].r=r;
        if(l==r){
            e[rt].tmax=a[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
        push_up(rt);
    }
    int query(int ul,int ur,int rt){
        if(ul<=e[rt].l&&ur>=e[rt].r){
            return e[rt].tmax;
        }
        int mid=(e[rt].l+e[rt].r)>>1;
        if(ur<= mid) return query(ul,ur,lson);
        else if(ul>mid) return query(ul,ur,rson);
        else{
            int t1=query(ul,ur,lson);
            int t2=query(ul,ur,rson);
            t1=max(t1,t2);
            return t1;
        }
    }
}tr;
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        tr.build(1,n,1);
        int m;scanf("%d",&m);
        for(int i=0;i<m;i++){
            int x1,y1;scanf("%d%d",&x1,&y1);
            int ans=tr.query(x1,y1,1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
