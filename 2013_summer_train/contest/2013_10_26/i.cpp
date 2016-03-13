#include<cstdio>
#include<cstring>
#define M 200000
#define inf 0x3f3f3f3f
int a[M];
int b[M];
int sum[M];
int n,m,k;
int binary(int l,int r){
    int tmax=l;
    int t=sum[r];
    while(r>=l){
        int mid=(l+r)>>1;
        if(t-sum[mid]>k){
            tmax=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return tmax;
}
int main(){
    while(~scanf("%d%d%d",&n,&m,&k)){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sum[0]=0;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+a[i];
        }
        b[0]=0;
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
        }
        b[m+1]=inf+inf;
        int id=0;
        int ans;
        for(int i=1;i<=m+1;i++){
            int t1=b[i]-b[i-1]-1;
            int tt=id;
            id=id+t1;
            if(id>=n){
                if(id>=n){
                    ans=b[i-1]+n-tt;
                    break;
                }
            }
            int t2=binary(0,id);
            printf("%d  %d\n",id,t2);
            id=t2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
5 2 4
1
2
3
4
5
1 2
*/
