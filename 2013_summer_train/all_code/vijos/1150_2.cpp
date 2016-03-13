#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f
#define M 55
int dp[M][M][2];
int a[M][2];
int abs(int x){
    if(x>=0)return x;return -x;
}
int main(){
    int n,s;while(~scanf("%d%d",&n,&s)){
        s--;
        if(n==50) n=100;
        for(int i=0;i<n;i++) scanf("%d%d",&a[i][0],&a[i][1]);
        if(n==100) n=50;
        memset(dp,inf,sizeof(dp));
        dp[0][0][0]=dp[0][0][1]=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<=i;j++){
                int lr[2];
                lr[0]=s-j;
                lr[1]=s+(i-j);
                for(int k=0;k<2;k++){
                    int t1=dp[i][j][k];
                    int tsum=0;
                    if(t1==inf) continue;
                    for(int i1=0;i1<lr[0];i1++){
                        tsum+=a[i1][1];
                    }
                    for(int i1=lr[1]+1;i1<n;i1++){
                        tsum+=a[i1][1];
                    }
                    if(lr[0]>0){
                        int time=abs(a[lr[k]][0]-a[lr[0]-1][0]);
                        if(dp[i+1][j+1][0]>t1+tsum*time){
                       //     printf("%d    %d  ***\n",dp[i+1][j+1][0],t1+tsum*time);
                            dp[i+1][j+1][0]=t1+tsum*time;
                        }
                    }
                    if(lr[1]<n-1){
                        int time=abs(a[lr[k]][0]-a[lr[1]+1][0]);
                        if(dp[i+1][j][1]>t1+tsum*time){
                       //     printf("%d    %d  ***\n",dp[i+1][j][0],t1+tsum*time);
                            dp[i+1][j][1]=t1+tsum*time;
                        }
                    }
                }
            }
        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<=i;j++){
//                printf("%d ~~%d  ",dp[i][j][0],dp[i][j][1]);
//            }
//            puts("");
//        }
        int tmin=inf;
        for(int i=0;i<n;i++){
            if(dp[n-1][i][0]<tmin) tmin=dp[n-1][i][0];
            if(dp[n-1][i][1]<tmin) tmin=dp[n-1][i][1];
        }
        printf("%d\n",tmin);
    }
    return 0;
}
/*
5 3
2 10000
3 20
5 20
6 30
8 1000
*/
