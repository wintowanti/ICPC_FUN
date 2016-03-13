#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 20000
using namespace std;
int abs(int x){
    if(x>=0) return x;return -x;
}
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
int point[M][2];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        char tmp[100];
        for(int i=0;i<m;i++){
            scanf("%s",tmp);
            point[i][0]=tmp[0]-'A';
            if(tmp[2]=='\0')
            point[i][1]=tmp[1]-'0';
            else{
                point[i][1]=(tmp[1]-'0')*10+tmp[2]-'0';
            }
        }
        g1.init();
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                int flag1=0,flag2=0;
                int t1=abs(point[i][0]-point[j][0]);
                int t2=abs(point[i][1]-point[j][1]);
                if(t1==1||t2==1) flag1++;
                if(t1==2||t2==2) flag2++;
                if(flag1&&flag2){
                    g1.add(i,j);
                }
            }
        }
        int ans=hungary(m);
        printf("%d\n",ans/2);
    }
    return 0;
}
/*
6 2
A1
A1
*/
