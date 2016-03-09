#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MX = 1e5+10;
const int MOD = 1e9+7;

map <int,int> key;
map <int,int>::iterator tr;
vector< int > number;
int mycount[MX];
int n,m;

void dfs(int level,int ans,int count){
    if(level == n){
        if(key[ans] == 0){
            key[ans] = count;
        }
        else{
            if(key[ans] > count) key[ans] = count;
        }
        return ;
    }
    dfs(level + 1, ans ^ number[level], count + 1);
    dfs(level + 1, ans, count);
}
void solve(){
    number.clear();
    key.clear();
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        int tmp; cin>>tmp;
        number.push_back(tmp);
    }
    dfs(0,0,0);
    /*
    for( tr = key.begin(); tr != key.end(); tr++){
        cout<< tr->first<<endl;
        cout<< tr->second<<endl;
    }*/
    long long ans = 0;
    for(int i = 1; i <= m; i++){
        int u,v;scanf("%d%d",&u,&v);
        long long tmp = mycount[ u ^ v];
        for(tr = key.begin(); tr != key.end(); tr++){
            int o = tr->first;
            int c = tr->second;
            if(tmp > c + mycount[(u ^ o ^ v)]){
                tmp = c + mycount[(u ^ o ^ v)];
            }
        }
    //cout<<tmp;
        ans += (long long) i * tmp;
    }
    cout<<ans<<endl;
}

void init(){
    for(int i = 0; i < MX; i++){
        int tmp = 0;
        int k1 = i;
        while(k1 > 0){
            if(k1 & 1) tmp ++;
            k1 >>= 1;
        }
        mycount[i] = tmp;
    }
}
int main(){
    int cas;
    cin>>cas;
    init();
    while(cas--){
        solve();
    }
    return 0;
}
