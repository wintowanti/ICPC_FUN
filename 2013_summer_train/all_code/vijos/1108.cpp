#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define M 100
#define inf 0x3f3f3f3f
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,cost,next;
    }e[M<<5];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v,int cost){
        e[en].u=u;e[en].v=v;e[en].cost=cost;e[en].next=head[u];head[u]=en++;
    }
}g1;
int dis[M];
int need[M];
int has[M];
bool vis[M];
int count1[M];
queue<int > q1;
int relax(int v,int u,int cost){
    if(dis[v]<dis[u]+cost){
        dis[v]=dis[u]+cost;
        return 1;
    }
    return 0;
}
int spfa(int sp,int n){
    while(!q1.empty()) q1.pop();
    memset(dis,-inf,sizeof(dis));
    memset(vis,1,sizeof(vis));
    memset(count1,0,sizeof(count1));
    dis[sp]=0;vis[sp]=0;
    q1.push(sp);
    while(!q1.empty()){
        int u=q1.front();q1.pop();
//      if(16==16)  printf("\n$$$$$$$$$   %d!!!!\n",u);
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            int cost=g1.e[i].cost;
//            if(u==16) printf("\n*%d  ***%d   %d    %d    %d!!\n",u,dis[u],v,dis[v],cost);
            if(relax(v,u,cost)){
                if(vis[v]){
                    count1[v]++;
                    if(count1[v]>n) {
                        return 0;
//                        printf("**************************\n");
                    }
                    vis[v]=0;
                    q1.push(v);
                }
            }

        }
        vis[u]=1;
    }
    return 1;
}
int build(int mid){
    g1.init();
    for(int i=0;i<23;i++){
        g1.add(i,i+1,0);
    }
    for(int i=1;i<24;i++){
        g1.add(i,i-1,-has[i]);
    }
    for(int i=8;i<24;i++){
        g1.add(i-8,i,need[i]);
    }
    for(int i=0;i<8;i++){
//        if(need[i]-mid!=0) printf("\n%d   %d ^  %d^\n\n",i+16,i,need[i]-mid);
        g1.add(i+16,i,need[i]-mid);
    }
    g1.add(24,0,0);
    g1.add(0,24,-has[0]);
    g1.add(24,23,mid);
    int ans=spfa(24,24);
//    for(int i=0;i<=24;i++){
//        printf("%d   %d~~~   ",i,dis[i]);
//    }
//    puts("*************************");
    return ans;
}
int binary(int l,int r){
    int mid,tmin=inf;
    while(l<=r){
        mid=(l+r)>>1;
//        printf("\n%d  !!***!\n",mid);
        if(build(mid)){
            tmin=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return tmin;
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            for(int i=0;i<24;i++) scanf("%d",&need[i]);
            int m;scanf("%d",&m);
            memset(has,0,sizeof(has));
            for(int i=0;i<m;i++){
                int t1;scanf("%d",&t1);has[t1]++;
            }
            int tsum=0;
            for(int i=0;i<24;i++) tsum+=has[i];
            int ans=binary(0,tsum);
            if(ans==inf){
                puts("No Solution");
            }
            else{
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
/*
1
1 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 1
5
0
23
22
1
10
1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1
17
*/
