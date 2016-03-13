#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#define inf 0x3f3f3f3f
#define M 100
using namespace std;
const int NV = 5580;
const int NE = 40500;
struct ISAP {
    int n, size;
    int head[NV];
    int dis[NV], gap[NV], pre[NV], cur[NV];
    int maxflow;
    struct Edge {
        int v, w, next;
        Edge () {}
        Edge (int V, int NEXT, int W = 0) : v(V), next(NEXT), w(W) { }
    }E[NE];
    void init(int x) {
        n = x, size = 0;
        for (int i = 0; i <= n; i++) {
            head[i] = -1;
        }
    }
    inline void insert(int u, int v, int w = 0) {
        E[size] = Edge(v, head[u], w);
        head[u] = size++;
        E[size] = Edge(u, head[v], 0);
        head[v] = size++;
    }
    int MaxFlow(int src, int des) {
        maxflow = 0;
        gap[0] = n;
        for (int i = 0; i <= n; i++) {
            dis[i] = gap[i] = 0;
        }
        for (int i = 0; i <= n; i++) {
            cur[i] = head[i];
        }
        int u = pre[src] = src;
        int aug = -1;
        while (dis[src] < n) {//结束条件1
loop:
            for (int &i = cur[u]; i != -1; i = E[i].next) {
                int v = E[i].v;
                if (E[i].w && dis[u] == dis[v] + 1) {
                    aug = min(aug, E[i].w);
                    pre[v] = u;
                    u = v;
                    if (v == des) {//找到一条增广路，更新
                        maxflow += aug;
                        // //修改残余网络
                        for (u = pre[u]; v != src; v = u, u = pre[u]) {
                            E[cur[u]].w -= aug;//正向边
                            E[cur[u]^1].w += aug;//反向边
                        }
                        aug = INT_MAX;
                    }//if
                    goto loop;
                }//for
            }//for
            //寻找最小的距离标号，并修改当前点    为最小的标号+1
            int mdis = n;
            for (int i = head[u]; i != -1; i = E[i].next) {
                int v = E[i].v;
                if (E[i].w && mdis > dis[v]) {
                    cur[u] = i;
                    mdis = dis[v];
                }
            }//for

            //GAP 优化 断层则跳出 结束条件2
            if ((--gap[dis[u]]) == 0) {
                break;
            }
            gap[dis[u] = mdis + 1]++;//将拥有该标号的数量加1
            u = pre[u];//当前节点 迁移一个
        }//while
        return maxflow;
    }//ISAP
}g1;
int a[M][M];
int n,m;
int o[4][2]={
0,1,
0,-1,
1,0,
-1,0,
};
int judge(int x,int y){
    if(x<0||x>n-1||y<0||y>m-1) return 0; return 1;
}
int main(){
//    for(int i=0;i<4;i++){
//        printf("%d  %d\n",o[i][0],o[i][1]);
//    }
    while(~scanf("%d%d",&n,&m)){
        int tsum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) scanf("%d",&a[i][j]),tsum+=a[i][j];
        }
  //      printf("%d\n",tsum);
        g1.init(n*m+100);
        int sp=0;int tp=n*m+1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i+j)%2){
                    g1.insert(sp,i*m+j+1,a[i][j]);
                    for(int k=0;k<4;k++){
                        int x1=i+o[k][0];
                        int y1=j+o[k][1];
                        if(judge(x1,y1)){
                            g1.insert(i*m+j+1,x1*m+y1+1,inf);
                        }
                    }
                }
                else{
                    g1.insert(i*m+j+1,tp,a[i][j]);
                }
            }
        }
        int ans=g1.MaxFlow(sp,tp);
        printf("%d\n",tsum-ans);
    }
    return 0;
}
