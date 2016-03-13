#include<cstdio>
#include<cstring>
#define M 60
#define inf 0x3f3f3f3f
using namespace std;
int a[M][2];
int dp[M][M][2];
int abs(int x){
    if(x>=0) return x;
    return -x;
}
int main(){
    int n,s;
    while(~scanf("%d%d",&n,&s)){
        s=s-1;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i][0],&a[i][1]);
        }
        memset(dp,inf,sizeof(dp));
        dp[0][s][0]=0;
        dp[0][s][1]=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<i;j++){
                int lr[2];
                    lr[0]=s-j;
                    lr[1]=s+(i-j);
                for(int k=0;k<2;k++){
                    int t1=dp[i][j][k];
                    if(lr[0]>0){
                        int tsum=0;
                        for(int i1=0;i1<lr[0];i1++){
                            tsum+=a[i1][1];
                        }
                        for(int i1=lr[1]+1;i1<n;i1++){
                            tsum+=a[i1][1];
                        }
                        int time=abs(a[lr[0]-1][0]-a[lr[k]][0]);
                        if(dp[i+1][j+1][0]>dp[i][j][k]+time*tsum){
                            dp[i+1][j+1][0]=dp[i][j][k]+time*tsum;
                        }
                        if(dp[i+1][j+1][1]>dp[i][j][k]+time*tsum){
                            dp[i+1][j+1][1]=dp[i][j][k]+time*tsum;
                        }
                    }
                    if(lr[1]<n-1){
                        int tsum=0;
                        for(int i1=0;i1<lr[0];i1++){
                            tsum+=a[i1][1];
                        }
                        for(int i1=lr[1]+1;i1<n;i1++){
                            tsum+=a[i1][1];
                        }
                        int time=abs(a[lr[1]+1][0]-a[lr[k]][0]);
                        if(dp[i+1][j][0]>dp[i][j][k]+time*tsum){
                            dp[i+1][j][0]=dp[i][j][k]+time*tsum;
                        }
                        if(dp[i+1][j][1]>dp[i][j][k]+time*tsum){
                            dp[i+1][j][1]=dp[i][j][k]+time*tsum;
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d ~%d    ",dp[i][j][0],dp[i][j][1]);
            }
            puts("");
        }
        int tmin=inf;
        for(int i=0;i<n;i++){
            if(dp[n-1][i][0]<tmin) tmin=dp[n-1][i][0];
            if(dp[n-1][i][1]<tmin) tmin=dp[n-1][i][1];
        }
        printf("%d\n",tmin);
    }
    return 0;
}
