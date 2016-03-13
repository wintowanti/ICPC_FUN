#include<cstdio>
#include<cstring>
#include<queue>
#define M 300
using namespace std;
class G{
    public :
        int head[M],en;
        struct E{
            int u,v,next;
        }e[M*M];
        void init(){
            memset(head,-1,sizeof(head));en=0;
        }
        void add(int u,int v){
            e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
        }
}g1;
bool hash1[M][M];
int ans[M];
int ans_num;
int indegree[M];
struct S{
    int  x;
    friend bool operator <(const S a,const S b){
        if(a.x<=b.x) return 1;return 0;
    }
};
priority_queue<S> q1;
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            int n,m;scanf("%d%d",&n,&m);
            memset(indegree,0,sizeof(indegree));memset(hash1,0,sizeof(hash1));
            g1.init();
            for(int i=0;i<m;i++){
                int t1,t2;scanf("%d%d",&t1,&t2);
           //     if(hash1[t2][t1]==0){
                    hash1[t2][t1]=1;
                    g1.add(t2,t1);
                    indegree[t1]++;
          //      }
            }
            int num=0;
            while(!q1.empty()) q1.pop();
            for(int i=1;i<=n;i++){
                if(indegree[i]==0){
                    S s1;s1.x=i;
                    q1.push(s1);
                }
            }
            while(1){
                int flag=0;
                if(q1.empty()) break;
                S s1;s1=q1.top();q1.pop();
                ans[num++]=s1.x;
                for(int i=g1.head[s1.x];i!=-1;i=g1.e[i].next){
                    int v=g1.e[i].v;
                    indegree[v]--;
                    if(indegree[v]==0){
                        S s2;s2.x=v;q1.push(s2);
                    }
                }
            }
            int ans1[M];
            if(num!=n){
                puts("-1");
                continue;
            }else{
                for(int i=0;i<=n-1;i++){
                    ans1[ans[i]]=n-i;
                }
            }
            for(int i=1;i<=n;i++){
                if(i!=1)
                printf(" %d",ans1[i]);
                else printf("%d",ans1[i]);
            }
            puts("");
        }
    }
    return 0;
}
