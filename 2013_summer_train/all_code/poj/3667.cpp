#include<cstdio>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define M 70000
struct E{
    int lmax,lflag,rmax,rflag,tmax,tflag,lazy;
};
struct T{
    E e[M<<2];
    void push_up(int rt,int num){
        e[rt].lmax=e[lson].lmax;e[rt].lflag=e[lson].lflag;
        e[rt].rmax=e[rson].rmax;e[rt].rflag=e[rson].rflag;
        if(e[lson].lmax==(num+1)/2){
            e[rt].tmax=e[lson].lmax+e[rson].lmax;
        }
        if(e[rson].rmax==(num)/2){
            e[rt].rmax=e[lson].rmax+e[rson].rmax;
            e[rt].rflag=e[lson].rflag;
        }
        if(e[lson].tmax>=e[rson].tmax){
            e[rt].tmax=e[lson].tmax;e[rt].tmax=e[lson].tflag;
        }else{
            e[rt].tmax=e[rson].tmax;e[rt].tmax=e[rson].tflag;
        }
        int t1=e[lson].rmax+e[rson].lmax;
        if(t1>e[rt].tmax||(t1==e[rt].tmax&&e[lson].rflag<e[rt].tflag)){
            e[rt].tmax=t1;e[rt].tflag=e[lson].rflag;
        }
    }
    void push_down(int rt,int num){
        if(e[rt].lazy==0){
            e[lson].lazy=e[rson].lazy=0;
            int t1=(num+1)>>1;int t2=(num)>>1;
            e[lson].lmax=e[lson].rmax=e[lson].tmax=t1;e[lson].lflag=e[lson].rflag=e[lson].tflag=e[lson].lflag;
            e[rson].lmax=e[rson].rmax=e[rson].tmax=t2;e[rson].lflag=e[rson].rflag=e[rson].tflag=e[rson].lflag;
        }
        else if(e[rt].lazy==1){
            e[lson].lazy=e[rson].lazy=1;
            e[lson].lmax=e[lson].rmax=e[lson].tmax=0;e[lson].lflag=e[lson].rflag=e[lson].tflag=e[lson].lflag;
            e[rson].lmax=e[rson].rmax=e[rson].tmax=0;e[rson].lflag=e[rson].rflag=e[rson].tflag=e[rson].lflag;
        }
        e[rt].lazy=-1;
        return ;
    }
    void build(int l,int r,int rt){
        e[rt].lazy=-1;
        int num=(r-l+1);
        if(l==r){
            e[rt].lmax=e[rt].rmax=e[rt].tmax=1;
            e[rt].lflag=e[rt].rflag=e[rt].tflag=l;
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,lson);
        build(mid+1,r,rson);
        push_up(rt,num);
    }
    void update(int ul,int ur,int new_flag,int l,int r,int rt){
        int num=(r+l-1);
        if(ul<=l&&ur>=r){
            e[rt].lazy=new_flag;
            if(new_flag==0){
                e[rt].tmax=e[rt].rmax=e[rt].lmax=num;e[rt].tflag=e[rt].rflag=e[rt].lflag=e[rt].lflag;
            }
            else{
                e[rt].tmax=e[rt].rmax=e[rt].lmax=0;e[rt].tflag=e[rt].rflag=e[rt].lflag=e[rt].lflag;
            }
            return ;
        }
        push_down(rt,num);
        int mid=(l+r)>>1;
        if(ur<=mid) update(ul,ur,new_flag,l,mid,rt);
        else if(ul>mid) update(ul,ur,new_flag,mid+1,r,rt);
        else{
            update(ul,ur,new_flag,l,mid,rt);
            update(ul,ur,new_flag,mid+1,r,rt);
        }
        push_up(rt,num);
    }
    int query(int range,int l,int r,int rt){
        int num=(r+l-1);
        if(range>e[rt].tmax) return -1;
        if(e[rt].lmax>=range)
            return e[rt].lflag;
        push_down(rt,num);
        push_up(rt,num);
        int mid=(l+r)>>1;
        int t1=query(range,l,mid,lson);
        int t2=query(range,mid+1,r,rson);
        if(t1!=-1) return t1;
        if(e[lson].rmax+e[rson].lmax>=range){
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
                int ans=tr.query(t2,1,n,1);
                printf("%d\n",ans);
                if(ans==-1){
                    puts("0");
                }
                else{
                    printf("%d\n",ans);
                    tr.update(ans,ans+t2-1,1,1,n,1);
                }
            }
            else{

            }
        }
    }
}
/*
10 6
1 3
1 3
*/
