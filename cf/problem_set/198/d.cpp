#include<cstdio>
#include<cstring>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define M 200000
int max(int x,int y){
    if(x>y) return x;return y;
}
struct T{
    struct E{
        int l,r,tmax;
    }e[M<<2];
    void push_up(int rt){
       e[rt].tmax=max(e[lson].tmax,e[rson].tmax);
    }
    void build(int l,int r,int rt){
        e[rt].l=l;
        e[rt].r=r;
        if(l==r){
            e[rt].tmax=0;
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
        push_up(rt);
    }
    void update(int ul,int new_flag,int rt){
//        printf("%d  %d   %d   %d\n",ul,e[rt].l,e[rt].r,new_flag);
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
        if(ul<=e[rt].l&&ur>=e[rt].r){
            return e[rt].tmax;
        }
        int mid=(e[rt].l+e[rt].r)>>1;
        int t1=0,t2=0;
        if(ur<=mid) t1=query(ul,ur,lson);
        else if(ul>mid) t2=query(ul,ur,rson);
        else{
            t1=query(ul,ur,lson);
            t2=query(ul,ur,rson);
        }
        t1=max(t1,t2);
        return t1;
    }
}tr;
int a[M];
int main(){
    int n;while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]++;
        tr.build(1,n+1,1);
//        puts("~~~~~");
        for(int i=1;i<=n;i++){
            int t1=a[i];
            int t2=tr.query(1,t1-1,1);
//            printf("%d\n",t2);
            t2++;
            tr.update(t1,t2,1);
//            puts("******");
        }
        int ans=tr.query(1,n+1,1);
        printf("%d\n",ans);
    }
    return 0;
}
