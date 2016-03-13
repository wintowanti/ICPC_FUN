#include<cstdio>
#include<cstring>
#define M 1080
bool dp[2*M][M];
int a[M];
int b[M];
int c[M*2];
int main(){
    int n1,n2;while(~scanf("%d%d",&n1,&n2)&&(n1+n2)){
        for(int i=1;i<=n1;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n2;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n1+n2;i++) scanf("%d",&c[i]);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<n1+n2;i++){
            for(int j=0;j<=n1;j++){
                if(dp[i][j]==1){
                    int t1=j+1;
                    int t2=(i-j)+1;
                    if(c[i+1]==a[t1]&&t1<=n1){
                        dp[i+1][j+1]=1;
                    }
                    if(c[i+1]==b[t2]&&t2<=n2){
                        dp[i+1][j]=1;
                    }
                }
            }
        }
        if(dp[n1+n2][n1]){
            puts("possible");
        }
        else{
            puts("not possible");
        }
    }
    return 0;
}
