#include <iostream>
#include <cstring>
#include <cstdio>
#define inf 0x3f3f3f3f
#define MAXNODE 3000
#define MAXEDGE MAXNODE*5
#define MIN(a,b) ((a)<(b)?(a):(b))
#define OPPOSITE(x) (((x)&1)?((x)+1):((x)-1))
#define INFINIT inf
using namespace std;
int n,m;
int N,S,T;
int begin[MAXNODE+1],end[MAXEDGE+1],next[MAXEDGE+1],c[MAXEDGE+1],cost[MAXEDGE+1],d[MAXNODE+1],cur[MAXNODE+1];
bool hash[MAXNODE+1];
int Count = 0;
int aug(int u,int f){
    if (u == T) return f;
    hash[u] = true;
    for (int now = cur[u]; now; now = next[now])
        if (c[now]&&!hash[end[now]]&&d[u] == d[end[now]]+cost[now])
            if (int tmp = aug(end[now],MIN(f,c[now])))
                return c[now] -= tmp,c[OPPOSITE(now)] += tmp,cur[u] = now,tmp;
    return 0;
}
bool modlabel(){
    int tmp = INFINIT;
    for (int i = 1; i<=N; i++)
        if (hash[i])
            for (int now = begin[i]; now; now = next[now])
                if (c[now]&&!hash[end[now]])
                    tmp = MIN(tmp,d[end[now]]+cost[now]-d[i]);
    if (tmp == INFINIT)
        return true;
    for (int i = 1; i<=N; i++)
        if (hash[i])
            hash[i] = false,d[i] += tmp;
    return false;
}
int CostFlow(){
    int costflow = 0,tmp;
    while (true){
        for (int i = 1; i<=N; i++)
            cur[i] = begin[i];
        while (tmp = aug(S,~0U>>1)){
            costflow += tmp*d[S];
            memset(hash,0,sizeof(hash));
        }
        if (modlabel())
            break;
    }
    return costflow;
}
void AddEdge(int a,int b,int flow, int v){
    Count++; next[Count] = begin[a]; begin[a] = Count; end[Count] = b; c[Count] = flow; cost[Count] = v;
    Count++; next[Count] = begin[b]; begin[b] = Count; end[Count] = a; c[Count] = 0; cost[Count] = -v;
}
int change(int x){
    return x+2;
}
int main(){
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)){
        int sp=2,tp=2*n+3,spp=1;
        Count=0;
        AddEdge(spp,sp,k,0);
        for(int i=1;i<=n;i++){
            int t1=change(i);
            AddEdge(sp,t1,inf,0);
            AddEdge(sp,t1+n,inf,0);
            AddEdge(t1+n,tp,inf,0);
            if(i!=n){
                AddEdge(t1,t1+1,inf,0);
                AddEdge(t1+n,t1+1,inf,0);
            }
        }
        for(int i=0;i<m;i++){
            int u,v,cost;scanf("%d%d%d",&u,&v,&cost);
            int t1=change(u);
            int t2=change(v);
            AddEdge(t1,t2+n,1,-cost);
        }
//        puts("~~~~");
        S=spp;T=tp;N=tp;
        int ans=CostFlow();
        printf("%d\n",-ans);
    }
    return 0;
}
