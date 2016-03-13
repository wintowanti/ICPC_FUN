#include<cstdio>
#include<cstring>
#include<queue>
#define M 109
#define inf 0x3f3f3f3f
using namespace std;
int vis[M][M*3];
int dis[M][M];
int ans,has;
int cost1[M];
int cost2[M];
struct E{
    int x,cost,value;
    bool friend operator<(E  a,E b){
        if(a.cost>=b.cost) return 1;
        return 0;
    }
};
priority_queue<E> q1;
void floey(int n){
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
int bfs(int sp,int tp){
    while(!q1.empty()) q1.pop();
    memset(vis,-inf,sizeof(vis));
    vis[sp][0]=0;
    E e1,e2;
    e1.x=sp;e1.value=0;e1.cost=0;
    q1.push(e1);
    while(!q1.empty()){
        e1=q1.top();q1.pop();
//        printf("%d   %d    %d\n",e1.x,e1.cost,e1.value);
        if(e1.cost>has) continue;
        if(e1.x==tp){
            if(e1.value>ans) ans=e1.value;
        }
        for(int i=1;i<=tp;i++){
            if(cost2[i]<=cost2[e1.x]) continue;
            e2.x=i;
            e2.cost=e1.cost+dis[e1.x][e2.x]+cost1[i];
            e2.value=e1.value+cost2[i];
            if(i==tp) e2.value=e1.value;
            if(e2.cost>has) continue;
            if(e2.value>vis[i][e2.cost]){
                vis[i][e2.cost]=e2.value;
                q1.push(e2);
            }
        }
    }
    return ans;
}
int main(){
    int cas;
    while(~scanf("%d",&cas)){
        for(int q=1;q<=cas;q++){
            memset(dis,inf,sizeof(dis));
            int n,st,tt,m;
            scanf("%d%d%d%d%d",&n,&m,&has,&st,&tt);n++;
            dis[0][st+1]=0;
            dis[st+1][0]=0;
            dis[tt+1][n]=0;
            dis[n][tt+1]=0;
            for(int i=1;i<n;i++){
                scanf("%d",&cost1[i]);
            }
            for(int i=1;i<n;i++){
                scanf("%d",&cost2[i]);
            }
            cost1[0]=-inf;
            cost2[0]=-inf;
            cost1[n]=0;
            cost2[n]=inf;
            for(int i=0;i<m;i++){
                int u,v,t1;
                scanf("%d%d%d",&u,&v,&t1);
                u++;v++;
                if(dis[u][v]>t1){
                    dis[u][v]=t1;
                    dis[v][u]=t1;
                }
            }
            floey(n);
            ans=0;
//            printf(" n is %d\n",n);
//            for(int i=0;i<=n;i++){
//                for(int j=0;j<=n;j++){
//                    printf("%d  ",dis[i][j]);
//                }
//                puts("~~~\n");
//            }
            bfs(0,n);
            printf("Case #%d:\n%d\n",q,ans);
        }
    }
    return 0;
}
/*
1
4 4 9 0 3
1 1 1 1
5 7 9 12
0 1 10
1 3 10
0 2 10
2 3 10
10
4 4 0 0 3
0 0 0 0
5 7 9 12
0 1 0
1 3 0
0 2 0
2 3 0
*/
