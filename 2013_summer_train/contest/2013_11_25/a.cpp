#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#define M 4000
#define ll long long
using namespace std;
ll a[M];
ll c[M][2];
ll q[M][2];
ll vis[M];
map<ll,ll> map1;
int main(){
    ll cas;
    while(~scanf("%lld",&cas)){
        while(cas--){
            map1.clear();
            ll t1,n,m,q1;
            scanf("%lld%lld%lld",&n,&q1,&t1);
            ll en=0;
            for(ll i=0;i<n;i++){
                scanf("%lld%lld",&c[i][0],&c[i][1]);
                if(c[i][0]>c[i][1]) swap(c[i][0],c[i][1]);
                a[en++]=c[i][0];
                a[en++]=c[i][1];
            }
            for(ll i=0;i<q1;i++){
                 scanf("%lld%lld",&q[i][0],&q[i][1]);
                 a[en++]=q[i][0];
                 a[en++]=q[i][1];
            }
//            printf("%lld^^^\n",en);
            sort(a,a+en);
            en=unique(a,a+en)-a;
//            printf("%lld^^^^\n",en);
            ll dex=1;
            map1[a[0]]=1;
            for(ll i=1;i<en;i++){
                if(a[i-1]==a[i]-1){
                    map1[a[i]]=++dex;
                }
                else{
                    dex++;
                    map1[a[i]]=++dex;
                }
            }
            memset(vis,0,sizeof(vis));
            for(ll i=0;i<n;i++){
                for(ll j=map1[c[i][0]];j<=map1[c[i][1]];j++){
                    vis[j]=1;
                }
            }
            for(ll i=0;i<q1;i++){
                ll flag=1;
                for(ll j=map1[q[i][0]];j<=map1[q[i][1]];j++){
                    if(vis[j]==0) flag=0;
                }
                if(flag) puts("YES");
                else puts("NO");
            }
        }
    }
    return 0;
}
