#include<cstdio>
#include<cstring>
#define M 580000
int dp[M][10];
int last[M][10];
char str[M];
int ans[M];
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
       // m=n-m;
        scanf("%s",str);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            int t1=str[i-1]-'0';
            dp[i][t1]++;
            for(int j=0;j<10;j++){
                dp[i][j]+=dp[i-1][j];
            }
        }
        for(int i=n;i>=0;i--){
            int t1=str[i-1]-'0';
            for(int j=0;j<10;j++){
                last[i][j]=last[i+1][j];
            }
            last[i][t1]=i;
        }
        int l=0;
        for(int i=1;i<=n-m;i++){
            int tmax=-1;
            int r=m+i;
//            printf("l  r is %d  %d\n",l,r);
            for(int j=9;j>=0;j--){
                if(dp[r][j]-dp[l][j]>0){
                    tmax=j;
                    l=last[l+1][j];
                    break;
                }
            }
//            printf("%d\n",tmax);
            ans[i]=tmax;
        }
        for(int i=1;i<=n-m;i++){
            printf("%d",ans[i]);
        }
        puts("");
    }
    return 0;
}
