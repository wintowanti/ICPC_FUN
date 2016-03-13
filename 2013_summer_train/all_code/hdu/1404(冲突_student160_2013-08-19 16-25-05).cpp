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
    for(int i=1;i<=5;i++){
//        puts("^^^^^^^^^^^");
        if(ten[i-1]>x) break;
        int t1=(x/ten[i-1])%ten[i];
//        printf("%d!!~~~~\n",t1);
        if(t1){
            for(int j=1;j<=t1;j++){
                int t3=x-j*ten[i-1];
                int t4=dfs(t3);
                if(t4<tmin) tmin=t4;
                if(tmin==0) break;
            }
        }
        if(tmin==0) break;
        else{
            int t3=x/ten[i];
//            printf("%d!!!\n",t3);
            int t4=dfs(t3);if(t4<tmin) tmin=t4;
        }
    }
    return dp[x]=!tmin;
}
int main(){
    freopen("in.txt","w",stdout);
    memset(dp,-1,sizeof(dp));
    ten[0]=1;ten[1]=10;ten[2]=100;ten[3]=1000;ten[4]=10000;ten[5]=100000;
    char str[100];
    dp[0]=1;
//    for(int i=0;i<=20;i++){
//        printf("i is%d   %d\n",i,dfs(i));
//    }
//    dfs(298000);
//    dfs(398000);
//    dfs(498000);
//    dfs(598000);
//    dfs(698000);
//    dfs(898000);
//    dfs(998000);
//    dfs(998990);
    int tsum=0;
    for(int i=0;i<999999;i+=1){ dfs(i);if(dp[i]==0) printf(",%d,\n",i),tsum++;}
    printf("%d\n",tsum);
//    dfs(999999);
//    while(~scanf("%s",str)){
//        if(str[0]=='0'){
//            puts("Yes");
//        }
//        else{
//            int tsum=0;
//            for(int i=0;str[i];i++){
//                tsum*=10;tsum+=str[i]-'0';
//            }
//            printf("%d\n",tsum);
//            int ans=dfs(tsum);
//            if(ans) puts("Yes");
//            else puts("No");
//        }
//    }
    return 0;
}
