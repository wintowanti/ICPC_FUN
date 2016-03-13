#include<cstdio>
#define M 40000
#define ll long long
#define inf 0x3f3f3f3f
#define lson (rt<<1)
#define rson (rt<<1|1)
ll tsum[M<<2];
ll tflag[M<<2];
int a[M];
void push_up(int rt){
    tsum[rt]=tsum[lson]+tsum[rson];
}
void push_down(int rt,ll num){
    if(tflag[rt]!=-inf){
        tflag[lson]=tflag[rson]=tflag[rt];
        tsum[lson]=((num+1)/2)*tflag[lson];
        tsum[rson]=((num)/2)*tflag[rson];
        tflag[rt]=-inf;
    }
}
void build(int l,int r,int rt){
    tflag[rt]=-inf;
    if(l==r){
        tsum[rt]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    push_up(rt);
}
void updata(int ul,int ur,ll new_flag,int l,int r,int rt){
    ll num=r-l+1;
//    printf("%d    %d    !!%d   %d   %d    %d\n",ul,ur,new_flag,l,r,rt);
    if(ul<=l&&ur>=r){
//        printf("@@@@@@@@@@@@@@@@\n");
        tsum[rt]=num*new_flag;
        tflag[rt]=new_flag;
        return ;
    }
    push_down(rt,num);
    int mid=(l+r)>>1;
    if(ur<=mid)     updata(ul,ur,new_flag,l,mid,lson);
    else if(ul>mid) updata(ul,ur,new_flag,mid+1,r,rson);
    else{           updata(ul,ur,new_flag,l,mid,lson);
                    updata(ul,ur,new_flag,mid+1,r,rson);
    }
    push_up(rt);
}
ll query(int ul,int ur,int l,int r,int rt){
    ll num=r-l+1;
    if(ul<=l&&ur>=r){
        return tsum[rt];
    }
    push_down(rt,num);
    int mid=(l+r)>>1;
    ll sum=0;
    if(ur<=mid)     sum+=query(ul,ur,l,mid,lson);
    else if(ul>mid) sum+=query(ul,ur,mid+1,r,rson);
    else{
                    sum+=query(ul,ur,l,mid,lson);
                    sum+=query(ul,ur,mid+1,r,rson);
    }
    push_up(rt);
    return sum;
}
int main(){
    int n,m;
    ll tsum1;
    while(~scanf("%d%d",&n,&m)){
        tsum1=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),tsum1+=a[i];
        build(1,n,1);
        ll t1=query(1,2,1,n,1);
//        printf("%I64d****!!\n",t1);
         t1=query(1,n,1,n,1);
//        printf("%I64d****!!\n",t1);
        for(int i=0;i<m;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            ll t3=query(t1,t2,1,n,1);
            ll all=query(1,n,1,n,1);
            ll num=t2-t1+1;
            ll t4=t3/num;
//            printf("%I64d    %I64d      %I64d\n",t4,all,t3);
            if(t4*num==t3){
                updata(t1,t2,t4,1,n,1);
            }
            else{
                if(all<=tsum1){
                    if(t4>0)t4=t4+1;
                }
                else{
                    if(t4<0) t4=t4-1;
                }
//                printf("%d^^^\n",(int)t4);
                updata(t1,t2,t4,1,n,1);
            }
        }
//        ll t22=query(4,4,1,n,1);
//         printf("%I64d*****\n",t22);
//        ll t11=query(5,5,1,n,1);
//        printf("%I64d*****\n",t11);
        for(int i=1;i<=n;i++){
            ll t1=query(i,i,1,n,1);
            if(i==1) printf("%lld",t1);
            else printf(" %lld",t1);
        }
        puts("");
    }
    return 0;
}
/*
6 2
1 1 1 1 1 1
2 5
3 4
*/
