#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#define inf 0x3f3f3f3f
#define M 20
using namespace std;
int dp[1<<20];
int vis[1<<20];
int map1[M][M];
queue<int >q1;
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&map1[i][j]);
            }
        }
//        printf("!!!!\n");
        while(!q1.empty()) q1.pop();
        memset(dp,inf,sizeof(dp));
        memset(vis,1,sizeof(vis));
        for(int i=0;i<n;i++){
            int t1=i<<n;
            int t2=1<<i;
            dp[t1|t2]=0;
        //    printf("%d!!!!\n",t1|t2);
            q1.push(t1+t2);
        }
        while(!q1.empty()){
            int t1=q1.front();q1.pop();
            int t2=t1>>n;
            int t3=t1&((1<<n)-1);
            for(int i=0;i<n;i++){
                if((~t3)&(1<<i)){
                 //   printf("%d   %d*  dp is %d*\n",t1,i,dp[t1]);
                //    system("pause");
                    int t5=(i<<n)|t3|(1<<i);
                    int t4=dp[t1]+map1[t2][i];
                    if(t4<dp[t5]){
                        dp[t5]=t4;
                        if(vis[t5]){
                            vis[t5]=0;
                            q1.push(t5);
                        }
                    }
                }
            }
            vis[t1]=1;
        }
        int tmin=inf;
        for(int i=0;i<n;i++){
            int t1=i<<n;
            int t2=(1<<n)-1;
            if(dp[t1+t2]<tmin) tmin=dp[t1+t2];
        }
        printf("%d\n",tmin);
    }
    return 0;
}
/*
2
-1 9794
2724
3
-1 212213 1
234234 -1 1000
123123  3   -1
*/
