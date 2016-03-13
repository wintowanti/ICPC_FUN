#include<cstdio>
#include<cstring>
#define M 20000
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int dis[M];
void dfs(int u,int step){
    dis[u]=step;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        dfs(v,step+1);
    }
}
int main(){
    int n;while(~scanf("%d",&n)){
        dis[0]=0;
        g1.init();
        for(int i=1;i<=n;i++){
            int t1;
            scanf("%d",&t1);
            g1.add(t1,i);
        }
        dfs(0,0);
        int tmax=0;
        for(int i=1;i<=n;i++){
            if(dis[i]>tmax) tmax=dis[i];
        }
        printf("%d\n",tmax-1);
    }
}
