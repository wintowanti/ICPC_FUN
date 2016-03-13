#include<cstdio>
#include<cstring>
#define M 1099
#define ll long long
ll dp[2][M];
int cur;
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        cur=1;
        int all=(1<<(m+1))-1;
        memset(dp,0,sizeof(dp));
        dp[0][all]=1;
        int o1=1<<(m);
        int o2=1<<(m-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cur=cur^1;
                int next=cur^1;
                memset(dp[next],0,sizeof(dp[next]));
                for(int k=0;k<(1<<(m+1));k++){
                    if(dp[cur][k]==0) continue;
//                    printf("%d^^^^\n",k);
                    // kong
                    if(k&o1){
//                        puts("kong");
                        int t1=(k<<1);t1&=all;
//                        printf("%d\n",t1);
                        dp[next][t1]+=dp[cur][k];
                    }
                    // heng fan
                    if(j>0){
//                        puts("heng fan");
                        if(k&o1){
                            if(!(k&1)){
                                int t1=(k<<1)+3;t1&=all;
                                dp[next][t1]+=dp[cur][k];
                            }
                        }
                    }
                    // shu fan
                    if(k&o1){
//                        puts("shu fan");
                        if(!(k&o2)){
                            int t1=(k<<1)+o1+1;t1&=all;
                            dp[next][t1]+=dp[cur][k];
                        }
                    }
                    // 4 zhong
                    if(j>0){
                        //1
                        if(k&o1){
                            if(!(k&o2)&&!(k&1)){
                                int t1=(k<<1)+o1+3;t1&=all;
                                dp[next][t1]+=dp[cur][k];
                            }
                        }
                        // 2
                        if(!(k&o1)){
                            if(!(k&1)){
                                int t1=(k<<1)+3;t1&=all;
                                dp[next][t1]+=dp[cur][k];
                            }
                        }
                        // 3
                        if(!(k&o1)){
                            if(!(k&o2)){
                                int t1=(k<<1)+1+o1;t1&=all;
                                dp[next][t1]+=dp[cur][k];
                            }
                        }
                        // 4
                        if(!(k&o1)){
                            if(!(k&o2)){
                                if(!(k&1)){
                                    int t1=(k<<1)+o1+2;t1&=all;
                                    dp[next][t1]+=dp[cur][k];
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%lld\n",dp[cur^1][all]);
    }
    return 0;
}
