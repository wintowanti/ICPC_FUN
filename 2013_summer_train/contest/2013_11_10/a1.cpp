#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<queue>
#define inf 0x3f3f3f3f
using namespace std;
const int NV = 58000;
const int NE = 150002;
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
        for (int i = 0; i <= NV-10; i++) {
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
        while (dis[src] < n) {//œáÊøÌõŒþ1
loop:
            puts("**********");
            puts("mark");
            for (int &i = cur[u]; i != -1; i = E[i].next) {
                int v = E[i].v;
                if (E[i].w && dis[u] == dis[v] + 1) {
                    aug = min(aug, E[i].w);
                    pre[v] = u;
                    u = v;
                    if (v == des) {//ÕÒµœÒ»ÌõÔö¹ãÂ·£¬žüÐÂ
                        maxflow += aug;
                        // //ÐÞžÄ²ÐÓàÍøÂç
                        for (u = pre[u]; v != src; v = u, u = pre[u]) {
                            E[cur[u]].w -= aug;//ÕýÏò±ß
                            E[cur[u]^1].w += aug;//·ŽÏò±ß
                        }
                        aug = INT_MAX;
                    }//if
                    goto loop;
                }//for
            }//for
            //Ñ°ÕÒ×îÐ¡µÄŸàÀë±êºÅ£¬²¢ÐÞžÄµ±Ç°µã    Îª×îÐ¡µÄ±êºÅ+1
            int mdis = n;
            for (int i = head[u]; i != -1; i = E[i].next) {
                int v = E[i].v;
                if (E[i].w && mdis > dis[v]) {
                    cur[u] = i;
                    mdis = dis[v];
                }
            }//for

            //GAP ÓÅ»¯ ¶Ï²ãÔòÌø³ö œáÊøÌõŒþ2
            if ((--gap[dis[u]]) == 0) {
                break;
            }
            gap[dis[u] = mdis + 1]++;//œ«ÓµÓÐžÃ±êºÅµÄÊýÁ¿ŒÓ1
            u = pre[u];//µ±Ç°œÚµã ÇšÒÆÒ»žö
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
bool vis[M1][M1];
struct E{
    int x,y;
};
queue<E> q1;
int bfs(){
    int ans=0;
    memset(vis,0,sizeof(vis));
    int sx,sy;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map1[i][j]=='D'){
                sx=i;
                sy=j;
                break;
            }
        }
    }
    while(!q1.empty()) q1.pop();
    E e1,e2;
    vis[sx][sy]=1;
    e1.x=sx;e1.y=sy;
    q1.push(e1);
    while(!q1.empty()){
        e1=q1.front();q1.pop();
        for(int i=0;i<4;i++){
            int x1=e1.x+o[i][0];
            int y1=e1.y+o[i][1];
            if(judge(x1,y1)==0){
                ans=1;
                continue;
            };
            if(map1[x1][y1]=='#') continue;
            if(vis[x1][y1]) continue;
            vis[x1][y1]=1;
            e2.x=x1;e2.y=y1;
            q1.push(e2);
        }
    }
    return ans;
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
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%3d",num[i][j]);
        }
        puts("~~");
    }
    printf("%d   %d\n",sp,tp);
    puts("******");
    int ans=g1.MaxFlow(sp,tp);
    return ans;
}
int main() {
//    freopen("in.txt","r",stdin);
    int cas;
    while(~scanf("%d",&cas)){
        while(cas--){
            scanf("%d%d",&n,&m);
            memset(num,-1,sizeof(num));
            for(int i=0;i<n;i++) scanf("%s",map1[i]);
            int flag=0;
            int en=2;
//            int flag_ans=bfs();
//            if(flag_ans==0){
//                puts("0");
//                continue;
//            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(vis[i][j]==0){
                        ;
                    }
                    if(map1[i][j]=='D'){
                        num[i][j]=1;
                    }
                    else if(map1[i][j]=='.'){
                        num[i][j]=en++;
                    }
                    else num[i][j]=-1;
                }
            }
//            for(int i=0;i<n;i++){
//                puts(map1[i]);
//            }
//            puts("mark");
            g1.init(en+30);
            int sp=0;
            int tp=en;
            int ans=build(sp,tp);
          //  int ans=1;
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
11 16
XXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXX
XXXXXXXX...XXXXX
XXXXXXXX.D......
XXXXXXXX......XX
XXXXXXXX.X.XX.XX
XXXXXXXX.X.XX.XX
XXXXXXXX........
XXXXXXXXXX.XX.XX
11 16
XXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXX
XXXXXXXX...XXXXX
XXXXXXXX.D......
XXXXXXXX......XX
XXXXXXXX.X.XX.XX
XXXXXXXX.X.XXXXX
XXXXXXXX........
XXXXXXXXXX.XX.XX
*/
