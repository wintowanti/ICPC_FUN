#include<cstdio>
#include<cstring>
#include<iostream>
#define M 108
#define ll long long
using namespace std;
int c[2][4][M];
int t[M][11];
int dp[M*10];
int good[M*10][2];
int mark[M];
int n;
int find_dp(int last,int en){
    memset(dp,0,sizeof(dp));
    for(int i=0;i<en;i++){
        for(int j=last;j>=good[i][0];j--){
            if(dp[j]<dp[j-good[i][0]]+good[i][1]) dp[j]=dp[j-good[i][0]]+good[i][1];
        }
    }
    int tmax=0;
    for(int i=0;i<=last;i++) if(dp[i]>tmax) tmax=dp[i];
    return tmax;
}
int work(int last,int flag1,int flag2){
    memset(mark,0,sizeof(mark));
    for(int j=1;j<=n;j++){
        mark[j]=max(mark[j],c[0][flag1][j]);
    }
    for(int j=1;j<=n;j++){
        mark[j]=max(mark[j],c[1][flag2][j]);
    }
    for(int i=1;i<=n;i++){
        for(int j=mark[i];j<6;j++){
            last-=t[i][j+1];
        }
        mark[i]=max(6,mark[i]);
    }
    if(last<0) return -1000;
    int has=0;
    for(int i=1;i<=n;i++){
        has+=(mark[i])*t[i][0];
    }
    int en=0;
    for(int i=1;i<=n;i++){
        int tsum=0;
        for(int j=mark[i]+1;j<=10;j++){
            tsum+=t[i][j];
            int cost=(j-mark[i])*t[i][0];
            good[en][0]=tsum;
            good[en++][1]=cost;
        }
    }
    int ans=find_dp(last,en);
    return ans+has;
}
int main(){
    int cas;
    while(~scanf("%d",&cas)){
        for(int q=1;q<=cas;q++){
            printf("Case #%d: ",q);
            int alltime;scanf("%d%d",&n,&alltime);
            int allb=0;
            for(int i=1;i<=n;i++){
                for(int j=0;j<11;j++) scanf("%d",&t[i][j]);
                allb+=t[i][0];
            }
//            puts("*****");
            memset(c,0,sizeof(c));
            for(int i=0;i<2;i++){
                for(int j=1;j<4;j++){
                    for(int k=0;k<=n;k++){
                        scanf("%d",&c[i][j][k]);
                    }
                }
            }
            int tmax=-100000;
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    int last=alltime-c[0][i][0]-c[1][j][0];
                    if(last<0) continue;
//                    printf("this is mark     %d   %d  last is %d **\n",i,j,last);
                    int t1=work(last,i,j);
                    if(t1*10+allb*(i+j)>tmax) tmax=t1*10+allb*(i+j);
//                    printf("this is %d   \n",t1*10+allb*(i+j));
                }
            }
            if(tmax<0){
                puts("Impossible");
            }
            else{
                double ans=tmax*1.00/(allb+0.00);
                printf("%.2lf\n",ans);
            }
        }
    }
    return 0;
}
