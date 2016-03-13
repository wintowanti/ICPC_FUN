#include<cstdio>
#include<cstring>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define M  208000
struct E{
    int level,tsum,l,r;
};
int a[M];
struct T{
    E e[M<<2];
    void push_up(int rt){
        e[rt].level=e[lson].level+1;
        int t1=e[rt].level%2;
        if(t1){
            e[rt].tsum=(e[lson].tsum|e[rson].tsum);
        }
        else{
            e[rt].tsum=(e[lson].tsum^e[rson].tsum);
        }
//        printf("%d!!!!\n",e[rt].tsum);
    }
    void build(int l,int r,int rt){
        e[rt].l=l;e[rt].r=r;
        if(l==r){
            e[rt].tsum=a[l];
            e[rt].level=0;
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
}tr;
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=(1<<n);i++){
            scanf("%d",&a[i]);
        }
//        puts("~~~~~~~~~~~");
        int t1=1<<n;
        tr.build(1,t1,1);
        for(int i=0;i<m;i++){
            int t2,t3;scanf("%d%d",&t2,&t3);
            tr.update(t2,t3,1);
            printf("%d\n",tr.e[1].tsum);
        }
    }
    return 0;
}
