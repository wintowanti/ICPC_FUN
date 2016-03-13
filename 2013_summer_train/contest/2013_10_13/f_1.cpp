#include<cstring>
#include<cstdio>
#include<queue>
#define M 302
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
struct G{
    ll en,head[M];
    struct E{
        int u,v,next,a,b,cost;
    }e[M*M];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int a,int b,int cost){
        e[en].u=u;e[en].v=v;e[en].a=a;e[en].b=b;e[en].cost=cost;e[en].next=head[u];head[u]=en++;
    }
}g1;
struct E{
    ll pos;
    ll time;
    friend bool operator <(const E a,const E b){
        if(a.time>=b.time){
            return 1;
        }
        return 0;
    }
};
priority_queue<E> q1;
ll vis[M];
ll bfs(ll sp,ll tp){
    E e1,e2;
    while(!q1.empty())q1.pop();
    memset(vis,inf,sizeof(vis));
    e1.pos=sp;e1.time=0;
    q1.push(e1);
    while(!q1.empty()){
        e1=q1.top();q1.pop();
        if(e1.pos==tp) return e1.time;
        ll pos=e1.pos;
        ll this_time=e1.time;
        ll flag=0;
        ll tmin=inf;
        tmin*=inf;
        for(ll i=g1.head[pos];~i;i=g1.e[i].next){
            ll pos2=g1.e[i].v;
            ll a=g1.e[i].a;
            ll b=g1.e[i].b;
            ll flag1=0;
            ll nexttime=this_time%(a+b);
            if(nexttime+g1.e[i].cost<=a&&nexttime+g1.e[i].cost>=1){
                nexttime=this_time+g1.e[i].cost;
            }
            else{
                ll t1=(this_time/(a+b)+1)*(a+b);
                nexttime=t1+g1.e[i].cost;
                if(nexttime<tmin) tmin=nexttime;
            }
            if(vis[pos2]>nexttime){
                vis[pos2]=nexttime;
                e2.pos=pos2;
                e2.time=nexttime;
                q1.push(e2);
            }
        }

    }
}
int main(){
    ll cas=1;
    ll n,m,sp,tp;
    while(~scanf("%lld%lld%lld%lld",&n,&m,&sp,&tp)){
        g1.init();
        for(ll i=0;i<m;i++){
            int u,v,a,b,cost;scanf("%d%d%d%d%d",&u,&v,&a,&b,&cost);
            if(a>=cost){
                g1.add(u,v,a,b,cost);
            }
        }
        ll ans=bfs(sp,tp);
        printf("Case %lld: %lld\n",cas++,ans);
    }
    return 0;
}
/*
4 4 1 3
1 2 50 6 14
2 3 7 7 7
1 4 2 2 2
4 3 2 2 1
*/
