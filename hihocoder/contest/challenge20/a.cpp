#include <cstdio>
#include <iostream>
#include <cstring>
#define lson (rt<<1)
#define rson (rt<<1|1)

using namespace std;
const int MX = 1e6;
struct T{
    struct E{
        int l,r,value;
    }e[MX];
    void push_up(int rt){
        e[rt].value = max(e[lson].value,e[rson].value);
    }
    void build(int l,int r,int rt){
        e[rt].l = l; e[rt].r = r;
        if(l == r){
            e[rt].value = -1;
            return ;
        }
        int mid = (e[rt].l + e[rt].r) >>1;
        build(l, mid, lson);
        build(mid+1, r, rson);
        push_up(rt);
    }
    void update(int ul,int value,int rt){
        if(e[rt].l == ul && e[rt].r == ul){
            if(e[rt].value < value) e[rt].value = value;
            return ;
        }
        int mid = (e[rt].l + e[rt].r) >>1;
        if(ul <= mid) update(ul,value,lson);
        else update(ul,value,rson);
        push_up(rt);
    }
    int query(int ul,int ur,int rt){
        if(ul <= e[rt].l && ur >= e[rt].r){
            return e[rt].value;
        }
        int mid = (e[rt].l + e[rt].r) >>1;
        int ans = -1;
        if(ul <= mid) ans = max(ans,query(ul,ur,lson));
        if(ur > mid) ans = max(ans,query(ul,ur,rson));
        return ans;
    }
}tr;
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        tr.build(1,100008,1);
        for(int i =0; i < n; i++){
            int t,v;scanf("%d%d",&t,&v);
            tr.update(t,v,1);
        }
        for(int i = 0; i < m; i++){
            int a,b;scanf("%d%d",&a,&b);
            int ans = tr.query(a,b,1);
            if(ans == -1) puts("None");
            else printf("%d\n",ans);
        }
    }
    return 0;
}
