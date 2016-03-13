#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=123456789;
int vis[100005][2];
int res[3][11];
int st,et;
queue<int> q;
void bfs(){
    while(!q.empty()) q.pop();
    q.push(st);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<3;i++){
            for(int j=0;j<10;j++){
                int tmp;
                if(i==0){
                    tmp=u*10+j;
                    if(tmp>et) continue;
                    int step=vis[u][1]+1;
                    int cost=vis[u][0]+res[i][j];
                    if(vis[tmp][0]>cost){
                        vis[tmp][0]=cost;
                        vis[tmp][1]=step;
                        q.push(tmp);
                    }else if(vis[tmp][0]==cost&&vis[tmp][1]>step){
                        vis[tmp][0]=cost;
                        vis[tmp][1]=step;
                        q.push(tmp);
                    }
                }
                if(i==1){
                    tmp=u+j;
                    if(tmp>et) continue;
                    int step=vis[u][1]+1;
                    int cost=vis[u][0]+res[i][j];
                    if(vis[tmp][0]>cost){
                        vis[tmp][0]=cost;
                        vis[tmp][1]=step;
                        q.push(tmp);
                    }else if(vis[tmp][0]==cost&&vis[tmp][1]>step){
                        vis[tmp][0]=cost;
                        vis[tmp][1]=step;
                        q.push(tmp);
                    }
                }
                if(i==2){
                    tmp=u*j;
                    if(tmp>et) continue;
                    int step=vis[u][1]+1;
                    int cost=vis[u][0]+res[i][j];
                    if(vis[tmp][0]>cost){
                        vis[tmp][0]=cost;
                        vis[tmp][1]=step;
                        q.push(tmp);
                    }else if(vis[tmp][0]==cost&&vis[tmp][1]>step){
                        vis[tmp][0]=cost;
                        vis[tmp][1]=step;
                        q.push(tmp);
                    }
                }
            }
        }
    }
}
int main(){
    int cas=1;
    while(scanf("%d%d",&st,&et)!=EOF){
        for(int i=0;i<3;i++){
            for(int j=0;j<10;j++) scanf("%d",&res[i][j]);
        }
        for(int i=0;i<100005;i++) vis[i][0]=vis[i][1]=inf;
        if(st>et){
            vis[0][0]=res[2][0];
            vis[0][1]=1;
            st=0;
        }else{
            vis[st][0]=0;
            vis[st][1]=0;
        }
        bfs();
        printf("Case %d: %d %d\n",cas++,vis[et][0],vis[et][1]);
    }
}
