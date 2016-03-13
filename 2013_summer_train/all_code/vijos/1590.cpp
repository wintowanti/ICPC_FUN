#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#define inf 0x3f3f3f3f
using namespace std;
const int NV = 1580;
const int NE = 4500;
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
int main()
{
    int cas;
    while(~scanf("%d",&cas)){
        while(cas--){
            int n,m;scanf("%d%d",&n,&m);
            int sp=0;int tp=2*n+1;
            g1.init(2*n+20);
            g1.insert(0,1,inf);
            for(int i=1;i<n;i++){
                int t1;scanf("%d",&t1);g1.insert(i*2,i*2+1,t1);
            }
            g1.insert(2*n,2*n+1,inf);
            for(int i=0;i<m;i++){
                int t1,t2;scanf("%d%d",&t1,&t2);g1.insert(t1*2+1,t2*2,inf);g1.insert(t2*2+1,2*t1,inf);
            }
            int ans=g1.MaxFlow(sp,tp);
            if(ans==0){
                puts("Min!");
            }
            else if(ans==inf){
                puts("Max!");
            }
            else {
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
/*
1
4 5
2 3 4
0 1
0 3
1 2
2 4
3 4
100
4 0
1 2 3
1 1
0 1
*/
