#include<stdio.h>
#define M 40
#define N 10
int n,m;
double dp[M][M][M][N];
int main(){
    double p1;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=m;k++) for(int k1=0;k1<=m;k1++) dp[j][k][k1][i]=0;
            }
        }
        p1=(1.0/n);
        for(int i=1;i<=n;i++){
            dp[1][1][1][i]=p1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int t1=j;
                for(int k=1;k<=n;k++){
                    for(int k1=1;k1<=m;k1++) {
                        for(int k2=1;k2<=m;k2++){
                            double tmp=dp[i][k1][k2][k];
                            int tmax=0;
                            if(t1==k){
                                tmax=k2+1;
                                if(tmax>k1) dp[i+1][tmax][k2+1][t1]+=tmp*p1;
                                else  dp[i+1][k1][k2+1][t1]+=tmp*p1;
                            }
                            else{
                                tmax=1;
                                if(tmax>k1) dp[i+1][tmax][1][t1]+=tmp*p1;
                                else dp[i+1][k1][tmax][t1]+=tmp*p1;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            double ans=0.00;
            for(int j=1;j<=n;j++){
                for(int k=1;k<=m;k++){
                    ans+=dp[m][i][k][j];
                }
            }
            printf("%.3lf\n",ans);
        }
    }
    return 0;
}
