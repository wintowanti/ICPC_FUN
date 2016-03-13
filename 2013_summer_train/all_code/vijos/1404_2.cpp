#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define inf 0x3f3f3f3f
#define ll int
#define M 200000
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;
int max(int x,int y){
    if(x>y) return x;return y;
}
int min(int x,int y){
    if(x>y) return y;return x;
}
struct G{
    int head[M],en;
    struct E{
        int u,v,cost,next;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int cost){
        e[en].u=u;e[en].v=v;e[en].cost=cost;e[en].next=head[u];head[u]=en++;
    }
}g1;
ll dis[M];
int in[M];
bool vis[M];
queue<int > q1;
int relax(int v,int u,int cost){
    if(dis[v]>dis[u]+cost){
        dis[v]=dis[u]+cost;return 1;
    }
    return 0;
}
ll spfa(int sp,int tp){
    while(!q1.empty()) q1.pop();
    memset(dis,inf,sizeof(dis));
    memset(vis,1,sizeof(vis));
    memset(in,0,sizeof(in));
    ll mark=dis[0];
    dis[sp]=0;vis[sp]=0;
    q1.push(sp);
    while(!q1.empty()){
        int u=q1.front();q1.pop();
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            int cost=g1.e[i].cost;
            if(relax(v,u,cost)){
                if(vis[v]){
                    vis[v]=0;
                    q1.push(v);
                }
            }
        }
        vis[u]=1;
    }
//    for(int i=0;i<)
//    printf("%I64d!!\n",dis[tp]);
    if(dis[tp]==mark){
        return -1;
    }else{
        return dis[tp];
    }
}
struct P{
    int x,y,z;
    friend bool operator <(const P a,P b){
        if(a.y<b.y) return 1;return 0;
    }
}p[M];
struct T{
    ll tmin[M<<2];ll tflag[M<<2];
    void build(){
        memset(tmin,inf,sizeof(tmin));
        memset(tflag,inf,sizeof(tflag));
    }
    void push_up(int rt){
        tmin[rt]=min(tmin[lson],tmin[rson]);
    }
    void push_down(int rt){
        if(1){
            if(tflag[lson]>tflag[rt]){
                tmin[lson]=tflag[lson]=tflag[rt];
            }
            if(tflag[rson]>tflag[rt]){
                tmin[rson]=tflag[rson]=tflag[rt];
            }
        }
    }
    void update(int ul,int ur,ll new_flag,int l,int r,int rt){
//        printf("%d   %d   %I64d   %d   %d   %d\n",ul,ur,new_flag,l,r,rt);
        if(ul<=l&&ur>=r){
            if(tmin[rt]>new_flag) tmin[rt]=new_flag;
            if(tflag[rt]>new_flag) tflag[rt]=new_flag;
            return ;
        }
        push_down(rt);
        int mid=(l+r)>>1;
        if(ur<=mid) update(ul,ur,new_flag,l,mid,lson);
        else if(ul>mid) update(ul,ur,new_flag,mid+1,r,rson);
        else{
            update(ul,ur,new_flag,l,mid,lson);
            update(ul,ur,new_flag,mid+1,r,rson);
        }
        push_up(rt);
    }
    ll query(int ul,int l,int r,int rt){
        if(ul==l&&ul==r){
            return tmin[rt];
        }
        push_down(rt);
        int mid=(l+r)>>1;
        if(ul<=mid) return query(ul,l,mid,lson);
        else return query(ul,mid+1,r,rson);
    }
}tr;
int main(){
    int s,e,n;while(~scanf("%d%d%d",&n,&s,&e)){
        s+=2;e+=2;
        g1.init();
        for(int i=0;i<n;i++){
            int t1,t2,t3;scanf("%d%d%d",&t1,&t2,&t3);t1++,t2+=2;
            t1=max(t1,s-1);
            t2=min(t2,e);
            p[i].x=t1;p[i].y=t2,p[i].z=t3;
        }
        sort(p,p+n);
        tr.build();
//        printf("%d!!\n",s-1);
        tr.update(s-1,s-1,0ll,1,e,1);
        ll tt1=tr.query(s-1,1,e,1);
//        printf("%I64d***\n",tt1);
        for(int i=0;i<n;i++){
//            printf("%d  %d   %d\n",p[i].x,p[i].y,p[i].z);
            ll t1=tr.query(p[i].x,1,e,1)+p[i].z;
            tr.update(p[i].x+1,p[i].y,t1,1,e,1);
//            printf("%I64d  !!!! \n",t1);
        }
        ll ans=tr.query(e,1,e,1);
        if(ans>=inf){
            puts("-1");
        }
        else{
            printf("%d\n",ans);
        }
    }
    return 0;
}
