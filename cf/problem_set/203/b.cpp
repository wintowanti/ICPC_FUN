#include<cstdio>
#include<cstring>
#define M 100009
#define inf 0x3f3f3f3f
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M+2000];
    void init(){
        for(int i=0;i<M;i++) head[i]=-1;
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int a[M];
int b[M];
int vis[M];
int ans[M];
int dp[M];
bool vis2[M];
int dfs(int x){
    vis2[x]=0;
    if(dp[x]!=-1) return dp[x];
    if(a[x]==1){
        vis2[x]=1;
        return dp[x]=1;
    }
    int t1=-inf;
    for(int i=g1.head[x];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(vis2[v])
        t1=dfs(v);
    }
    vis2[x]=1;
    return dp[x]=t1+1;
}
void dfs2(int x,int level){
    ans[level]=x;
    if(a[x]==1) return ;
    for(int i=g1.head[x];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        dfs2(v,level+1);
    }
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<=n+1;i++)vis[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]),vis[b[i]]++;
        g1.init();
        for(int i=1;i<=n;i++){
            if(vis[b[i]]<=1&&b[i]!=0){
//                printf("%d!  %d!\n",b[i],i);
                g1.add(b[i],i);
            }
        }
//        printf("%d!!!\n",g1.en);
//        puts("~~~");
        for(int i=0;i<=n+2;i++) dp[i]=-1;
        memset(vis2,1,sizeof(vis2));
        for(int i=1;i<=n;i++){
            dfs(i);
        }
//        puts("!!!");
        int tmax=0;
        int flag=0;
        for(int i=1;i<=n;i++){
//            printf("~~~~%d!!!\n",dp[i]);
            if(dp[i]>tmax){
                tmax=dp[i];
                flag=i;
            }
        }
        dfs2(flag,0);
        printf("%d\n",tmax);
        for(int i=0;i<tmax;i++){
            if(i) printf(" %d",ans[i]);
            else printf("%d",ans[i]);
        }
        puts("");
    }
    return 0;
}
/*
5
0 0 0 0 1
5 1 2 3 4

*/
