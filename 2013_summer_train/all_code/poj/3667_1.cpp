#include<cstdio>
#include<cstring>
#define M 508000
#define lson (rt<<1)
#define rson (rt<<1|1)
struct E{
    int lmax,rmax,rflag,tmax,lazy,l,r;
};
int max(int x,int y){
    if(x>y) return x;return y;
}
struct T{
    E e[M<<2];
    void push_up(int rt){
        int num=(e[rt].r-e[rt].l+1);
        int numl=(num+1)>>1;int numr=(num)>>1;
        e[rt].lmax=e[lson].lmax;
        if(e[lson].lmax==numl){
            e[rt].lmax=e[lson].lmax+e[rson].lmax;
        }
        e[rt].rmax=e[rson].rmax;
        e[rt].rflag=e[rson].rflag;
        if(e[rson].rmax==numr){
            e[rt].rmax=e[rson].rmax+e[lson].rmax;
            e[rt].rflag=e[lson].rflag;
        }
        int t1=max(e[lson].tmax,e[rson].tmax);
            t1=max(t1,e[lson].rmax+e[rson].lmax);
        e[rt].tmax=t1;
//        printf("%d    %d     %d   ___%d    %d______!!\n",e[rt].l,e[rt].r,t1,e[rt].lmax,e[rt].rmax);
    }
    void push_down(int rt){
        int num=(e[rt].r-e[rt].l+1);
        if(e[rt].lazy==0){
            e[lson].lazy=e[rson].lazy=e[rt].lazy;
            e[lson].rmax=e[lson].lmax=e[lson].tmax=(num+1)>>1;  e[lson].rflag=e[lson].l;
            e[rson].rmax=e[rson].lmax=e[rson].tmax=(num)>>1;    e[rson].rflag=e[rson].l;
        }
        if(e[rt].lazy==1){
            e[lson].lazy=e[rson].lazy=e[rt].lazy;
            e[lson].rmax=e[lson].lmax=e[lson].tmax=0;  e[lson].rflag=e[lson].r+1;
            e[rson].rmax=e[rson].lmax=e[rson].tmax=0;    e[rson].rflag=e[rson].r+1;
        }
        e[rt].lazy=-1;
    }
    void build(int l,int r,int rt){
        e[rt].l=l;e[rt].r=r;
        e[rt].lazy=-1;
        if(l==r){
            e[rt].lmax=e[rt].tmax=e[rt].rmax=1;e[rt].rflag=l;
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
        push_up(rt);
    }
    void update(int ul,int ur,int new_flag,int rt){
        int num=(e[rt].r-e[rt].l+1);
        if(ul<=e[rt].l&&ur>=e[rt].r){
            e[rt].lazy=new_flag;
            if(new_flag==0){
                e[rt].lmax=e[rt].rmax=e[rt].tmax=num;e[rt].rflag=e[rt].l;
            }
            if(new_flag==1){
                e[rt].lmax=e[rt].rmax=e[rt].tmax=0; e[rt].rflag=e[rt].r+1;
            }
            return ;
        }
        push_down(rt);
        int mid=(e[rt].r+e[rt].l)>>1;
        if(ur<=mid) update(ul,ur,new_flag,lson);
        else if(ul>mid) update(ul,ur,new_flag,rson);
        else{
            update(ul,ur,new_flag,lson);
            update(ul,ur,new_flag,rson);
        }
        push_up(rt);
    }
    int query(int range,int rt){
//        printf("%d   %d   %d++++++++++++\n",  e[rt].l,e[rt].r,e[rt].tmax);
        if(e[rt].tmax<range) return -1;
        if(e[rt].lmax>= range) return e[rt].l;
        push_down(rt);
        int t1=query(range,lson);
        if(t1!=-1) return t1;
        int t2=query(range,rson);
        push_up(rt);
        if(e[lson].rmax+e[rson].lmax>=range){
//            printf("****************\n");
            return e[lson].rflag;
        }
        return t2;
    }
}tr;
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        tr.build(1,n,1);
        for(int i=0;i<m;i++){
            int t1;scanf("%d",&t1);
            if(t1==1){
                int t2;scanf("%d",&t2);
                int ans=tr.query(t2,1);
//                printf("%d\n",ans);
                if(ans==-1) puts("0");else printf("%d\n",ans);
                if(ans==-1) continue;
                tr.update(ans,ans+t2-1,1,1);
            }
            else{
                int t2,t3;scanf("%d%d",&t2,&t3);
                int t4=t2+t3-1;
                if(t4>n) t4=n;
                tr.update(t2,t4,0,1);
            }
        }
    }
    return 0;
}
/*
12 600
1 3
1 3
1 3
1 1
1 1
1 1
2 5 5
1 5
*/
