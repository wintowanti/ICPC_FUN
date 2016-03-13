#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#define M 10000
#define N 500
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
int my_que[N<<2];
int bfs(){
    int hpp=0;int tpp=-1;
//    q1.push(dinic_sp);
    my_que[++tpp]=dinic_sp;
    memset(dis,-1,sizeof(dis));
    dis[dinic_sp]=0;
    while(hpp<=tpp){
        int u=my_que[hpp++];
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            if(dis[v]==-1&&g1.e[i].cap>0){
                dis[v]=dis[u]+1;
                my_que[++tpp]=v;
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
char str[100][100];
bool build(int n,int mid,int k){
    int sp=0,tp=4*n+1;
    g1.init();
    int tsum=mid*n;
    for(int i=1;i<=n;i++){
        g1.add(sp,i,mid);
        g1.add(i,i+n,k);
        g1.add(i+3*n,tp,mid);
        g1.add(i+2*n,i+3*n,k);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(str[i][j]=='Y'){
                g1.add(i+1,j+1+3*n,1);
            }
            else{
                g1.add(i+1+n,j+1+2*n,1);
            }
        }
    }
    int t1=dinic(sp,tp);
//    printf("!!!!!%d\n",t1);
    if(t1==tsum) return 1;
    return 0;
}
int binary(int l,int r,int n,int k){
    int tmax=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(build(n,mid,k)){
            tmax=mid;l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return tmax;
}
int main(){
    int n,k;while(~scanf("%d%d",&n,&k)){
        for(int i=0;i<n;i++) scanf("%s",str[i]);
        int ans=binary(0,n,n,k);
        printf("%d\n",ans);
    }
    return 0;
}
