#include<cstdio>
#include<cstring>
#include<cmath>
#define M 1001
#define N 30080
using namespace std;
struct G{
    int head[M*2],en;
    struct E{
        int u,v,next;
    }e[M*M*4];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
bool vis[M<<2];
int mat[M<<2];
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
        if(g1.head[i]==-1) continue;
        memset(vis,1,sizeof(vis));
        if(crosspath(i)){
      //      printf("%d\n",i);
            tsum++;
        }
    }
    return tsum;
}
double human[M<<4][3];
double point[M<<4][2];
double dis(double x1,double y1,double x2,double y2){
    double tsum=0;
    tsum+=(x1-x2)*(x1-x2);
    tsum+=(y1-y2)*(y1-y2);
    tsum=sqrt(tsum);
    return tsum;
}
int main(){
    int n1,n2;
    double t;
    while(~scanf("%d%d%lf",&n2,&n1,&t)){
        for(int i=0;i<n1;i++) scanf("%lf%lf",&point[i][0],&point[i][1]);
        for(int i=0;i<n2;i++) scanf("%lf%lf%lf",&human[i][0],&human[i][1],&human[i][2]);
        g1.init();
        for(int i=0;i<n2;i++){
            for(int j=0;j<n1;j++){
                if(dis(human[i][0],human[i][1],point[j][0],point[j][1])<=human[i][2]*t){
                    g1.add(i,j);
                }
            }
        }
        int ans=hungary(n2);
        printf("%d\n",ans);
    }
    return 0;
}
