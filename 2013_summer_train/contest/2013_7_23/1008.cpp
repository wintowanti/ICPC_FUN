#include<cstdio>
#include<cstring>
#define M 100800
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<3];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int dis[M];
void dfs(int u,int cost){
    dis[u]=cost;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(dis[v]==-1){
            dfs(v,cost+1);
        }
    }
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            int n,m;
            scanf("%d%d",&n,&m);
            g1.init();
            for(int i=0;i<n-1;i++){
                int t1,t2;scanf("%d%d",&t1,&t2);
                g1.add(t1,t2);
                g1.add(t2,t1);
            }
            memset(dis,-1,sizeof(dis));
            dfs(1,0);
            int tmax=0;
            int flag=0;
            for(int i=1;i<=n;i++){
                if(dis[i]>tmax){
                    tmax=dis[i];
                    flag=i;
                }
            }
            memset(dis,-1,sizeof(dis));
            dfs(flag,0);
                tmax=0;
            for(int i=1;i<=n;i++){
                if(dis[i]>tmax){
                    tmax=dis[i];
                }
            }
            tmax++;
         //   printf("%d\n",tmax);
            for(int i=0;i<m;i++){
                int t1;scanf("%d",&t1);
                if(t1<=tmax){
                    printf("%d\n",t1-1);
                }
                else{
                    t1=tmax+(t1-tmax)*2;
                    printf("%d\n",t1-1);
                }
            }
        }
    }
    return 0;
}
