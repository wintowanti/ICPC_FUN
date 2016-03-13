#include<cstdio>
#include<cstring>
#define M 100800
#define ll __int64
ll dp1[2][201];
ll dp2[2][201];
int a[M];
int b[M];
int c[M];
int main(){
    c[0]=0;
    int n,m;while(~scanf("%d%d",&n,&m)){
        c[0]=1;
        for(int i=1;i<=2*n+10;i++){
            c[i]=(c[i-1]*10)%m;
        }
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) b[i]=a[i],b[i+n]=a[i];
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        ll tsum1=0;
        ll tsum2=0;
        for(int i=n;i>=1;i--){
            int i1=i&1;
            dp1[i1][a[i]%m]+=1;
            memset(dp1[!i1],0,sizeof(dp1[!i1]));
            for(int j=0;j<=m;j++){
                int t1=n-i+1;
                int t2=(a[i]*c[t1]+j)%m;
//                printf("%d!!!\n",t2);
                dp1[!i1][t2]+=dp1[i1][j];
            }
            tsum1+=dp1[i1][0];
        }
        for(int i=2*n;i>=1;i--){
            int i1=i&1;
            dp2[i1][b[i]%m]+=1;
            memset(dp2[!i1],0,sizeof(dp2[!i1]));
            for(int j=0;j<=m;j++){
                int t1=2*n-i+1;
                int t2=(b[i]*c[t1]+j)%m;
                dp2[!i1][t2]+=dp2[i1][j];
            }
            tsum2+=dp2[i1][0];
        }
        printf("%I64d    %I64d\n",tsum2,tsum1);
    }
    return 0;
}
