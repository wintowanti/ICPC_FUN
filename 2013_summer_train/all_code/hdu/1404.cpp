#include<cstdio>
#include<cstring>
#define M 1100008
using namespace std;
int dp[M];
int ten[10];
int dfs(int x){
    if(dp[x]!=-1) return dp[x];
//    printf("%d~~~\n",x);
    int tmin=1;
    int flag_last=0;
    for(int i=1;i<=5;i++){
//        puts("^^^^^^^^^^^");
        if(ten[i-1]>x) break;
        if(ten[i]>x) flag_last=1;
        int t1=(x/ten[i-1])%10;
//        printf("t1 is  %d~~**********~~\n",t1);
        if(t1){
            for(int j=1;j<=t1;j++){
                int t3=x-j*ten[i-1];
////                if(j==t1&&flag_last) continue;
                int t4=dfs(t3);
//                printf("%d^^^^\n",t3);
//                int t4;
                if(t4<tmin) tmin=t4;
//                if(tmin==0) break;
            }
        }
        else{
            int t3=x/ten[i];
//            printf("t3   is%d!!!\n",t3);
            int t4=dfs(t3);if(t4<tmin) tmin=t4;
        }
    }
    return dp[x]=!tmin;
}
int main(){
   // freopen("in111.txt","w",stdout);
    memset(dp,-1,sizeof(dp));
    ten[0]=1;ten[1]=10;ten[2]=100;ten[3]=1000;ten[4]=10000;ten[5]=100000,ten[6]=1000000;
    char str[100];
    dp[0]=1;
//
    int tsum=0;
//    dfs(1000);
//    for(int i=0;i<=999999;i+=1){ dfs(i);if(dp[i]==0) printf(" %d,",i),tsum++;}
//    printf("%d\n",tsum);
//    dfs(999999);
    while(~scanf("%s",str)){
        if(str[0]=='0'){
            puts("Yes");
        }
        else{
            int tsum=0;
            for(int i=0;str[i];i++){
                tsum*=10;tsum+=str[i]-'0';
            }
//            printf("%d\n",tsum);
            int ans=dfs(tsum);
            if(ans) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
