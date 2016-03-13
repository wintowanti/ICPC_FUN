#include<cstdio>
#include<cstring>
#define M 13
int dp[M][M][M][2];
void init(){
    int o[20];
    o[1]=1;
    for(int i=2;i<M;i++){
        o[i]=o[i-1]*10;
        o[i]%=13;
    }
    memset(dp,0,sizeof(dp));
    dp[0][0][0][0]=1;
    int n=10;
    for(int i=0;i<M;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<M;k++){
                for(int i1=0;i1<2;i1++){
                    for(int j1=0;j1<n;j1++){
                        int t1;
                        t1=(j1*o[i+1]+k)%13;
                        if(i1==0){
                            if(j==3&&j1==1){
                                dp[i+1][j1][t1][1]+=dp[i][j][k][i1];
                            }
                            else{
                                dp[i+1][j1][t1][0]+=dp[i][j][k][i1];
                            }
                        }
                        else{
                            dp[i+1][j1][t1][i1]+=dp[i][j][k][i1];
                        }
                    }
                }
            }
        }
    }
}
int w[M];
int f(int n){
    if(n==0) return 0;
    int len=0;
    while(n){
        w[++len]=n%10;n/=10;
    }
    int o[20];
    o[1]=1;
    for(int i=2;i<M;i++){
        o[i]=o[i-1]*10;
        o[i]%=13;
    }
//    printf("len is %d\n",len);
    int flag1=0,flag2=0;
    int tsum=0;
    for(int i=len;i>=1;i--){
        for(int j=0;j<w[i];j++){
            int t1=(13*10-flag2)%13;
//            printf("%d\n",t1);
            tsum+=dp[i][j][t1][1];
            if(flag1||(i!=len&&(w[i+1]==1&&j==3))){
                tsum+=dp[i][j][t1][0];
            }
        }
        if(i!=len){
            if(w[i+1]==1&&w[i]==3) flag1=1;
        }
        flag2+=w[i]*o[i];
        flag2%=13;
//        printf("%d!!!\n",flag2);
    }
    return tsum;
}
int main(){
    init();
//    printf("%d\n",100%13);
//    printf("%d~~",200%13);
//    printf("%d^^^^\n",3%13);
//    printf("%d  \n",dp[3][1][0][1]);
//    printf("   %d   **\n",dp[2][3][4][0]);
    int n;while(~scanf("%d",&n)){
        int ans=f(n+1);
        printf("%d\n",ans);
    }
    return 0;
}
