#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#define M 200
#define inf 0x3f3f3f3f
using namespace std;
const int NV = 1580;
const int NE = 450002;
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
char str[M][M];
bool build(int n,int mid,int k){
    int sp=0,tp=4*n+1;
    g1.init(tp+2);
    int tsum=mid*n;
    for(int i=1;i<=n;i++){
        g1.insert(sp,i,mid);
        g1.insert(i,i+n,k);
        g1.insert(i+3*n,tp,mid);
        g1.insert(i+2*n,i+3*n,k);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(str[i][j]=='Y'){
                g1.insert(i+1,j+1+3*n,1);
            }
            else{
                g1.insert(i+1+n,j+1+2*n,1);
            }
        }
    }
    int t1=g1.MaxFlow(sp,tp);
//    printf("!!!!!%d\n",t1);
    if(t1==tsum) return 1;
    return 0;
}
int binary(int l,int r,int n,int k){
    int tmax=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(build(n,mid,k)){
            tmax=mid;l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return tmax;
}
int main(){
    int n,k;while(~scanf("%d%d",&n,&k)){
        for(int i=0;i<n;i++) scanf("%s",str[i]);
        int ans=binary(0,n,n,k);
        printf("%d\n",ans);
    }
    return 0;
}
