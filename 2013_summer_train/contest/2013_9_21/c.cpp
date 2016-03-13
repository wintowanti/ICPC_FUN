#include<cstring>
#include<cstdio>
#define M 200000
int dp[30][2];
int str1[M];
int str2[M];
int main(){
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)){
        for(int i=0;i<n;i++) scanf("%d",&str1[i]);
        for(int i=0;i<m;i++) scanf("%d",&str2[i]);
        memset(dp,0,sizeof(dp));
        int ans=0;
        int i=0,j=0;
        for(;i<n;){
            int t1=str1[i];
            int t2=str2[j];
            if(dp[t1][0]==t2){
                j++;
                i++;
                dp[t1][1]++;
//                printf("%d  %d   %d\n",i,j,m);
                if(j==m){
                    ans++;
                    j=0;
                    memset(dp,0,sizeof(dp));
                }
            }
            else if(dp[t1][0]==0){
                int flag=1;
                for(int k1=1;k1<=k;k1++){
                    if(dp[k1][1]!=0){
                        if(k1<t1&&dp[k1][0]>=t2){
                            flag=0;
                        }
                        if(k1>t1&&dp[k1][0]<=t2){
                            flag=0;
                        }
                    }
                }
                if(flag){
                    dp[t1][0]=t2;
                    dp[t1][1]+=1;
                    j++;
                    i++;
                    if(j==m){
                        ans++;
                        j=0;
                        memset(dp,0,sizeof(dp));
                    }
                }
                else{
                    int t3=i-j;
                    int l1=str1[t3];
                    dp[l1][1]--;
                    if(dp[l1][1]==0){
                        dp[l1][0]=0;
                    }
//                    j--;
                }
            }
            else if(dp[t1][0]!=t2){
                int t3=i-j;
                int t33=0;
                int l1=str1[t3];
                dp[l1][1]--;
                if(dp[l1][1]==0){
                    dp[l1][0]=0;
                }
//                j--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
10 5 10
2 4 2 4 2 1 5 2 5 1
1 2 1 2 1
*/
