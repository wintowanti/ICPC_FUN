#include<cstdio>
#include<math.h>
#include<cstring>
#include<iostream>
#define M 108
#define ll long long
using namespace std;
ll c[2][4][M];
ll t[M][11];
ll dp[2][M*10];
ll good[M*10][2];
ll mark[M];
ll n;
ll find_dp(ll last,ll en){
    memset(dp[1],0,sizeof(dp[1]));
    for(ll i=0;i<en;i++){
        for(ll j=0;j+good[i][0]<=last;j++){
            if(dp[0][j]+good[i][1]>dp[1][j+good[i][0]]) dp[1][j+good[i][0]]=dp[0][j]+good[i][1];
        }
    }
    for(ll i=0;i<=last;i++) dp[0][i]=dp[1][i];
    return 1;
}
ll work(ll last,ll flag1,ll flag2){
    memset(mark,0,sizeof(mark));
    memset(dp,0,sizeof(dp));
    for(ll j=1;j<=n;j++){
        mark[j]=max(mark[j],c[0][flag1][j]);
    }
    for(ll j=1;j<=n;j++){
        mark[j]=max(mark[j],c[1][flag2][j]);
    }
    for(ll i=1;i<=n;i++){
        for(ll j=mark[i];j<6;j++){
            last-=t[i][j+1];
        }
        mark[i]=max(6ll,mark[i]);
    }
    if(last<0) return -1000;
    ll has=0;
    for(ll i=1;i<=n;i++){
        has+=(mark[i])*t[i][0];
    }
    for(ll i=1;i<=n;i++){
        ll tsum=0;
        good[0][0]=0;
        good[0][1]=0;
        ll en=1;
        for(ll j=mark[i]+1;j<=10;j++){
            tsum+=t[i][j];
            ll cost=(j-mark[i])*t[i][0];
            good[en][0]=tsum;
            good[en++][1]=cost;
        }
        find_dp(last,en);
    }
    int tmax=0;
    for(int i=0;i<=last;i++) if(dp[0][i]>tmax) tmax=dp[0][i];
    return tmax+has;
}
int main(){
    ll cas;
    while(~scanf("%lld",&cas)){
        for(ll q=1;q<=cas;q++){
            printf("Case #%lld: ",q);
            ll alltime;scanf("%lld%lld",&n,&alltime);
            ll allb=0;
            for(ll i=1;i<=n;i++){
                for(ll j=0;j<11;j++) scanf("%lld",&t[i][j]);
                allb+=t[i][0];
            }
//            puts("*****");
            memset(c,0,sizeof(c));
            for(ll i=0;i<2;i++){
                for(ll j=1;j<4;j++){
                    for(ll k=0;k<=n;k++){
                        scanf("%lld",&c[i][j][k]);
                    }
                }
            }
            ll tmax=-100000;
            for(ll i=0;i<4;i++){
                for(ll j=0;j<4;j++){
                    ll last=alltime-c[0][i][0]-c[1][j][0];
                    if(last<0) continue;
//                    printf("this is mark     %lld   %lld  last is %lld **\n",i,j,last);
                    ll t1=work(last,i,j);
                    if(t1<0) continue;
                    if(t1*10+allb*(i+j)>tmax) tmax=t1*10+allb*(i+j);
//                    printf("this is %lld   \n",t1*10+allb*(i+j));
                }
            }
            if(tmax<0){
                puts("Impossible");
            }
            else{
                double ans=tmax*1.00/(allb+0.00);
                ans*=100.0;
                ans=round(ans);
                printf("%.2lf\n",ans/100.00);
            }
        }
    }
    return 0;
}
/*
3
1 9
2 1 1 1 1 1 2 2 2 2 2
4 9
4 3
5 5

3 9
4 10
6 10
*/
