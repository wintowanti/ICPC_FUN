#include<cstdio>
#include<cstring>
#define M 300000
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next,flag;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].flag=1;e[en].next=head[u];head[u]=en++;
    }
}g1;
int ans[M];
int en;
void dfs(int u){
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(g1.e[i].flag){
            g1.e[i].flag=0;
            g1.e[i^1].flag=0;
            dfs(v);
            ans[en++]=v;
        }
    }
}
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=0;i<m;i++){
            int u,v;scanf("%d%d",&u,&v);
            g1.add(u,v);g1.add(v,u);
            g1.add(u,v);g1.add(v,u);
        }
        en=0;
        dfs(1);
        ans[en++]=1;
        for(int i=0;i<en;i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
