#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#define inf 0x3f3f3f3f
using namespace std;
const int NV = 158000;
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
        while (dis[src] < n) {//��������1
loop:
            for (int &i = cur[u]; i != -1; i = E[i].next) {
                int v = E[i].v;
                if (E[i].w && dis[u] == dis[v] + 1) {
                    aug = min(aug, E[i].w);
                    pre[v] = u;
                    u = v;
                    if (v == des) {//�ҵ�һ������·������
                        maxflow += aug;
                        // //�޸Ĳ�������
                        for (u = pre[u]; v != src; v = u, u = pre[u]) {
                            E[cur[u]].w -= aug;//�����
                            E[cur[u]^1].w += aug;//�����
                        }
                        aug = INT_MAX;
                    }//if
                    goto loop;
                }//for
            }//for
            //Ѱ����С�ľ����ţ����޸ĵ�ǰ��    Ϊ��С�ı��+1
            int mdis = n;
            for (int i = head[u]; i != -1; i = E[i].next) {
                int v = E[i].v;
                if (E[i].w && mdis > dis[v]) {
                    cur[u] = i;
                    mdis = dis[v];
                }
            }//for

            //GAP �Ż� �ϲ������� ��������2
            if ((--gap[dis[u]]) == 0) {
                break;
            }
            gap[dis[u] = mdis + 1]++;//��ӵ�иñ�ŵ�������1
            u = pre[u];//��ǰ�ڵ� Ǩ��һ��
        }//while
        return maxflow;
    }//ISAP
}g1;
int main(){
    int m,n;
    while(~scanf("%d%d",&m,&n)){
        int sp=0,tp=n+1;
        g1.init(tp);
        g1.insert(sp,1,inf);
        g1.insert(n,tp,inf);
        for(int i=0;i<m;i++){
            int u,v,cost;scanf("%d%d%d",&u,&v,&cost);
            g1.insert(u,v,cost);
        }
        int ans=g1.MaxFlow(sp,tp);
        printf("%d\n",ans);
    }
    return 0;
}
/*
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
*/
