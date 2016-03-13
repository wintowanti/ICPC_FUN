#include<cstdio>
#include<cstring>
#include<queue>
#define M 208
#define inf 0x3f3f3f3f
using namespace std;
bool vis[M][M];
int dis[20][20];
int dp[1<<17][17];
int hash[M][M];
int n,m;
int judge(int x,int y){
    if(x<0||x>n-1||y<0||y>m-1) return 0;
    return 1;
}
int map1[M][M];
int o[4][2]={
    0,-1,
    0,1,
    1,0,
    -1,0
};
struct E{
    int x,y,step;
    bool friend operator <(const E a,const  E b){
        if(a.step>=b.step) return 1;
        return 0;
    }
};
priority_queue<E>q1;
void bfs(int sx,int sy,int id,int flag){
//    printf("%d    %d    %d   %d~~~~\n",sx,sy,id,flag);
    while(!q1.empty()) q1.pop();
    int num=0;
    E e1,e2;
    e1.x=sx;e1.y=sy;
    e1.step=map1[sx][sy];
    memset(vis,1,sizeof(vis));
    vis[sx][sy]=0;
    if(e1.step==-1) return ;
    q1.push(e1);
    while(!q1.empty()){
        e1=q1.top();q1.pop();
        if(hash[e1.x][e1.y]!=-1){
            int t1=hash[e1.x][e1.y];
            dis[id][t1]=e1.step;
            dis[t1][id]=e1.step;
            num++;
        }
        if(num==flag) return ;
        for(int i=0;i<4;i++){
            int x1=e1.x+o[i][0];
            int y1=e1.y+o[i][1];
            if(judge(x1,y1)==0){
                if(dis[id][0]==inf){
                    dis[id][0]=e1.step;
                    dis[0][id]=e1.step;
                    num++;
                }
                continue;
            }
            if(map1[x1][y1]==-1) continue;
            if(vis[x1][y1]){
                vis[x1][y1]=0;
                e2.x=x1;
                e2.y=y1;
                e2.step=e1.step+map1[x1][y1];
                q1.push(e2);
            }
        }
    }
}
void floed(int n){
    for(int k=0;k<=n;k++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}
struct E1{
    int t1,pre;
};
queue<E1 > qq1;
bool vis1[1<<17][17];
int cost1[300];
int cout(int x){
    int tsum=0;
    while(x){
        if(x&1) tsum++;
        x>>=1;
    }
    return tsum;
}
//int work(int m){
//    memset(vis1,1,sizeof(vis1));
//    memset(dp,inf,sizeof(dp));
//    while(!qq1.empty()) qq1.pop();
//    E1 e1,e2;
//    for(int i=0;i<=m;i++){
//        int t1=1<<i;
//        dp[t1][i]=dis[0][i];
//        e1.t1=t1;
//        e1.pre=i;
//        qq1.push(e1);
//        vis[t1][i]=0;
//    }
//    while(!qq1.empty()){
//        e1=qq1.front();qq1.pop();
//        int t1=e1.t1;
//        int pre=e1.pre;
//        if(e1.pre==0) continue;
//        for(int i=0;i<=m;i++){
//            int oo=1<<(i);
//            if(!(t1&(oo))){
//                int t3=t1+oo;
//                int t2=dp[t1][pre]+dis[pre][i]-cost1[pre];
//                if(dp[t3][i]>t2){
//                    dp[t3][i]=t2;
//                    e2.t1=t3;
//                    e2.pre=i;
//                    qq1.push(e2);
//                }
//            }
//        }
//        vis[t1][pre]=1;
//    }
////    printf("%d   ~~\n",dp[3][0]);
//    int tmin=0;
//    int tmax=0;
//    for(int i=0;i<(1<<(m+1));i++){
//        int t1=cout(i);
//        if(dp[i][0]==inf) continue;
//        if(t1>tmax){
//            tmax=t1;
//            tmin=dp[i][0];
//        }
//        else if(t1==tmax){
//            if(dp[i][0]<tmin) tmin=dp[i][0];
//        }
//    }
//    printf("%d   ~~   %d\n",tmin,tmax);
//    return tmin;
//}
int work(int m){
    memset(dp,inf,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<1<<(m+1);i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                if(j!=0) continue;
                for(int k=0;k<=m;k++){
                    int oo=1<<k;
                    if((oo&i)==0){
                        int t1=i+oo;
                        int t2=dp[i][j]+dis[j][k]-cost1[j];
                        if(t2<dp[t1][k]){
                            dp[t1][k]=t2;
                        }
                    }
                }
            }
            else{
                if(dp[i][j]==inf) continue;
                for(int k=0;k<=m;k++){
                    int oo=1<<k;
                    if((oo&i)==0){
                        int t1=i+oo;
                        int t2=dp[i][j]+dis[j][k]-cost1[j];
                        if(t2<dp[t1][k]){
                            dp[t1][k]=t2;
                        }
                    }
                }
            }
        }
    }
    int tmax=0;
    int tmin=0;
    for(int i=0;i<(1<<(m+1));i++){
        if(dp[i][0]==inf) continue;
        int t1=cout(i);
        if(t1>tmax){
            tmax=t1;
            tmin=dp[i][0];
        }
        else if(t1==tmax){
            if(dp[i][0]<tmin) tmin=dp[i][0];
        }
    }
    return tmin;
}
int main(){
    int cas;
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&cas)){
        while(cas--){
            scanf("%d%d",&n,&m);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    scanf("%d",&map1[i][j]);
                }
            }
            int m1;scanf("%d",&m1);
            memset(hash,-1,sizeof(hash));
            cost1[0]=0;
            for(int i=1;i<=m1;i++){
                int x,y;scanf("%d%d",&x,&y);
                hash[x][y]=i;
                cost1[i]=map1[x][y];
            }
            memset(dis,inf,sizeof(dis));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(hash[i][j]!=-1){
//                        printf("%d  %d*****\n",i,j);
                        bfs(i,j,hash[i][j],m1+1);
                    }
                }
            }
            dis[0][0]=0;
//            for(int i=0;i<=m1;i++){
//                for(int j=0;j<=m1;j++){
//                    printf("%d   ",dis[i][j]);
//                }
//                puts("");
//            }
//            puts("~~~~~~~~~~~~~~~~~");
          //  floed(m1);
//            for(int i=0;i<=m1;i++){
//                for(int j=0;j<=m1;j++){
//                    printf("%d   ",dis[i][j]);
//                }
//                puts("");
//            }
            int ans=work(m1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
