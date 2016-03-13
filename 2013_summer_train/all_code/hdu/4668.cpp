#include<cstdio>
#include<cstring>
#define M 1000
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
int mat[M];
bool vis[M];
int crosspath(int u){
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(vis[v]){
            vis[v]=0;
            if(mat[v]==-1||crosspath(mat[v])){
                    mat[v]=u;
                    return 1;
            }
        }
    }
    return 0;
}
void hungary(int n){
    memset(mat,-1,sizeof(mat));
    for(int i=1;i<=n;i++){
        memset(vis,1,sizeof(vis));
        crosspath(i);
    }
    return ;
}
int road[M][2];
int ans[M];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=1;i<=m;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            g1.add(t1,t2);
            road[i][0]=t1;road[i][1]=t2;
        }
        hungary(n);
        int tsum=0;
        for(int i=1;i<=m;i++){
            int t1=road[i][0];int t2=road[i][1];
            if(mat[t2]!=t1){
                ans[tsum++]=i;
            }
        }
        printf("%d\n",tsum);
        for(int i=0;i<tsum;i++){
            if(i) printf(" %d",ans[i]);
            else printf("%d",ans[i]);
        }
        puts("");
    }
    return 0;
}
