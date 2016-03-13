#include<cstdio>
#include<cstring>
#define inf 0x3f3f3f3f
#define M 200020
struct G{
    int head[M],en;
    struct E{
        int u,v,cost,next,flag;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v,int cost){
        e[en].flag=0;
        e[en].u=u;e[en].v=v;e[en].cost=cost;e[en].next=head[u];head[u]=en++;
    }
}g1;
int mark[M<<4];
int dis[M],fa[M],son[M],mc[M],lv[M],m;
int my_que[M<<4];
int my_sta[M<<4];
int find_root(int pos,int siz){
    int qh=0,qt=-1,cen=0;
    int top=-1;
    fa[pos]=0;
    my_que[++qt]=pos;
    while(qt>=qh){
        int u=my_que[qh++];
        son[u]=1,mc[u]=0;
        for(int i=g1.head[u];~i;i=g1.e[i].next){
            int v=g1.e[i].v;
            if(v==fa[u]||g1.e[i].flag) continue;
            fa[v]=u;
            my_que[++qt]=v;
        }
        my_sta[++top]=u;
    }
    mc[cen]=siz;
    while(top>=0){
        int u=my_sta[top--];
        son[fa[u]]+=son[u];
        if(mc[fa[u]]<son[u]) mc[fa[u]]=son[u];
        if(mc[u]<siz-son[u]) mc[u]=siz-son[u];
        if(mc[u]<mc[cen]) cen=u;
    }
    printf("rt is %d~~~\n",cen);
    return cen;
}
int stk[M<<4][2];
int ans;
int top;
void dfs(int u,int p,int cost){
    printf("%d!!!!\n",u);
    dis[u]=dis[p]+cost;
    lv[u]=lv[p]+1;
    if(dis[u]<=m){
        stk[top][0]=dis[u];
        stk[top++][1]=lv[u];
        if(lv[u]+mark[m-dis[u]]<ans){
            printf("%d   %d\n~~~~~~~~~~~~~~~",lv[u],mark[m-dis[u]]);
            ans=lv[u]+mark[m-dis[u]];
        }
    }
    else return ;
    for(int i=g1.head[u];~i;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(v==p||g1.e[i].flag) continue;
        dfs(v,u,g1.e[i].cost);
    }
}
int change[M<<6],en;
void divide(int u){
    printf("%d!!!",u);
    dis[u]=0;
    lv[u]=0;
    mark[0]=0;
    en=0;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        top=0;
        int v=g1.e[i].v;
        if(g1.e[i].flag) continue;
        puts("fuck");
        dfs(v,u,g1.e[i].cost);
        for(int j=0;j<top;j++){
            int dis1=stk[j][0];
            int cost1=stk[j][1];
            if(mark[dis1]>cost1){
//                printf("dis  is %d   cost is  %d\n",dis1,cost1);
                mark[dis1]=cost1;
                change[en++]=dis1;
            }
        }
    }
    puts("mark1");
    for(int i=0;i<en;i++){
        mark[change[i]]=inf;
    }
    for(int i=g1.head[u];~i;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(g1.e[i].flag) continue;
        g1.e[i^1].flag=1;
        int rt=find_root(v,son[v]);
        divide(rt);
    }
}
int main(){
    int n;
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=0;i<n-1;i++){
            int u,v,cost;scanf("%d%d%d",&u,&v,&cost);
            g1.add(u,v,cost);g1.add(v,u,cost);
        }
        memset(mark,inf,sizeof(mark));
        mark[0]=0;
        ans=inf;
        int rt=find_root(1,n);
        divide(rt);
        if(ans==inf){
            puts("-1");
        }
        else printf("%d\n",ans);
    }
    return 0;
}
/*
5 3

0 1 1

1 2 10

1 3 4

2 4 2
*/
