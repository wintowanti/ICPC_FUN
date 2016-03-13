#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define M 120000
#define N 198964
#define inf 0x3f3f3f3f
#define lson (rt<<1)
#define rson  (rt<<1|1)
using namespace std;
int a[M];
int simple[M];
int num;
struct B{
    int binary(int l,int r,int k){
        while(r>=l){
            int mid=(l+r)>>1;
            if(simple[mid]==k) return mid;
            if(simple[mid]>k){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
    }
    int binary_tmin(int l,int r,int k){
        int tmin=r;
        while(r>=l){
            int mid=(l+r)>>1;
            if(simple[mid]>=k){
                tmin=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return tmin;
    }
    int binary_tmax(int l,int r,int k){
        int tmax=l;
        while(r>=l){
            int mid=(l+r)>>1;
            if(simple[mid]<=k){
                tmax=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return tmax;
    }
}b;
int max(int x,int y){
    if(x>y) return x;return y;
}
struct A{
    int tsum1,tmax1;
};
struct T{
    int tsum[M<<2],tmax[M<<2];
    void build(){
        memset(tsum,0,sizeof(tsum));
        memset(tmax,0,sizeof(tmax));
    }
    void push_up(int rt){
        tsum[rt]=(tsum[lson]+tsum[rson])%N;
        tmax[rt]=max(tmax[lson],tmax[rson]);
    }
    A query(int ul,int ur,int l,int r,int rt){
        if(ul<=l&&ur>=r){
            A a;a.tsum1=tsum[rt]; a.tmax1=tmax[rt];
            return a;
        }
        int mid=(l+r)>>1;
        A a1,a2;
        if(ur<=mid) a1=query(ul,ur,l,mid,lson);
        else if(ul>mid) a1=query(ul,ur,mid+1,r,rson);
        else{
            a1=query(ul,ur,l,mid,lson);
            a2=query(ul,ur,mid+1,r,rson);
            a1.tsum1+=a2.tsum1;a1.tsum1%=N;
            a1.tmax1=max(a1.tmax1,a2.tmax1);
        }
        return a1;
    }
    void update(int ul,A new_flag,int l,int r,int rt){
        if(ul==l&&ul==r){
            tsum[rt]=new_flag.tsum1;
            tmax[rt]=new_flag.tmax1;
            return ;
        }
        int mid=(l+r)>>1;
        if(ul<=mid) update(ul,new_flag,l,mid,lson);
        else update(ul,new_flag,mid+1,r,rson);
        push_up(rt);
        return ;
    }
}tr;
int main(){
    int n,h;
    while(~scanf("%d%d",&n,&h)){
        simple[0]=a[0]=-inf;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),simple[i]=a[i];
        sort(simple,simple+n+1);
        int flag=0;
        for(int i=1;i<=n;i++){
            if(simple[i]-simple[i-1]<=h){
                flag=1;break;
            }
        }
        if(!flag){
            puts("0\n0\n");
            continue ;
        }
        num=unique(simple,simple+n+1)-simple;
//        printf("%d  \n",num);
        tr.build();
        for(int i=1;i<=n;i++){
            int t1=a[i]-h;
            int t2=a[i]+h;
            int l=b.binary_tmin(0,num,t1);
            int mid=b.binary(0,num,a[i]);
            int r=b.binary_tmax(0,num,t2);
            A a1=tr.query(l,r,1,num,1);
            A a2=tr.query(mid,mid,1,num,1);
//            printf(" a is %d  !%d   %d   %d  !%d  %d  \n",a[i],l,mid,r,a1.tsum1,a1.tmax1);
            a1.tsum1=(a2.tsum1+a1.tsum1+1)%N;
            a1.tmax1++;
            a1.tsum1%=N;
            tr.update(mid,a1,1,num,1);
        }
        int ans=tr.tsum[1];ans=(ans+N-n)%N;
        printf("%d\n%d\n",ans,tr.tmax[1]);
    }
    return 0;
}
