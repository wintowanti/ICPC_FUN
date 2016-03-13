#include<cstdio>
#include<queue>
#include<cstring>
#define inf 0x3f3f3f3f
#define M 300000
using namespace std;
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
int in[M];
int ans[M];
priority_queue<int> q1;
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        g1.init();
        for(int i=0;i<m;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            g1.add(t2,t1,1);
            in[t1]++;
        }
        for(int i=1;i<=n;i++){
            if(in[i]==0){
                q1.push(i);
            }
        }
        int flag=n;
        while(!q1.empty()){
            int t1=q1.top();q1.pop();
            ans[t1]=flag--;
            for(int i=g1.head[t1];i!=-1;i=g1.e[i].next){
                int v=g1.e[i].v;
                in[v]--;
                if(in[v]==0){
                    q1.push(v);
                }
            }
        }
        for(int i=1;i<=n;i++){
           if(i==1) printf("%d",ans[i]);
           else printf(" %d",ans[i]);
        }
        puts("");
    }
    return 0;
}
