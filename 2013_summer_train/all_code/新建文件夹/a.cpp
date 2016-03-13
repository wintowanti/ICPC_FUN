#include<cstdio>
#include<cstring>
#define M 17
#define inf 0x3f3f3f3f
int dp[1<<M];
int dis[M][M];
int cost[M];
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            int n,m,k;scanf("%d%d%d",&n,&m,&k);
            for(int i=1;i<=n;i++) scanf("%d",&cost[i]);
            memset(dis,inf,sizeof(dis));
            for(int i=0;i<m;i++){
                int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);if(dis[t1][t2]>t3){
                    dis[t1][t2]=t3;dis[t2][t1]=t3;
                }
            }
            memset(dp,inf,sizeof(dp));
            dp[1]=0;
            for(int i=1;i<(1<<n);i++){
                if(dp[i]<k){
                    for(int j=0;j<n;j++){
                        int t1=1<<j;
                        if(i&t1){
                            for(int k=0;k<n;k++){
                                int t2=1<<k;
                                if(i&t2) continue;
                                int t3=dp[i]+dis[j+1][k+1];
                                int t4=i^t2;
                                if(t3<dp[t4]){
                                    dp[t4]=t3;
                                }
                            }
                        }
                    }
                }
            }
            int tmax=0;
            for(int i=0;i<(1<<n);i++){
                if(dp[i]<=k){
                    int tsum=0;
                    for(int j=0;j<n;j++){
                        if(i&(1<<j)){
                            tsum+=cost[j+1];
                        }
                    }
                    if(tmax<tsum) tmax=tsum;
                }
            }
            printf("%d\n",tmax);
        }
    }
    return 0;
}
