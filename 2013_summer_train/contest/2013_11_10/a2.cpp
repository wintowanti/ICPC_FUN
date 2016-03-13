#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#define inf 0x3f3f3f3f
using namespace std;
const int NV = 158000;
const int NE = 4050002;
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
        while (dis[src] < n) {//œáêøìõŒt1
loop:
            for (int &i = cur[u]; i != -1; i = E[i].next) {
                int v = E[i].v;
                if (E[i].w && dis[u] == dis[v] + 1) {
                    aug = min(aug, E[i].w);
                    pre[v] = u;
                    u = v;
                    if (v == des) {//Õòμœò»ìõÔö1ãÂ·￡¬žüDÂ
                        maxflow += aug;
                        // //DTžÄ2DóàíøÂç
                        for (u = pre[u]; v != src; v = u, u = pre[u]) {
                            E[cur[u]].w -= aug;//ÕyÏò±ß
                            E[cur[u]^1].w += aug;//·ŽÏò±ß
                        }
                        aug = INT_MAX;
                    }//if
                    goto loop;
                }//for
            }//for
            //Ñ°Õò×îD¡μÄŸààë±êoÅ￡¬2￠DTžÄμ±Ç°μã    Îa×îD¡μÄ±êoÅ+1
            int mdis = n;
            for (int i = head[u]; i != -1; i = E[i].next) {
                int v = E[i].v;
                if (E[i].w && mdis > dis[v]) {
                    cur[u] = i;
                    mdis = dis[v];
                }
            }//for

            //GAP óÅ»ˉ ¶Ï2ãÔòìø3ö œáêøìõŒt2
            if ((--gap[dis[u]]) == 0) {
                break;
            }
            gap[dis[u] = mdis + 1]++;//œ«óμóDžÃ±êoÅμÄêyá¿Œó1
            u = pre[u];//μ±Ç°œúμã ÇšòÆò»žö
        }//while
        return maxflow;
    }//ISAP
}g1;
#define M1 200
char map1[M1][M1];
int  num[M1][M1];
int o[4][2]={
    1,0,
    -1,0,
    0,-1,
    0,1,
};
int n,m;
int judge(int x,int y){
    if(x<0||x>n-1||y<0||y>m-1) return 0;
    return 1;
}
int build(int sp,int tp){
    g1.insert(sp,1,inf);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int pos=num[i][j];
            if(map1[i][j]=='D'){
                for(int k=0;k<4;k++){
                    int x1=i+o[k][0];
                    int y1=j+o[k][1];
                    if(judge(x1,y1)){
                        int pos2=num[x1][y1];
                        if(pos2!=pos&&pos2!=-1){
                            g1.insert(pos,pos2,1);
                        }
                    }
                    else{
                        g1.insert(pos,tp,1);
                    }
                }
            }
            else if(map1[i][j]=='.'){
                int pos=num[i][j];
                for(int k=0;k<4;k++){
                    int x1=i+o[k][0];
                    int y1=j+o[k][1];
                    if(judge(x1,y1)){
                        int pos2=num[x1][y1];
                        g1.insert(pos,pos2,1);
                    }
                    else{
                        g1.insert(pos,tp,1);
                    }
                }
            }
        }
    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            printf("%d  ",num[i][j]);
//        }
//        puts("~~");
//    }
//    printf("%d   %d\n",sp,tp);
    int ans=g1.MaxFlow(sp,tp);
    return ans;
}
int main() {
    freopen("in.txt","r",stdin);
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            scanf("%d%d",&n,&m);
            for(int i=0;i<n;i++) scanf("%s",map1[i]);
            int flag=0;
            int en=2;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(map1[i][j]=='D'){
                        num[i][j]=1;
                    }
                    else if(map1[i][j]=='.'){
                        num[i][j]=en++;
                    }
                    else num[i][j]=-1;
                }
            }
            g1.init(en+2);
            int sp=0;
            int tp=en;
            int ans=build(sp,tp);
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
2
7 8
XXX..XXX
XXX..XXX
.....XXX
XXX..XXX
XDDDD.XX
XDDDD...
XXXXXXXX
5 5
XX.XX
.DDD.
XD.DX
X....
X....
*/
