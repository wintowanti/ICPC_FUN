#include<cstdio>
#include<cstring>
#define M 10
int dp[M][M];
using namespace std;
void init(){
    dp[0][0]=1;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<M;k++){
                if(j==4||k==4) continue;
                if(j==2&&k==6) continue;
                dp[i+1][k]+=dp[i][j];
            }
        }
    }
}
int w[M];
int f(int n){
    if(n==0) return 0;
    int len=0;
    while(n){
        w[++len]=n%10;
        n/=10;
    }
    int tsum=0;
    int flag=0;
    for(int i=len;i>=1;i--){
        for(int j=0;j<w[i];j++){
            if(j==4) continue;
            if(flag==1&&j==2) continue;
            tsum+=dp[i][j];
        }
        if(flag&&w[i]==2) break;
        if(w[i]==4) break;
        if(w[i]==6) flag=1;
        else flag=0;
    }
    return tsum;
}
int main(){
    init();
    int a,b;
    while(~scanf("%d%d",&a,&b)&&(a+b)){
        int ans1=f(b+1)-f(a);
        printf("%d\n",ans1);
    }
    return 0;
}
