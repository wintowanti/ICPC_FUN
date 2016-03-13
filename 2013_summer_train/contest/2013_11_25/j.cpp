#include<cstdio>
#include<cstring>
#define M 208
#define mt(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,m;
int dp[M][M];
int value[M];
int tmp[2][M];
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<3];
    void init(){
        mt(head,-1);
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
void flash_dp(int u,int v){
    mt(tmp,0);
    for(int i=0;i<=m;i++) tmp[0][i]=dp[u][i],tmp[1][i]=dp[u][i];
    for(int i=0;i<=m;i++){
        int up=dp[v][i];
//        printf("%d^~~~~~~^^^\n",up);
        for(int j=1;j+i<=m;j++){
            if(tmp[1][j+i]<tmp[0][j]+up) tmp[1][j+i]=tmp[0][j]+up;
        }
    }
    for(int i=0;i<=m;i++){
        dp[u][i]=tmp[1][i];
    }
}
void dfs(int u){
    dp[u][1]=value[u];
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        dfs(v);
        flash_dp(u,v);
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)&&(n+m)){
        m++;
        mt(dp,0);
        mt(value,0);
        g1.init();
        for(int i=1;i<=n;i++){
            int fa;scanf("%d%d",&fa,&value[i]);
            g1.add(fa,i);
        }
        dfs(0);
        printf("%d\n",dp[0][m]);
//        for(int j=0;j<=n;j++){
//            printf("this is %d\n",j);
//            for(int i=0;i<=m;i++){
//                printf("%d    ",dp[j][i]);
//            }
//            puts("");
//        }
    }
    return 0;
}
/*
3 2
0 1
0 2
0 3
*/
