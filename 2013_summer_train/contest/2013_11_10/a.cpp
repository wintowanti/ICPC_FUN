#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#define M 1050002
#define N 20050
#define inf 0x3f3f3f3f
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
struct G{
    int head[N],en;
    struct E{
        int u,v,cap,next;
    }e[M];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int cap){
        e[en].u=u;e[en].v=v;e[en].cap=cap;e[en].next=head[u];head[u]=en++;
        e[en].u=v;e[en].v=u;e[en].cap=0  ;e[en].next=head[v];head[v]=en++;
    }
}g1;
int dis[N],dinic_sp,dinic_tp,cur[N];
int my_que[N];
int bfs(){
    int hp=0,tp=-1;
    my_que[++tp]=dinic_sp;
    memset(dis,0,sizeof(dis));
    dis[dinic_sp]=1;
    while(hp<=tp){
        int u=my_que[hp++];
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            if(!dis[v]&&g1.e[i].cap>0){
                dis[v]=dis[u]+1;
                my_que[++tp]=v;
            }
        }
    }
   return dis[dinic_tp];
}
int dfs(int u,int tmax){
    if(u==dinic_tp||tmax==0){
        return tmax;
    }
    int tsum=0,f;
    for(int  & i=cur[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(dis[v]==dis[u]+1&& (f=dfs(v,min(tmax,g1.e[i].cap)))){
            g1.e[i].cap-=f;
            g1.e[i^1].cap+=f;
            tmax-=f;
            tsum+=f;
            if(!tmax) break;
        }
    }
    return tsum;
}
int dinic(int sp,int tp){
    dinic_sp=sp;dinic_tp=tp;
    int tsum=0;
    while(bfs()){
        for(int i=0;i<=tp;i++) cur[i]=g1.head[i];
        tsum+=dfs(sp,inf);
    }
    return tsum;
}
char map1[60][60];
int n,m;
int o[4][2]={
    0,1,
    0,-1,
    1,0,
    -1,0
};
int judge(int x,int y){
    if(x<0||x>n-1||y<0||y>m-1) return 1;
    return 0;
}
int main() {
    int cas;
  //  while(~scanf("%d",&cas))
        scanf("%d",&cas);
		while(cas--){
        scanf("%d%d",&m,&n);
        int d1,f1,b1;scanf("%d%d%d",&d1,&f1,&b1);
        for(int i=0;i<n;i++){
            scanf("%s",map1[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
	            if(i==0||i==n-1||j==0||j==m-1){
	                if(map1[i][j]=='.'){
	                    ans+=f1;
	                    map1[i][j]='#';
	                }
	            }
			}
        }
        g1.init();
        int sp=0;
        int tp=n*m+1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map1[i][j]=='#'){
                    int pos=i*n+j+1;
                    if(i==0||i==n-1||j==0||j==m-1){
                      g1.add(sp,pos,inf);
                    }
                    else{
                        g1.add(sp,pos,d1);
                    }
                }
                else{
                    int pos=i*n+j+1;
                    g1.add(pos,tp,f1);
                }
            }
        }
        for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
	            for(int k=0;k<4;k++){
	                int x1=i+o[k][0];
	                int y1=j+o[k][1];
	                if(judge(x1,y1)) continue;
	                int pos1=i*n+j+1;
	                int pos2=x1*n+y1+1;
	                g1.add(pos1,pos2,b1);
	            }
			}
        }
        int ans1=dinic(sp,tp);
        printf("%d\n",ans+ans1);
    }
    return 0;
}
