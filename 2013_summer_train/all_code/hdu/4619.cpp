#include<cstdio>
#include<cstring>
#define M 1001
#define N 30080
using namespace std;
struct G{
    int head[M*M],en;
    struct E{
        int u,v,next;
    }e[M*M];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
bool vis[N<<2];
int mat[N<<2];
int change(int x,int y){
    return x*110+y;
}
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
int hungary(int n){
    int tsum=0;
    memset(mat,-1,sizeof(mat));
    for(int i=0;i<=n;i++){
        if(g1.head[i]==-1) continue;
        memset(vis,1,sizeof(vis));
        if(crosspath(i)){
      //      printf("%d\n",i);
            tsum++;
        }
    }
    return tsum;
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)&&(n+m)){
        g1.init();
        for(int i=0;i<n;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            int t3,t4;t3=t1+1;t4=t2;
            int f1=change(t1,t2);
            int f2=change(t3,t4);
//            printf("%d  %d\n",f1,f2+N/2);
//            printf("%d  %d\n",f2,f1+N/2);
            g1.add(f1,f2+M/2);
            g1.add(f2,f1+M/2);
        }
        for(int i=0;i<m;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            int t3,t4;t3=t1;t4=t2+1;
            int f1=change(t1,t2);
            int f2=change(t3,t4);
            g1.add(f1,f2+M/2);
            g1.add(f2,f1+M/2);
//            printf("%d  %d\n",f1,f2);
        }
        int ans=hungary(N+3);
      //  printf("%d\n",ans);
        printf("%d\n",ans/2);
    }
    return 0;
}
/*
2 1
0 0
1 1
1 0
*/
