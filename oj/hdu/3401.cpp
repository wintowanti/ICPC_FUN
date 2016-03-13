#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#define inf 0x3f3f3f3f
#define M 2008
using namespace std;
int dp[M][M];
struct E{int n1;int cost;};
deque<E> dq[2];
int a[M][5];
int t,maxp,w;
void init(){
    memset(dp,-inf,sizeof(dp));
    while(!dq[0].empty()) dq[0].pop_front();
    while(!dq[1].empty()) dq[1].pop_front();
    dp[0][0]=0;
}
int yy_front(int id){
    if(dq[id].empty()) return -inf;
    E e1;e1=dq[id].front(); return e1.cost;
}
void yy_pop(int id,int n,int limit){
    while(!dq[id].empty()){
        E e1;e1=dq[id].front();
        if(abs(e1.n1-limit)>0) dq[id].pop_front();
        else break;
    }
}
void yy_insert(int id,int n,int cost){
    while(!dq[id].empty()){
        E e1=dq[id].back();
        if(e1.cost<=cost){
            dq[id].pop_back();
        }else break;
    }
    E e1;e1.n1=n;e1.cost=cost;
    dq[id].push_back(e1);
}
int main(){
    int cas;
    while(~scanf("%d",&cas)){
        while(cas--){
            init();
            scanf("%d%d%d",&t,&maxp,&w);
            for(int i=1;i<=t;i++) scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
            for(int i=0;i<=t;i++){
                for(int j=0;j<=maxp;j++){
                    printf("%d   ~~",dp[i][j]);
                }
                puts("");
            }
            for(int i=1;i<=t;i++){
                while(!dq[0].empty()) dq[0].pop_front();
                while(!dq[1].empty()) dq[1].pop_front();
                printf("%d\n",i);
                //buy
                for(int j=0;j<=maxp;j++){
                        printf("%d~~~\n",j);
                    dp[i][j]=max(dp[i-1][j],dp[i][j]);
                    yy_pop(0,j,a[i][2]);
                    if(i-w-1>=0){
                            printf("  @@%d   ~~~~%d   !!!\n",dp[i-w-1],dp[i-w-1]+(a[i][0]*maxp-j));
                        yy_insert(0,j,dp[i-w-1][j]+(a[i][0])*(maxp-j));
                    }
                    int t1=yy_front(0);
                    printf("%d^^^^^^\n",t1);
                    dp[i][j]=max(dp[i][j],t1-a[i][0]*(maxp-j));
                }
                printf("@@@@");
                //sell
                for(int j=0;j<=maxp;j++){
                    printf("%d~~~\n",j);
                    dp[i][j]=max(dp[i-1][j],dp[i][j]);
                    yy_pop(1,j,a[i][3]);
                    if(i-w-1>=0){
                        yy_insert(1,j,dp[i-w-1][j]+(a[i][1])*j);
                    }
                    int t1=yy_front(1);
                    dp[i][j]=max(dp[i][j],t1-a[i][1]*j);
                }
            }
            int ans=-inf;
            for(int i=0;i<=t;i++){
                for(int j=0;j<=maxp;j++){
                    printf("%d   ~~",dp[i][j]);
                }
                puts("");
            }
            for(int i=0;i<=maxp;i++){
                if(ans<dp[t][i]) ans=dp[t][i];
            }
            printf("%d##\n",ans);
        }
    }
}
