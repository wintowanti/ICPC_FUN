#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int MX = 1e6;
struct Edge{
    int u,v,val,id;
    Edge(){

    }
    Edge(int u,int v, int val, int id):u(u),v(v),val(val),id(id){

    }
    friend bool operator < (const Edge& edge1, const Edge& edge2){
        return edge1.val < edge2.val;
    }
};
Edge edge[MX];
int fa[MX];
int max_val[MX];
int count_size[MX];
set <int> values[MX];
int ans [MX][2];
int find_fa(int x){
    if(fa[x] != x) fa[x] = find_fa(fa[x]);
    return fa[x];
}
void merge(set<int>& large, set<int>& small){
    for(auto it = small.begin(); it != small.end(); it++){
        large.insert(*it);
    }
}
int main(){
    int n,m;
    while(cin>>n>>m){
        for(int i = 1; i <= n; i++){
            fa[i] = i;
            max_val[i] = i;
            count_size[i] = 1;
            values[i].clear();
            values[i].insert(i);
        }
        for(int i = 0; i < m; i++){
            int u,v,val;scanf("%d%d%d",&u,&v,&val);
            edge[i] = Edge(u,v,val,i);
        }
        sort(edge,edge+m);
        for(int i = 0; i < m; i++){
            int u = edge[i].u;
            int v = edge[i].v;
            int id = edge[i].id;
            int fa1 = find_fa(u);
            int fa2 = find_fa(v);
            if(count_size[fa2] > count_size[fa1]) swap(fa1,fa2);

            if(fa1 == fa2){
                ans[id][0] = ans[id][1] = 0;
            }
            else{
                fa[fa2] = fa1;
                count_size[fa1] += count_size[fa2];

                if(max_val[fa1] < max_val[fa2]){
                    ans[id][0] = max_val[fa1];
                    ans[id][1] = *(values[fa2].upper_bound(ans[id][0]));
                }
                else{
                    ans[id][0] = max_val[fa2];
                    ans[id][1] = *(values[fa1].upper_bound(ans[id][0]));
                }

                merge(values[fa1], values[fa2]);

                max_val[fa1] = max(max_val[fa1], max_val[fa2]);
            }

        }
        for(int i = 0; i < m; i++){
            printf("%d %d\n",ans[i][0], ans[i][1]);
        }
    }
    return 0;
}
