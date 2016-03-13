#include<cstdio>
#include<cstring>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define M 300010
struct T{
    struct E{
        int l,r,color,lazy;
    }e[M<<2];
    void push_down(int rt){
        if(e[rt].lazy){
            e[lson].lazy=e[rson].lazy=e[rt].lazy;
            e[lson].color=e[rson].color=e[rt].lazy;
        }
        e[rt].lazy=0;
    }
    void build(int l,int r,int rt){
        e[rt].color=0;e[rt].lazy=0;
        e[rt].l=l;e[rt].r=r;
        if(l==r){
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
    }
    void update(int ul,int ur,int new_flag,int rt){
        if(ul<=e[rt].l&&ur>=e[rt].r){
            e[rt].color=new_flag;
            e[rt].lazy=new_flag;
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
    }
    int query(int ul,int rt){
        if(e[rt].l==ul&&e[rt].r==ul){
            return e[rt].color;
        }
        push_down(rt);
        int mid=(e[rt].r+e[rt].l)>>1;
        if(ul<=mid) return query(ul,lson);
        else return query(ul,rson);
    }
}tr;
int b[M][3];
int ans[M];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        tr.build(1,n,1);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
        }
        for(int i=m-1;i>=0;i--){
            if(b[i][2]!=b[i][0]){
                tr.update(b[i][0],b[i][2]-1,b[i][2],1);
            }
            if(b[i][2]!=b[i][1]){
                tr.update(b[i][2]+1,b[i][1],b[i][2],1);
            }
        }
        for(int i=1;i<=n;i++){
            int t1=tr.query(i,1);
            ans[i]=t1;
        }
        for(int i=1;i<=n;i++){
            if(i==1) printf("%d",ans[i]);
            else printf(" %d",ans[i]);
        }
        puts("");
    }
    return 0;
}
