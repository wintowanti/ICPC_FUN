#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;
int dfs(ll n,ll m){
    if(n%m==0) return 1;
    if(2*m<n)  return 1;
    return !dfs(m,n%m);
}
int main(){
    ll m,n;
    int cas;scanf("%d",&cas);
    while(cas--){
        cin>>n>>m;
        if(n<m) swap(n,m);
        int ans=dfs(n,m);
   //     printf("%d\n",ans);
        if(ans){
            puts("Stan wins");
        }else{
            puts("Ollie wins");
        }
    }
    return 0;
}
