#include<cstdio>
#include<cstring>
#include<iostream>
#define M 110001
#define inf 0x3f3f3f3f
using namespace std;
struct G1{
    int head[M],en;
    struct E{
        int u,v,next,flag;
    }e[M<<4];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].flag=0;
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
struct G2{
    int head[M],en;
    struct E{
        int u,v,next,cost;
    }e[M<<6];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int cost){
        e[en].cost=cost;
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g2;
int dis[M],ms[M],son[M],fa[M];
int my_que[M<<2],qh,qt;
int my_stk[M<<2],tp;
int find_root(int pos,int siz){
   qh=0;qt=-1;
   tp=-1;
   my_que[++qt]=pos;fa[pos]=0;
   int cen=0;ms[0]=siz;
   while(qt>=qh){
       int u=my_que[qh++];
       son[u]=1,ms[u]=0;
       for(int i=g1.head[u];~i;i=g1.e[i].next){
            int v=g1.e[i].v;
            if(g1.e[i].flag||v==fa[u]) continue;
            fa[v]=u;
            my_que[++qt]=v;
       }
       my_stk[++tp]=u;
    }
    while(tp>=0){
        int v=my_stk[tp--];
        son[fa[v]]+=son[v];
        if(ms[fa[v]]<son[v]) ms[fa[v]]=son[v];
        if(ms[v]<siz-son[v]) ms[v]=siz-son[v];
        if(ms[v]<ms[cen]) cen=v;
    }
    return cen;
}
void bfs(int pos){
    qh=0;qt=-1;
    my_que[++qt]=pos;
    dis[pos]=0; fa[pos]=0;
    while(qt>=qh){
        int u=my_que[qh++];
        g2.add(u,pos,dis[u]);
        for(int i=g1.head[u];~i;i=g1.e[i].next){
            int v=g1.e[i].v;
            if(g1.e[i].flag||v==fa[u]) continue;
            dis[v]=dis[u]+1;
            my_que[++qt]=v;
            fa[v]=u;
        }
    }
}
void divide(int pos){
//    printf("%d!!\n",pos);
    bfs(pos);
    for(int i=g1.head[pos];i!=-1;i=g1.e[i].next){
        g1.e[i^1].flag=1;
        if(g1.e[i].flag) continue;
        int v=g1.e[i].v;
        int rt=find_root(v,son[v]);
//        printf("%d____-!!!\n",cen);
        divide(rt);
    }
}
int ans[M];
void mark(int u){
    ans[u]=0;
    for(int i=g2.head[u];~i;i=g2.e[i].next){
        int v=g2.e[i].v;
        int cost=g2.e[i].cost;
        if(ans[v]>ans[u]+cost) ans[v]=ans[u]+cost;
    }
}
int query(int u){
    int ret=ans[u];
    for(int i=g2.head[u];~i;i=g2.e[i].next){
        int v=g2.e[i].v;
        int cost=g2.e[i].cost;
        if(ret>ans[v]+cost) ret=ans[v]+cost;
    }
    return ret;
}
int main(){
//    freopen("in.txt","r",stdin);
    int n,m;while(~scanf("%d%d",&n,&m)){
        g1.init();
        memset(is_red,0,sizeof(is_red));
        for(int i=0;i<n-1;i++){
            int u,v;scanf("%d%d",&u,&v);
            g1.add(u,v);g1.add(v,u);
        }
        int rt=find_root(1,n);
        g2.init();
        divide(rt);
//        printf("%d\n",g2.en);
//        for(int i=1;i<=n;i++){
//            printf("this is %d\n",i);
//            for(int j=g2.head[i];~j;j=g2.e[j].next){
//                printf("%d  %d~~~",g2.e[j].v,g2.e[j].cost);
//            }
//            puts("");
//        }
        memset(ans,inf,sizeof(ans));
        mark(1);
        is_red[1]=1;
        for(int i=0;i<m;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            if(t1==1){
                mark(t2);
            }
            else{
                int tt=query(t2);
                printf("%d\n",tt);
            }
        }
    }
    return 0;
}
