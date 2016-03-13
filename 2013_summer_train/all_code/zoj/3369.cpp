#include<cstdio>
#include<cstring>
#define M 60
using namespace std;
int dp[M][M][M];
struct P{
    int j,k;
    char change;
}pre[M][M][M];
int a[M][3];
int main(){
    int n,h,s,p,m;
    while(~scanf("%d%d%d%d%d",&n,&h,&s,&p,&m)){
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        }
        memset(dp,0,sizeof(dp));
        dp[0][0][m]=h;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                for(int k=0;k<=m;k++){
                    int ts=j+s;
                    int tp=(i-j)+p;
                    int th=dp[i][j][k];
                    if(th!=0){
                        printf("%d   ~~~\n",th);
                    }
                    if(th>(2*a[i+1][0]-ts)&&ts>=a[i+1][0]){
                        int nxh=th-2*a[i+1][0]+ts;
                        if(dp[i+1][j+1][k]<nxh){
                            dp[i+1][j+1][k]=nxh;
                            pre[i+1][j+1][k].j=j;
                            pre[i+1][j+1][k].k=k;
                            pre[i+1][j+1][k].change='D';
                        }
                    }
                    if(tp>=a[i+1][1]&&k>=a[i+1][2]){
                        int nexm=k-a[i+1][2];
                        if(dp[i+1][j][nexm]<th){
                            dp[i+1][j][nexm]=th;
                            pre[i+1][j][nexm].j=j;
                            pre[i+1][j][nexm].k=k;
                            pre[i+1][j][nexm].change='E';
                        }
                    }
                }
            }
        }
        for(int i=0;i<=n;i++){
            printf("this is %d\n\n",i);
            for(int j=0;j<=i;j++){
                for(int k=0;k<=m;k++){
                    printf("%d  ",dp[i][j][k]);
                }
                puts("");
            }
        }
        int flag=-1,flagj,flagk;
        for(int j=0;j<=n;j++){
            for(int k=0;k<=m;k++){
                if(dp[n][j][k]>0){
                    flag=1;flagj=j;flagk=k;
                    break;
                }
            }
        }
        if(flag==-1){
            puts("UNLUCKY");
        }else{
            printf("can\n");
        }
    }
    return 0;
}
