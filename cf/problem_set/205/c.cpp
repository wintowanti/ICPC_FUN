#include<cstdio>
#include<cstring>
#include<iostream>
#define M 200000
using namespace std;
int a[M];
int tsum[M];
int dp[M];
int flag[M];
char str[M];
int main(){
    int n;while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        memset(tsum,0,sizeof(tsum));
        tsum[0]=a[0];
        for(int i=1;i<n;i++){
            tsum[i]=tsum[i-1]+a[i];
        }
        scanf("%s",str);
        int flag1=1;
        for(int i=0;str[i];i++){
            if(str[i]=='0') flag1=0;
            flag[i]=flag1;
        }
        int tmax=0;
        memset(dp,0,sizeof(dp));
        if(str[0]=='1') dp[0]=a[0];
        for(int i=1;i<n;i++){
            if(str[i]=='1'){
                if(flag[i]){
                    dp[i]=dp[i-1]+a[i];
                }
                else{
                    int t1=dp[i-1]+a[i];
                    int t2=tsum[i-1];
                    dp[i]=max(t1,t2);
                }
            }
            dp[i]=max(dp[i],dp[i-1]);
        }
//        for(int i=0;i<n;i++){
//            printf("%d  ",dp[i]);
//        }
//        puts("~~~");
        printf("%d\n",dp[n-1]);
    }
    return 0;
}
/*
5
17 0 10 30 1
10110
*/
