#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 200000
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<3];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
struct E{
    int vis,id;
    friend bool operator <(const E a,const E b){
        if(a.vis<b.vis) return 1;
        return 0;
    }
}e[M];
int ans[M];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++){
            e[i].vis=0;e[i].id=i;
        }
        g1.init();
        for(int i=0;i<m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            x--;y--;z--;
            e[x].vis++;
            e[y].vis++;
            e[z].vis++;
            g1.add(x,y);
            g1.add(x,z);
            g1.add(y,x);
            g1.add(y,z);
            g1.add(z,x);
            g1.add(z,y);
        }
        sort(e,e+n);
        memset(ans,0,sizeof(ans));
        for(int i=n-1;i>=0;i--){
            bool vis[4];
            for(int j=1;j<4;j++) vis[j]=1;
            int t1=e[i].id;
            for(int j=g1.head[t1];~j;j=g1.e[j].next){
                int v=g1.e[j].v;
                vis[ans[v]]=0;
            }
            for(int j=1;j<=3;j++){
                if(vis[j]){
                    ans[t1]=j;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
           if(i) printf(" %d",ans[i]);
           else printf("%d",ans[i]);
        }
        puts("");
    }
    return 0;
}
