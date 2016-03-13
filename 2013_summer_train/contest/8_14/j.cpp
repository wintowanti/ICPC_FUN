#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 2080
#define inf 0x3f3f3f3f
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next,cost;
    }e[M<<8];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int cost){
        e[en].u=u;e[en].v=v;e[en].cost=cost;e[en].next=head[u];head[u]=en++;
    }
}g1;
int min(int x,int y){
    if(x>y) return y;return x;
}
int dis[M/2][M/2];
int n;
struct S{
    int id,deadline;
    friend bool operator <(const S a,const S b){
        if(a.deadline<b.deadline) return 1;return 0;
    }
}s[M];
void folyd(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}
int cnt[M];
bool vis[M];
int crosspath(int u){
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(vis[v]){
            vis[v]=0;
            if(cnt[v]==-1||crosspath(cnt[v])){
                cnt[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int hungary(int n){
    memset(cnt,-1,sizeof(cnt));
    int tsum=0;
    for(int i=0;i<n;i++){
        if(g1.head[i]==-1) continue;
        memset(vis,1,sizeof(vis));
        if(crosspath(i)){
            tsum++;
        }
    }
    return tsum;
}
int main(){
    int n,m,r;while(~scanf("%d%d%d",&n,&m,&r)&&(n+m+r)){
        memset(dis,inf,sizeof(dis));
        for(int i=0;i<m;i++){
            int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);
            dis[t1][t2]=t3;dis[t2][t1]=t3;
        }
        for(int i=0;i<n;i++) dis[i][i]=0;
        folyd(n);
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                printf("%d  ",dis[i][j]);
//            }
//            puts("!");
//        }
        for(int i=0;i<r;i++){
            scanf("%d%d",&s[i].id,&s[i].deadline);
        }
        sort(s,s+r);
        g1.init();
        for(int i=0;i<r;i++){
            for(int j=i+1;j<r;j++){
                int t1=dis[s[i].id][s[j].id];
                if(t1+s[i].deadline<=s[j].deadline){
//                    printf("%d  %d+++\n",i,j);
                    g1.add(i,j,0);
                }
            }
        }
        int ans=hungary(r);
//        printf("%d!!\n",ans);
        printf("%d\n",r-ans);
    }
    return 0;
}
