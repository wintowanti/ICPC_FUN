#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#define M 6000
#define inf 0x3f3f3f3f
using namespace std;
int vis[2][M];
struct G{
    int head[M],en;
    struct E{
        int u,v,next,t,c;
    }e[M<<7];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int c,int t){
        e[en].u=u;e[en].v=v;e[en].c=c;e[en].t=t;e[en].next=head[u];head[u]=en++;
    }
}g1;
struct E{
    int pos,t,c;
    friend bool operator <(const  E a,const E b){
        if(a.t<b.t) return 0;
        return 1;
    }
};
int dead;
priority_queue<E> q1;
int bfs(int sp,int tp){
    while(!q1.empty()) q1.pop();
    memset(vis[0],inf,sizeof(vis[0]));
    memset(vis[1],0,  sizeof(vis[1]));
    vis[0][sp]=0;
    vis[1][sp]=0;
    E e1,e2;
    e1.pos=sp;e1.t=0;e1.c=0;q1.push(e1);
    while(!q1.empty()){
        e1=q1.top();q1.pop();
//        printf("%d   %d     %d\n",e1.pos,e1.t,e1.c);
        if(e1.pos==tp) return e1.t;
        for(int i=g1.head[e1.pos];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            int t=e1.t+g1.e[i].t;
            int c=e1.c+g1.e[i].c;
            e2.pos=v;e2.t=t;e2.c=c;
            if(e2.c<=dead){
                int flag=1;
                if(vis[0][v]>c){
                    vis[0][v]=c;
                    vis[1][v]=t;
                    flag=1;
                }
                else{
                    if(t<vis[1][v]) flag=1;
                }
                if(flag) q1.push(e2);
            }
        }
    }
    return -1;
}
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=0;i<m;i++){
            int u,v,c,t;scanf("%d%d%d%d",&u,&v,&c,&t);
            g1.add(u,v,c,t);
            g1.add(v,u,c,t);
        }
        int sp,tp;scanf("%d%d%d",&sp,&tp,&dead);
        int ans=bfs(sp,tp);
        printf("%d\n",ans);
    }
    return 0;
}
