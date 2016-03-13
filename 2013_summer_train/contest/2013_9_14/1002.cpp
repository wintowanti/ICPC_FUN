#include<cstdio>
#include<cstring>
#define M 7000
int dp[12][12][M];
int tsum[12][12][M];
void init(){
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    int n=10;
    for(int i=0;i<12;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<M-1;k++){
                for(int k1=0;k1<n;k1++){
                    int t1=k+k1*(1<<i);
                    dp[i+1][k1][t1]+=dp[i][j][k];
                }
            }
        }
    }
    memset(tsum,0,sizeof(tsum));
    for(int i=1;i<12;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<M-1;k++){
                tsum[i][j][k]=tsum[i][j][k-1]+dp[i][j][k];
            }
        }
    }
}
int w[20];
int f(int x,int fa){
    if(x==0) return 0;
    int len=0;
    int flag=0;
    while(x){
        w[++len]=x%10;
        x/=10;
    }
    int tsum1=0;
    for(int i=len;i>=1;i--){
        for(int k=0;k<w[i];k++){
            tsum1+=tsum[i][k][fa-flag];
        }
        flag+=(w[i])*(1<<(i-1));
        if(fa<flag) break;
//        printf("%d   !!\n",flag);
    }
    return tsum1;
}
int main(){
    init();
    int cas;
    while(~scanf("%d",&cas)){
        for(int q=1;q<=cas;q++){
            int a,b;scanf("%d%d",&a,&b);
            int len=0;
            int fa=0;
            while(a){
                int t1=a%10;
                fa+=(1<<(len))*t1;
                len++;
                a/=10;
            }
//            printf("fa is %d  ~\n",fa);
            int ans=f(b+1,fa);
            printf("Case #%d: %d\n",q,ans);
        }
    }
    return 0;
}
