#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;

const int MX = 1e5 + 9;
const int INF =  0x3f3f3f3f;
const int MOD = 1e9+7;
int in_degree[MX];
vector< int > graph[MX];
struct T{
    struct E{
        int l,r,value;
    };
    E e[MX << 2];
    void push_up(int rt){
        e[rt].value =  min(e[lson].value, e[rson].value);
    }
    void build(int l,int r,int rt){
        e[rt].l = l; e[rt].r = r;
        if(l == r){
            e[rt].value = in_degree[l];
            return ;
        }
        int mid = (e[rt].l + e[rt].r) >> 1;
        build(l, mid, lson);
        build(mid + 1, r, rson);
        push_up(rt);
    }
    int query(int k,int rt){
        if(e[rt].l == e[rt].r){
            return e[rt].l;
        }
        if(e[lson].value <= k) return query(k, lson);
        return query(k, rson);
    }
    void update(int l,int value,int rt){
        if(e[rt].l == l && e[rt].r == l ){
            e[rt].value = value;
            return ;
        }
        int mid = (e[rt].l + e[rt].r) >> 1;
        if(l <= mid) update(l, value, lson);
        else update(l, value, rson);
        push_up(rt);
    }
}tr;
int n,m,k;

void init(){
    for(int i = 0; i <= n; i++) graph[i].clear();
    memset(in_degree, 0, sizeof(in_degree));
}
void solve(){
    scanf("%d%d%d",&n,&m,&k);
    init();
    for(int i = 0; i < m; i++){
        int u,v; scanf("%d%d",&u,&v);
        graph[u].push_back(v);
        in_degree[v] ++;
    }
    tr.build(1,n,1);
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        int u = tr.query(k, 1);
        k -= in_degree[u];
        in_degree[u] = INF;
        tr.update(u, INF, 1);
        for(int j = 0 ; j < graph[u].size(); j++){
            in_degree[ graph[u][j] ] --;
            tr.update(graph[u][j], in_degree[ graph[u][j] ], 1);
        }
        //cout<<u<<endl;
        ans += (long long ) u * (long long) i;
        ans %= MOD;
    }
    cout<<ans<<endl;
}
int main(){
    int cas; cin>> cas;
    while(cas--){
        solve();
    }
    return 0;
}
