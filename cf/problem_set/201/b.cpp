#include<cstdio>
#include<cstring>
#define M 108
#define inf 0x3f3f3f3f
int dp[M][M][M];
int pre[M*M*M][2];
int change(int x,int y,int z){
    return x*(102*102)+y*(102)+z;
}
char str1[M];
char str2[M];
char str3[M];
int main(){
    while(~scanf("%s%s%s",str1,str2,str3)){
        int n1=strlen(str1);
        int n2=strlen(str2);
        int n3=strlen(str3);
        memset(dp,-inf,sizeof(dp));
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0||j==0){
                    dp[i][j][1]=0;
                }
            }
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                for(int k=1;k<=n3;k++){
                    if(str1[i-1]==str2[j-1]){
//                        puts("!!!!!");
                        if(str1[i-1]==str3[k-1]){
                            dp[i][j][k+1]=dp[i-1][j-1][k]+1;
                            int t1=change(i,j,k+1);
                            int t2=change(i-1,j-1,k);
                            pre[t1][0]=t1;
                            pre[t1][1]=str1[i-1]-'A';
                        }
                        else {
                            if(dp[i][j][1]<dp[i-1][j-1][k]+1){
                                dp[i][j][1]=dp[i-1][j-1][k]+1;
                                int t1=change(i,j,1);
                                int t2=change(i-1,j-1,k);
                                pre[t1][0]=t2;
                                pre[t1][1]=str1[i-1]-'A';
                            }
                        }
                    }
                    {
                        if(dp[i-1][j][k]>dp[i][j-1][k]){
                            if(dp[i][j][k]>dp[i-1][j][k]) continue;
                            dp[i][j][k]=dp[i-1][j][k];
                            int t1=change(i,j,k);
                            int t2=change(i-1,j,k);
                            pre[t1][0]=t2;
                            pre[t1][1]=-1;
                        }
                        else{
                            if(dp[i][j][k]>dp[i][j-1][k]) continue;
                            dp[i][j][k]=dp[i][j-1][k];
                            int t1=change(i,j,k);
                            int t2=change(i,j-1,k);
                            pre[t1][0]=t2;
                            pre[t1][1]=-1;
                        }
                    }
                }
            }
        }
        int tmax=0;
        int tr;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                for(int k=1;k<=n3;k++){
                    if(dp[i][j][k]>tmax){
                        tr=change(i,j,k);
                        tmax=dp[i][j][k];
                    }
                }
            }
        }
        if(tmax==0){
            puts("0");
        }
        else{
            char ans[M];
            int len=tmax;
//            printf("%d\n",len);
            while(len>0){
                if(pre[tr][1]!=-1){
                    ans[len--]=pre[tr][1]+'A';
                }
                tr=pre[tr][0];
            }
            for(int i=1;i<=tmax;i++){
                printf("%c",ans[i]);
            }
            puts("");
        }
//        printf("%d\n",tmax);
    }
    return 0;
}
/*
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
*/
