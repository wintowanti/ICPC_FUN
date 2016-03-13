#include<cstdio>
#include<cstring>
#include<stack>
#define inf 0x3f3f3f3f
#define M 208000
#define ll __int64
using namespace std;
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
}g1,g2;
int min(int x,int y){
    if(x>y) return y;return x;
}
int pre[M],low[M],subid[M],subnum,num[M],dis[M],dfs_clock;
int in[M],out[M];
stack<int > stk;
void init_t(){
    memset(low,0,sizeof(low));
    memset(pre,0,sizeof(pre));
    memset(subid,0,sizeof(subid));
    subnum=dfs_clock=0;
}
void dfs1(int u){
    pre[u]=low[u]=++dfs_clock;
    stk.push(u);
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(!pre[v]){
                dfs1(v);
                low[u]=min(low[u],low[v]);
        }
        else if(!subid[v]){
            low[u]=min(low[u],pre[v]);
        }
    }
    if(pre[u]==low[u]){
        ++subnum;
        int tsum=0;
        while(1){
            int t1=stk.top();stk.pop();
            subid[t1]=subnum;
            tsum++;
            if(t1==u) break;
        }
        num[subnum]=tsum;
    }
}
int dfs2(int u){
    int tsum=num[u];
    for(int i=g2.head[u];i!=-1;i=g2.e[i].next){
        int v=g2.e[i].v;
        if(dis[v]==-1){
            tsum+=dfs2(v);
        }
    }
    return dis[u]=tsum;
}
int main(){
    int cas,q;
    while(~scanf("%d",&cas)){ q=1;
        while(cas--){
            ll n;
            int m;
            scanf("%I64d%d",&n,&m);
            g1.init();
            for(int i=1;i<=m;i++){
                int t1,t2;scanf("%d%d",&t1,&t2);g1.add(t1,t2);
            }
            init_t();
            for(int i=1;i<=n;i++){
                if(!pre[i]) dfs1(i);
            }
            if(subnum==1){
                printf("Case %d: -1\n",q++);
                continue;
            }
//            printf("~~~~~~~~~~~~\n");
//            for(int i=1;i<=n;i++){
//                printf("%d   %d\n",i,subid[i]);
//            }
            memset(in,0,sizeof(in));
            memset(out,0,sizeof(out));
            for(int i=0;i<g1.en;i++){
                int t1=g1.e[i].u;int t2=g1.e[i].v;
                t1=subid[t1];t2=subid[t2];
                if(t1!=t2){
                    out[t1]++;in[t2]++;
                }
            }
//            puts("*********************");
            ll tmin=1000000000000ll;
            for(int i=1;i<=subnum;i++){
                if(num[i]<tmin&&(in[i]==0||out[i]==0)){
                    tmin=num[i];
                }
            }
//            printf("%I64d!!!\n",tmin);
            ll ans=n*(n-1);
            ans=ans-m-(n-tmin)*tmin;
            printf("Case %d: %I64d\n",q++,ans);
        }
    }
    return 0;
}
