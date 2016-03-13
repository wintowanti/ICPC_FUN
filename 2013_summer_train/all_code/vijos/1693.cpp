#include<cstdio>
#include<cstring>
#define M 1000
int max(int x,int y){
    if(x>y) return x;return y;
}
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
bool vis[M];
int mat[M];
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
    memset(mat,-1,sizeof(mat));
    int tsum=0;
    for(int i=1;i<=n;i++){
        memset(vis,1,sizeof(vis));
        if(crosspath(i)){
            tsum++;
        }
    }
    return tsum;
}
int change(int t1){
    int i=0;
    while(t1){
        i++;
        t1>>=1;
    }
    i=(1<<i)-1;
    return i;
}
int a[M];
int b[M];
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        g1.init();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int t1=max(a[i],b[j]);
                t1=change(t1);
                int t2=t1&(~a[i]);
                int t3=t1&b[j];
            //    printf("%d  %d  %d~~~\n",t1,t2,t3);
                if(t2==t3){
                    g1.add(i,j+n);
                    g1.add(j+n,i);
                   // printf("%d  %d\n",i,j);
                }
            }
        }
        int ans=hungary(n+m);
        printf("%d\n",ans/2);
    }
    return 0;
}
