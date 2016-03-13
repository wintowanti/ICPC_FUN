#include<cstdio>
#include<cstring>
#define M 2000
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<6];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
bool vis[M];
int mat[M];
int crosspath(int u){
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(vis[v]){
            vis[v]=0;
            if(mat[v]==-1||crosspath(mat[v])){
                mat[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int hungary(int n){
    int tsum=0;
    memset(mat,-1,sizeof(mat));
    for(int i=0;i<n;i++){
        memset(vis,1,sizeof(vis));
        if(crosspath(i)){
            tsum++;
        }
    }
    return tsum;
}
int main(){
    return 0;
}
