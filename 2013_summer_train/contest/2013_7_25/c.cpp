#pragma comment(linker,"/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
#include<iostream>
#define M 400000
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,flag,next;
    }e[M<<4];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];e[en].flag=1;head[u]=en++;
    }
}g1,g2,g3;
int subid[M];
int is_cut[M];
int pre[M];
int low[M];
int dis[M];
int dfs_clock;
int subnum;
int dfs1(int u,int fa){
//    printf("%d^^   %d\n",u,fa);
    int lowu=pre[u]=++dfs_clock;
    int child=0;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
//        printf("v is %d*****\n",v);
        if(!pre[v]){
            child++;
            int lowv=dfs1(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u]){
//                printf("%d!!!%d \n",pre[u],lowv);
                is_cut[u]=1;
            }
            if(lowv>pre[u]){
//                printf("%d   %d\n",u,v);
                  g1.e[i].flag=0;
                g1.e[i^1].flag=0;
            }
        }
        else if(pre[v]<pre[u]&&v!=fa){
//            printf("!!!!%d   \n",v);
            lowu=min(lowu,pre[v]);
        }
    }
    if(fa<0&&child==1) is_cut[u]=0;
    low[u]=lowu;
    return low[u];
}
void dfs2(int u){
    pre[u]=++dfs_clock;
    subid[u]=subnum;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(!pre[v]&&g1.e[i].flag){
            dfs2(v);
        }
    }
}
void dfs3(int u,int cost){
    dis[u]=cost;
    for(int i=g2.head[u];i!=-1;i=g2.e[i].next){
        int v=g2.e[i].v;
        if(dis[v]==-1){
            dfs3(v,cost+1);
        }
    }
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)&&(n+m)){
        g1.init();
        for(int i=0;i<m;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            g1.add(t1,t2);
            g1.add(t2,t1);
        }
        dfs_clock=0;
        memset(is_cut,0,sizeof(is_cut));
        memset(pre,0,sizeof(pre));
        memset(low,0,sizeof(low));
        for(int i=1;i<=n;i++){
            if(!pre[i])
            dfs1(i,-1);
        }
        subnum=0;
        dfs_clock=0;
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=n;i++){
            if(!pre[i]){
                subnum++;
                dfs2(i);
            }
        }
//        for(int i=1;i<=n;i++){
//            printf("i is %d  subid is  %d \n",i,subid[i]);
//        }
        g2.init();
        for(int i=0;i<g1.en;i++){
            int t1=g1.e[i].u;
            int t2=g1.e[i].v;
            t1=subid[t1];
            t2=subid[t2];
            if(t1!=t2){
              //  printf("%d~~~~%d~~\n",t1,t2);
                g2.add(t1,t2);
                g2.add(t2,t1);
            }
        }
        memset(dis,-1,sizeof(dis));
        for(int i=1;i<=subnum;i++){
            if(dis[i]==-1){
                dfs3(i,0);
            }
        }
        int root=0;
        int tmax=0;
        for(int i=1;i<=subnum;i++){
            if(dis[i]>=tmax){
                tmax=dis[i];
                root=i;
            }
        }
        memset(dis,-1,sizeof(dis));
        dfs3(root,0);
        tmax=0;
        for(int i=1;i<=subnum;i++){
            if(dis[i]>tmax){
                tmax=dis[i];
            }
        }
        int ans=subnum-1-tmax;
        printf("%d\n",ans);
    }
    return 0;
}
