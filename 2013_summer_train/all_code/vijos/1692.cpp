#include<cstdio>
#include<cstring>
#include<stack>
#define M 1010
using namespace std;
struct G{
public:
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M*M];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1,g2;
int subid[M],subnum,pre[M],low[M],dfs_clock,num[M];
stack<int > stk1;
void initt(){
    memset(subid,0,sizeof(subid));
    memset(pre,0,sizeof(pre));
    memset(low,0,sizeof(low));
    dfs_clock=subnum=0;
}
void dfs(int u){
    stk1.push(u);
    pre[u]=low[u]=++dfs_clock;
//    printf("%d@@@@@@%d\n",u,g1.head[u]);
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
//        printf("%d   \n",v);
        if(!pre[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }else if(!subid[v]){
            low[u]=min(low[u],pre[v]);
        }
    }
    if(pre[u]==low[u]){
        ++subnum;
        num[subnum]=0;
        while(1){
            int t1=stk1.top();stk1.pop();
//            printf("!!!!%d\n",t1);
            subid[t1]=subnum;
            num[subnum]++;
            if(t1==u) break;
        }
    }
}
void tarjan(int n){
    initt();
    for(int i=1;i<=n;i++){
        if(!pre[i]) dfs(i);
    }
}
int dp[M];
int used[M];
int dfs1(int u){
    if(dp[u]!=-1){
        return dp[u];
    }
    int tmax=0;
    for(int i=g2.head[u];i!=-1;i=g2.e[i].next){
        int v=g2.e[i].v;
        if(used[v]){
            int t1=dfs1(v);
            tmax+=t1;
        }
    }
    tmax+=num[u];
    return dp[u]=tmax;
}
void dfs2(int u){
    used[u]=0;
    for(int i=g2.head[u];i!=-1;i=g2.e[i].next){
        int v=g2.e[i].v;
        if(used[v]){
            dfs2(v);
        }
    }
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=0;i<n;i++){
            int t1;scanf("%d",&t1);
            for(int j=0;j<t1;j++){
                int t2;scanf("%d",&t2);
                g1.add(t2,i+1);
            }
        }
//        puts("~~~~~~~~~~~~");
        tarjan(n);
        g2.init();
        for(int i=0;i<g1.en;i++){
            int t1=subid[g1.e[i].u];int t2=subid[g1.e[i].v];
            if(t1!=t2){
                g2.add(t1,t2);
            }
        }
        memset(used,1,sizeof(used));
        int tsum=0;
//        for(int i=1;i<=n;i++){
//            printf("%d  ~~ %d\n",i,subid[i]);
//        }
//        for(int i=1;i<=subnum;i++){
//            printf("%d  ~~\n",num[i]);
//        }
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++){
            int tmax=0,flag=0;
            for(int j=1;j<=subnum;j++){
                if(used[j]){
                    int t1=dfs1(j);
                    if(t1>tmax) tmax=t1,flag=j;
                }
            }
            tsum+=tmax;
        //    printf("%d  %d!!\n",tmax,flag);
            dfs2(flag);
            if(tsum==n) break;
        }
        printf("%d\n",tsum);
    }
    return 0;
}
/*
4 3
0
0
0
0
*/
