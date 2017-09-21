#include <cmath>  
#include <vector>  
#include <cstdio>  
#include <climits>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define  pb push_back  
#define  mp make_pair  
#define  sz(x) ((int)(x).size())  
using namespace std;  
  
const int N = 500010;  
const int INF = (int)1e9;  
int fa[N], L[N], n, m, anc[N][33];  
int maxcost[N][33], cost[N], que[N * 10];  
struct Edge {  
    int e, w, next;  
}edge[N * 10];  
int head[N], cnt = 0, dis[N];  
  
void addedge(int a, int b, int w){  
    edge[cnt].e = b;  
    edge[cnt].w = w;  
    edge[cnt].next = head[a];  
    head[a] = cnt++;  
}  
  
struct LCA_online {  
    void initi(){  
        cnt = cost[1] = L[1] = 0;  
        memset(head, -1, sizeof head);  
    }  
  
    void dfs(int u, int f) {  
        fa[u] = f;  
        for(int it = head[u]; ~it; it = edge[it].next) {  
            int v = edge[it].e, w = edge[it].w;  
            if(v != f) {  
                cost[v] = w;  
                L[v] = L[u] + 1;  
                dfs(v, u);  
            }  
        }  
    }  
  
    void process() {  
        for(int i = 1; i <= n; i++) {  
            anc[i][0] = fa[i], maxcost[i][0] = cost[i];  
            for(int j = 1; (1 << j) < n; j++) anc[i][j] = -1;  
        }  
        for(int j = 1; (1 << j) < n; j++)  
            for(int i = 1; i <= n; i++)  
                if(anc[i][j - 1] != -1) {  
                    int a = anc[i][j - 1];  
                    anc[i][j] = anc[a][j - 1];  
                    maxcost[i][j] = max(maxcost[i][j - 1], maxcost[a][j - 1]);  
                }  
    }  
      
    int query(int p, int q) {  
        int lo;  
        if(L[p] < L[q]) swap(p, q);  
        for(lo = 1; (1 << lo) <= L[p]; lo++); lo--;  
        int ans = -INF;  
        for(int i = lo; i >= 0; i--)  
            if(L[p] - (1 << i) >= L[q])   
                ans = max(ans, maxcost[p][i]), p = anc[p][i];  
        if(p == q)  
            return p;         
//          return ans; //LCA -> p  
        for(int i = lo; i >= 0; i--)  
            if(anc[p][i] != -1 && anc[p][i] != anc[q][i]) {  
                ans = max(ans, maxcost[p][i]), p = anc[p][i];  
                ans = max(ans, maxcost[q][i]), q = anc[q][i];  
            }  
        return fa[p];  
//    return max(ans, max(cost[p], cost[q])); //LCA -> fa[q] fa[p]  
    }  
}g;  
  
void bfs() {  
    int fr = 0, rear = 0;  
    que[rear++] = 1;  
    dis[1] = 0;  
    while(fr < rear) {  
        int deq = que[fr++];  
        for(int it = head[deq]; ~it;it = edge[it].next  ) {  
            int e = edge[it].e, w = edge[it].w;  
            if(dis[e] == -1) {  
                dis[e] = dis[deq] + w;  
                que[rear++] = e;  
            }  
        }  
    }  
}  
  
int main() {  
    int T;  
    cin >> T;  
    while(T--) {  
        g.initi();  
        memset(dis, -1, sizeof dis);  
        cin >> n >> m; 
        for(int i = 0; i < n - 1; i++) {  
            int a, b, w;  
            scanf("%d%d", &a, &b);  
            addedge(a, b, 1);  
            addedge(b, a, 1);         
        }  
        g.dfs(1, -1);  
        g.process();  
        bfs();  
        while(m--) {  
            int x1,y1,x2,y2;  
            scanf("%d%d%d%d", &x1,&y1,&x2,&y2);  
            int fa1 = g.query(x1, y1);  
            int fa2 = g.query(x2, y2);
            int fafa = g.query(fa1,fa2);
            if(fafa != fa1 && fafa != fa2){
                puts("NO");
            }
            else{
                if(fafa == fa1 && fafa==fa2){
                    puts("YES");
                }
                else if(fafa == fa1){
                    if(g.query(fa2,x1) == fa2 || g.query(fa2,y1) == fa2){
                        puts("YES");
                    }
                    else{
                        puts("NO");
                    }
                }
                else{
                    if(g.query(fa1,x2) == fa1 || g.query(fa1,y2) == fa1){
                        puts("YES");
                    }
                    else{
                        puts("NO");
                    }
                }
            }
        }  
    }  
    return 0;  
}  
