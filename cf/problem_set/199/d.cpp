#include<cstdio>
#include<cstring>
#define M 100
#define mod 1000000007
using namespace std;
int cur;
int dp[2][M][2];
char map1[3][200000];
int main(){
    int n;while(~scanf("%d",&n)){
        for(int i=0;i<3;i++) scanf("%s",map1[i]);
        memset(dp,0,sizeof(dp));
        int m=3;
        int all=(1<<3)-1;
        cur=1;
        dp[0][all][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                    cur=cur^1;
                    int next=cur^1;
                    memset(dp[next],0,sizeof(dp[next]));
                for(int k=0;k<(1<<m);k++){
                    for(int k1=0;k1<2;k1++){
                        if(dp[cur][k][k1]==0) continue;
                        if(map1[j][i]=='X'||map1[j][i]=='O'){
                            if(k&(1<<(m-1))){
                                int t1=(k<<1)+1;t1&=all;
                                dp[next][t1][k1]+=dp[cur][k][k1];
                                dp[next][t1][k1]%=mod;
                            }
                        }
                        else if(map1[j][i]=='.'){
                            if(k&(1<<(m-1))){
                                int t1=(k<<1);t1&=all;
                                dp[next][t1][k1]+=dp[cur][k][k1];
                                dp[next][t1][k1]%=mod;
                                if((!(k&1))&&j){
                                    // heng fang
//                                    puts("heng*** fang");
                                    int flag=0;
                                    if(j==1&&map1[2][i]=='O') flag=1;
                                    if(j==2&&map1[0][i]=='O') flag=1;
                                    int t1=(k<<1)+3;t1&=all;
                                    dp[next][t1][k1|flag]+=dp[cur][k][k1];
                                    dp[next][t1][k1|flag]%=mod;
                                }
                            }
                            else{
                                int flag=0;
                                if(i>1  &&map1[j][i-2]=='O') flag=1;
                                if(i<n-1&&map1[j][i+1]=='O') flag=1;
                                // shu fang
//                                puts("shu fang");
//                                printf("%d^^^^\n",flag);
                                int t1=(k<<1)+1;t1&=all;
                                dp[next][t1][k1|flag]+=dp[cur][k][k1];
                                dp[next][t1][k1|flag]%=mod;
                            }
                        }
                    }
                }
            }
        }
        int ans=dp[cur^1][all][1];
        printf("%d\n",ans);
    }
    return 0;
}
/*
3
XXX
XXX
..O
*/
