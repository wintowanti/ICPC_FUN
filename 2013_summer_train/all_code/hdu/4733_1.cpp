#include<cstdio>
#include<cstring>
#define M 100010
#define N 1000000007
int dp[M][2][2][3];
char str1[M];
char str2[M];
int s(char p){
    if(p=='1') return 1;
    return 0;
}
int e(char p){
    if(p=='0') return 0;
    return 1;
}
int pre[M*40][2];
int change(int x,int y,int z,int u){
    return x*12+y*6+z*3+u;
}
int ans[M];
void pf(int n1,int n){
    if(n1==0){
        puts("Impossible");
    }
    else if(n1>1){
        printf("Ambiguous %d\n",n1);
    }
    else{
        int len=n;
        int flag=0;
        int t1=0  ;
        if(dp[n][0][0][1]==1){
            t1=change(n,0,0,1);
        }
        else if(dp[n][0][0][2]==1){
            t1=change(n,0,0,2);
        }
        else if(dp[n][1][0][1]==1){
            t1=change(n,1,0,1);
        }
        else if(dp[n][1][0][2]==1){
            t1=change(n,1,0,2);
        }
        while(len>0){
            ans[len--]=pre[t1][1];
            t1=pre[t1][0];
        }
        for(int i=1;i<=n;i++){
            if(ans[i]<30){
                printf("%d",ans[i]);
            }
            else{
                printf("%d",ans[i]-30);
            }
        }
        puts("");
        for(int i=1;i<=n;i++){
            if(ans[i]<30){
                printf("%d",ans[i]);
            }
            else{
                printf("%d",!(ans[i]-30));
            }
        }
        puts("");
    }
}
int main(){
    int cas;
    while(~scanf("%d",&cas)){
        for(int q=1;q<=cas;q++){
            scanf("%s",str1);
            scanf("%s",str2);
            memset(dp,0,sizeof(dp));
            dp[0][0][0][0]=1;
            int n=strlen(str1);
            for(int i=0;i<n;i++){
                for(int j=0;j<2;j++){
                    for(int k=0;k<2;k++){
                        for(int w=0;w<3;w++){
                            if(dp[i][j][k][w]<1) continue;
                            for(int j1=s(str1[i]);j1<=e(str1[i]);j1++){
                                for(int k1=s(str2[i]);k1<=e(str2[i]);k1++){
                                    if(w==0){
                                        if(j1==k1){
                                            int t1=k^j1;
                                            dp[i+1][j1][t1][0]+=dp[i][j][k][w];
                                            dp[i+1][j1][t1][0]%=N;
                                            int flag1=change(i,j,k,w);
                                            int flag2=change(i+1,j1,t1,0);
                                            pre[flag2][0]=flag1;
                                            pre[flag2][1]=j1;
                                        }
                                        if(j1!=k1){
                                            if(j1==k){
                                                dp[i+1][j1][0][1]+=dp[i][j][k][w];
                                                dp[i+1][j1][0][1]%=N;
                                                int flag1=change(i,j,k,w);
                                                int flag2=change(i+1,j1,0,1);
                                                pre[flag2][0]=flag1;
                                                pre[flag2][1]=j1+30;
                                            }
                                        }
                                    }
                                    else if(w==1){
                                        if(j1==k1&&j1==1){
                                            dp[i+1][j1][0][2]+=dp[i][j][k][w];
                                            dp[i+1][j1][0][2]%=N;
                                            int flag1=change(i,j,k,w);
                                            int flag2=change(i+1,j1,0,2);
                                            pre[flag2][0]=flag1;
                                            pre[flag2][1]=j1;
                                        }
                                    }
                                    else if(w==2){
                                        if(j1==k1&&j1==0){
                                            dp[i+1][j1][0][2]+=dp[i][j][k][w];
                                            dp[i+1][j1][0][2]%=N;
                                            int flag1=change(i,j,k,w);
                                            int flag2=change(i+1,j1,0,2);
                                            pre[flag2][0]=flag1;
                                            pre[flag2][1]=j1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            int tsum=0;
            for(int j=0;j<2;j++){
                tsum+=dp[n][j][0][1];
                tsum%=N;
                tsum+=dp[n][j][0][2];
                tsum%=N;
            }
            printf("Case #%d:\n",q);
            pf(tsum,n);
        }
    }
    return 0;
}
