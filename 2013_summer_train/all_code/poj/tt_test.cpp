#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#define M 1000020
#define N 1010
#define NV N
#define NE M
#define ll long long
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
ll map1[NV][NV];
ll tmax;
int tsum;
void floyd(int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(map1[i][j]>map1[i][k]+map1[k][j]){
                    map1[i][j]=map1[i][k]+map1[k][j];
                }
            }
        }
    }
 }
 int door[NV][2];
 int build(ll mid,int n){
    g1.init();
    int sp=0;
    int tp=2*n+1;
     for(int i=1;i<=n;i++){
        int t1=door[i][0];
        int t2=door[i][1];
        g1.add(sp,i,t1);
        g1.add(i+n,tp,t2);
        g1.add(i,i+n,inf);
     }
     for(int i=1;i<=n;i++){
        //    if(door[i][0]==0) continue;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(map1[i][j]<=mid){
                if(map1[i][j]>tmax) continue ;
                g1.add(i,j+n,door[i][0]);
            }
        }
     }
  //   printf("******\n");
     int t1=dinic(sp,tp);
  //   printf("%d\n",t1);
     if(t1<tsum) return 0;
     return 1;
 }
 ll binary(ll l,ll r,int n){
     ll tmin=inf*10000ll,mid;
     while(r>=l){
        mid=(l+r)>>1;
    //    printf("%I64d   %I64d   %I64d\n",l,r,mid);
        if(build(mid,n)){
            tmin=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
     }
     return tmin;
 }
 int main()
 {
     int n,m;
     while(~scanf("%d%d",&n,&m))
     {
          tsum=0;
         int tsum2=0;
         tmax=0;
         for(int i=1;i<=n;i++){
            scanf("%d%d",&door[i][0],&door[i][1]);
            tsum+=door[i][0];
            tsum2+=door[i][1];
         }
         memset(map1,inf,sizeof(map1));
         for(int i=0;i<m;i++){
//             printf("%d!!%d!\n",i,m);
            int t1,t2;
            ll t3;
            scanf("%d%d%I64d",&t1,&t2,&t3);
            if(map1[t1][t2]>t3) map1[t1][t2]=t3,map1[t2][t1]=t3;
            tmax+=2*t3;
//            printf("########");
         }
//         puts("******");
         if(tsum2<tsum){
            puts("-1");
            continue;
         }
         floyd(n);
         ll ans=binary(0,tmax,n);
         if(ans>tmax){
            puts("-1");
         }
        else{
            printf("%I64d\n",ans);
         }
     }
     return 0;
 }
