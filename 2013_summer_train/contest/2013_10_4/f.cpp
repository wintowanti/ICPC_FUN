#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#define M 40000
#define N 3500
#define inf 0x3f3f3f3f
using namespace std;
int min(int x,int y){
    if(x>y) return y;return x;
}
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
int dis[N],dinic_sp,dinic_tp;
int bfs(){
    queue<int> q1;
    q1.push(dinic_sp);
    memset(dis,-1,sizeof(dis));
    dis[dinic_sp]=0;
    while(!q1.empty()){
        int u=q1.front();q1.pop();
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            if(dis[v]==-1&&g1.e[i].cap>0){
                dis[v]=dis[u]+1;
                q1.push(v);
            }
        }
    }
    if(dis[dinic_tp]==-1) return 0;
    return 1;
}
int dfs(int u,int tmax){
    if(u==dinic_tp){
        return tmax;
    }
    int tsum=0;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(dis[v]==dis[u]+1&&g1.e[i].cap>0){
            int t1=min(g1.e[i].cap,tmax-tsum);
            t1=dfs(v,t1);
            g1.e[i].cap-=t1;
            g1.e[i^1].cap+=t1;
            tsum+=t1;
        }
    }
    return tsum;
}
int dinic(int sp,int tp){
    dinic_sp=sp;dinic_tp=tp;
    int tsum=0;
    while(bfs()){
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
    while(~scanf("%d",&cas))
        while(cas--){
        scanf("%d%d",&n,&m);swap(n,m);
        int d1,f1,b1;scanf("%d%d%d",&d1,&f1,&b1);
        for(int i=0;i<n;i++){
            scanf("%s",map1[i]);
        }
//        puts("****");
        int ans=0;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(i==0||i==n-1||j==0||j==m-1){
                if(map1[i][j]=='.'){
                    ans+=f1;
                    map1[i][j]='#';
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
                    g1.add(pos,tp,0);
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
                    g1.add(sp,pos,0);
                }
            }
        }
//        for(int i=0;i<n;i++){
//            puts(map1[i]);
//        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int x1=i+o[k][0];
                int y1=j+o[k][1];
                if(judge(x1,y1)) continue;
                int pos1=i*n+j+1;
                int pos2=x1*n+y1+1;
                g1.add(pos1,pos2,b1);
            }
        }
        int ans1=dinic(sp,tp);
        printf("%d\n",ans+ans1);
    }
    return 0;
}
