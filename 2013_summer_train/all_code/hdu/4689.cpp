#include<cstdio>
#include<cstring>
#define ll __int64
using namespace std;
int dp[22][200000];
int hash1[22][200000];
int hash[(1<<20)+10];
int judge(int x){
    int tsum=0;
    while(x){
        if(x&1) tsum++;
        x=x>>1;
    }
    return tsum;
}
int num[22];
int main(){
    char str[30];
    while(~scanf("%s",str)){
        int n=strlen(str);
        memset(num,0,sizeof(num));
        for(int i=0;i<1<<n;++i){
            int t1=judge(i);
            hash[i]=num[t1];
//            printf("i   is %d    t1 is  %d  num is   %d\n",i,t1,num[t1]);
            hash1[t1][num[t1]++]=i;
        }
        for(int i=0;i<=n;++i) for(int j=0;j<num[i];j++) dp[i][j]=0;
        dp[0][0]=1;
        int flag1=0;
        int flag=0;
        for(int i=0;i<n;++i){
            flag=0;
            for(int j=0;j<num[i];j++){
                if(dp[i][j]!=0){
                    int t1=hash1[i][j];
                    for(int k=0;k<n;k++){
                        if(t1&(1<<k)) continue;
                        if(i==k) continue;
                        if(str[k]=='+'){
                            if(i>k){
                                int t2=t1^(1<<k);
                                int nextj=hash[t2];
                                dp[i+1][nextj]+=dp[i][j];
                            }
                        }
                        if(str[k]=='-'){
                            if(i<k){
                                int t2=(t1+(1<<k));
                                int nextj=hash[t2];
                                dp[i+1][nextj]+=dp[i][j];
                            }
                        }
                    }
                }else flag++;
            }
            if(flag==num[i]){
                printf("!%d\n",i);
                flag=1;break;
            }
        }
        if(flag1){
            puts("0");
            continue;
        }
        int ans=dp[n][0];
        printf("%d\n",ans);
    }
    return 0;
}
/*
+-+-+-+-+-+-+-+-+-+-
*/
