/*
2-sat tarjan topsort
输出任意解
O(E)hit 1917
*/
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#define M 20000
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<4];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];
        head[u]=en++;
    }
}g1,g2;
int subid[M],subnum,dfs_clock,pre[M],low[M],last[M];
stack<int > stk1;
void initt(){
    memset(subid,0,sizeof(subid));
    memset(pre,0,sizeof(pre));
    memset(low,0,sizeof(low));
    subnum=dfs_clock=0;
}
void dfs(int u){
    stk1.push(u);
    pre[u]=low[u]=++dfs_clock;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(!pre[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!subid[v]){
            low[u]=min(low[u],pre[v]);
        }
    }
    if(pre[u]==low[u]){
        ++subnum;
        while(1){
            int t1=stk1.top();stk1.pop();
            subid[t1]=subnum;
            if(t1==u){
                last[subnum]=t1;
                break;
            }
        }
    }
}
int tarjan(int n){
    initt();
    for(int i=0;i<2*n;i++){
        if(!pre[i]) dfs(i);
    }
    for(int i=0;i<2*n;i+=2){
        if(subid[i]==subid[i^1]) return 0;
    }
    return 1;
}
int indgree[M],color[M];
queue<int> q1;
void init_top(){
    memset(indgree,0,sizeof(indgree));
    memset(color,-1,sizeof(color));
    g2.init();
    while(!q1.empty()) q1.pop();
    for(int i=0;i<g1.en;i++){
        int t1=g1.e[i].u;
        int t2=g1.e[i].v;
        t1=subid[t1];t2=subid[t2];
        if(t1!=t2){
            g2.add(t2,t1);
            indgree[t1]++;
        }
    }
}
void dfs2(int u){
    color[u]=0;
    for(int i=g2.head[u];i!=-1;i=g2.e[i].next){
        int v=g2.e[i].v;
        if(color[v]==-1){
            dfs2(v);
        }
    }
}
void top_sort(int n){
    init_top();
    for(int i=1;i<=n;i++){
        if(indgree[i]==0){
            q1.push(i);
        }
    }
    while(!q1.empty()){
            int u=q1.front();q1.pop();
            for(int i=g2.head[u];i!=-1;i=g2.e[i].next){
                int v=g2.e[i].v;
                indgree[v]--;
                if(indgree[v]==0) q1.push(v);
            }
            if(color[u]==-1){
                color[u]=1;
                int v=last[u];
                v=subid[v^1];
                dfs2(v);
            }
    }
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=0;i<m;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            t1--;t2--;
            g1.add(t1,t2^1);
            g1.add(t2,t1^1);
        }
        int ans=tarjan(n);
        if(!ans){
            puts("NIE");
        }
        else{
            top_sort(subnum);
            for(int i=0;i<2*n;i+=2){
                if(color[subid[i]]==1){
                    printf("%d\n",i+1);
                }
                else{
                    printf("%d\n",i+2);
                }
            }
        }
    }
    return 0;
}
/*
3 6
1 4
1 3
2 4
2 4
2 6
2 6
*/
