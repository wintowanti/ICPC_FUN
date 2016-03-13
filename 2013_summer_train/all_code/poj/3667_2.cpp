#include<cstdio>
#include<cstring>
#define M 508000
#define lson (rt<<1)
#define rson (rt<<1|1)
struct E{
    int lmax,lflag,rmax,rflag,tmax,tflag,lazy;
};
struct T{
    E e[M<<2];
    void push_up(int rt,int num){
        int t1=(num+1)>>1;int t2=(num)>>1;
        e[rt].lmax=e[lson].lmax;e[rt].lflag=e[lson].lflag;
        if(e[lson].lmax==t1&&e[rson].lmax!=0){
            e[rt].lmax=e[lson].lmax+e[rson].lmax;
        }
        e[rt].rmax=e[rson].rmax;e[rt].rflag=e[rson].rflag;
        if(e[rson].rmax==t2&&e[lson].rmax!=0){
            e[rt].rmax=e[rson].rmax+e[lson].rmax;
            e[rt].rflag=e[lson].rflag;
        }
        if(e[lson].tmax>e[rson].tmax){
            e[rt].tmax=e[lson].tmax;e[rt].tflag=e[lson].tflag;
        }
        else{
            e[rt].tmax=e[rson].tmax;e[rt].tflag=e[rson].tflag;
        }
        if(e[rt].tmax<e[lson].rmax+e[rson].lmax){
            e[rt].tmax=e[lson].rmax+e[rson].lmax;
            e[rt].tflag=e[lson].rflag;
        }
        if(e[rt].tmax<e[rt].lmax){
            e[rt].tmax=e[rt].lmax;e[rt].tflag=e[rt].lflag;
        }
        if(e[rt].tmax<e[rt].rmax){
            e[rt].tmax=e[rt].rmax;e[rt].tflag=e[rt].rflag;
        }
        return ;
    }
    void push_down(int rt,int num,int l){
        int t1=(num+1)>>1;
        int t2=(num)>>1;
        if(e[rt].lazy==0){
            e[lson].lazy=e[rson].lazy=0;
            e[lson].lmax=e[lson].tmax=e[rson].rmax=t1;e[lson].lflag=e[lson].rflag=e[lson].tflag=l;
            e[rson].lmax=e[rson].tmax=e[rson].rmax=t2;e[rson].lflag=e[rson].rflag=e[rson].tflag=l+t1;
        }
        else if(e[rt].lazy==1){
            e[lson].lazy=e[rson].lazy=1;
            e[lson].lmax=e[lson].tmax=e[lson].rmax=0;e[lson].lflag=e[lson].rflag=e[lson].tflag=l;
            e[rson].lmax=e[rson].tmax=e[rson].rmax=0;e[rson].lflag=e[rson].rflag=e[rson].tflag=l+t1+t2;
        }
        e[rt].lazy=-1;
    }
    void build(int l,int r,int rt){
        e[rt].lazy=-1;
        int num=(r-l+1);
        if(l==r){
            e[rt].lmax=e[rt].tmax=e[rt].rmax=1;e[rt].lflag=e[rt].rflag=e[rt].tflag=r+1;
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
        push_up(rt,num);
    }
    void update(int ul,int ur,int new_flag,int l,int r,int rt){
        int num=(r-l+1);
        if(ul<=l&&ur>=r){
            e[rt].lazy=new_flag;
            if(new_flag==0){
                e[rt].lmax=e[rt].rmax=e[rt].tmax=num;
                e[rt].lflag=e[rt].rflag=e[rt].tflag=l;
            }
            else if(new_flag==1){
                e[rt].lmax=e[rt].rmax=e[rt].tmax=0;
                e[rt].lflag=e[rt].rflag=e[rt].tflag=r;
            }
            return ;
        }
        push_down(rt,num,l);
        int mid=(l+r)>>1;
        if(ur<=mid) update(ul,ur,new_flag,l,mid,lson);
        else if(ul>mid) update(ul,ur,new_flag,mid+1,r,rson);
        else{
            update(ul,ur,new_flag,l,mid,lson);
            update(ul,ur,new_flag,mid+1,r,rson);
        }
        push_up(rt,num);
    }
    int query(int range,int l,int r,int rt){
        int num=(r-l+1);
//        printf("%d_____%d   %d    lazy is %d\n",e[rt].tmax,l,r,e[rt].lazy);
        if(e[rt].tmax<range) return -1;
        if(e[rt].lmax>=range) return l;
        push_down(rt,num,l);
        int mid=(l+r)>>1;
        int t1=query(range,l,mid,lson);
        int t2=query(range,mid+1,r,rson);
        push_up(rt,num);
        if(t1!=-1) return t1;
//        printf("%d   %d   !!++%d   %d+++\n",e[lson].rmax,e[rson].lmax,e[lson].rflag,e[rson].lflag);
        if(e[lson].rmax+e[rson].lmax>=range&&e[lson].rmax!=0){
            return e[lson].rflag;
        }
        push_up(rt,num);
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
                int ans=tr.query(t2,1,n,1);
//                printf("%d\n",ans);
                if(ans==-1) puts("0");else printf("%d\n",ans);
                if(ans==-1) continue;
                tr.update(ans,ans+t2-1,1,1,n,1);
            }
            else{
                int t2,t3;scanf("%d%d",&t2,&t3);
                int t4=t2+t3-1;
                if(t4>n) t4=n;
                tr.update(t2,t4,0,1,n,1);
            }
        }
    }
    return 0;
}
