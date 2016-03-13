#pragma comment(linker, "/STACK:16777216")
#include<cstdio>
#include<cstring>
#define M 100200
#define ll __int64
struct G{
    ll head[M],en;
    struct E{
        ll u,v,next;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(ll u,ll v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
ll dp[M][2];
ll child[M];
ll ans;
void dfs1(ll u,ll fa){
    dp[u][0]=0;
    dp[u][1]=0;
    child[u]=0;
    for(ll i=g1.head[u];i!=-1;i=g1.e[i].next){
        ll v=g1.e[i].v;
        if(v!=fa){
            dfs1(v,u);
            ll t1=dp[v][0];
            t1++;
            dp[u][0]+=t1;
            dp[u][1]+=t1*t1;
            child[u]++;
        }
    }
}
void dfs2(ll u,ll fa,ll fv){
    ll tsum=0;
    if(u!=1) child[u]++;
    if(child[u]>=2){
        ll t1=dp[u][0]+fv;
        ll t2=dp[u][1]+fv*fv;
        ans+=(t1*t1-t2)/2;
    }
    for(ll i=g1.head[u];i!=-1;i=g1.e[i].next){
        ll v=g1.e[i].v;
        if(v!=fa){
            ll t1=fv+dp[u][0]-dp[v][0];
            dfs2(v,u,t1);
        }
    }
}
int main(){
    ll n;while(~scanf("%I64d",&n)){
        g1.init();
        for(ll i=0;i<n-1;i++){
            ll t1,t2;scanf("%I64d%I64d",&t1,&t2);
            g1.add(t1,t2);
            g1.add(t2,t1);
        }
        dfs1(1,-1);
//        for(ll i=1;i<=n;i++){
//            printf("this is %I64d    %I64d   %I64d \n",i,dp[i][0],dp[i][1]);
//        }
        ans=0;
        dfs2(1,-1,0);
        ll ans2=n*(n-1)*(n-2);
        ans2=ans2/6;
        printf("%I64d\n",ans2-ans);
    }
    return 0;
}
/*
4
1 2
2 3
3 4
*/
