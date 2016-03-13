#include<stdio.h>
#include<math.h>
#include<iostream>
#include<set>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
bool isprime[100];
ll prime[100];
int num;
void getprime(){
    num=0;
    memset(isprime,0,sizeof(isprime));
    isprime[0]=isprime[1]=1;
    for(int i=2;i<=80;i++){
        if(!isprime[i]){
            for(int j=i*i;j<=80;j+=i) isprime[j]=1;
        }
    }
    for(ll i=2;i<=80;i++)
        if(!isprime[(int)i]) prime[num++]=i;
}
set<ll> myset;
ll n,p;
void dfs(int idx,ll cnt,ll now){
    if(cnt>n) return ;
    myset.insert(now);
    for(int i=idx;i<num&&prime[i]+cnt<=n;i++){
        ll tmp=now*prime[i]%p;
//        if(myset.find(tmp)!=myset.end()) continue;
        dfs(i,cnt+prime[i],tmp%p);
    }
}
int main(){
    int t;
    getprime();
//    for(int i=0;i<num;i++) printf("%lld ",prime[i]);
//    puts("");
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&p);
        if(p<=n){
            printf("%lld\n",p);
            continue;
        }
        myset.clear();
        dfs(0,0,1);
//        for(it=myset.begin();it!=myset.end();it++) printf("%lld ",*it);
//        puts("");
        cout<<myset.size()<<endl;
    }
}
