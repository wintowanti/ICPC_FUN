#include<cstdio>
#include<cstring>
#include<iostream>
#define M 108
#define inf 0x3f3f3f3f
using namespace std;
int map1[M][M];
int map2[M][M];
int vis[M];
int vis2[M];
int dis[M];
int f(int n,int en){
    int tsum=0;
    memset(vis2,0,sizeof(vis2));
    memset(dis,inf,sizeof(dis));
    for(int i=1;i<=n;i++){
        dis[i]=map1[0][i];
//        printf("%d  ~~**\n",dis[i]);
    }
    vis2[0]=1;
    for(int i=0;i<en;i++){
//        printf("%d\n",tsum);
        int tmin=inf;
        int flag=0;
        for(int j=1;j<=n;j++){
            if(vis[j]==1) continue;
            if(vis2[j]==1) continue;
            if(dis[j]<tmin) tmin=dis[j],flag=j;
        }
        vis2[flag]=1;
        tsum+=dis[flag];
        for(int j=1;j<=n;j++){
            if(dis[j]>map1[flag][j]) dis[j]=map1[flag][j];
        }
    }
    return tsum;
}
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++){
            int t1;scanf("%d",&t1);
            vis[t1]=1;
        }
        int en=n-m;
        memset(map1,inf,sizeof(map1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&map1[i][j]);
                if(vis[i]){
//                    puts("~~~");
                    map1[0][j]=min(map1[0][j],map1[i][j]);
//                    printf("%d  ^^%d  \n",map1[i][j],map1[0][j]);
                }
                if(vis[j]){
//                    puts("~~");
                    map1[j][0]=min(map1[j][0],map1[i][j]);
                }
            }
        }
        int ans=f(n,en);
        printf("%d\n",ans);
    }
    return 0;
}
