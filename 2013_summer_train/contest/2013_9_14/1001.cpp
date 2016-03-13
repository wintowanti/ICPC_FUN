#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll int
#define lson i<<1
#define rson i<<1|1
using namespace std;
ll const M = 100000+9;
ll inf = (1<<30)+55;
struct node {
 ll left;
 ll right;
 ll val;
}tree[M<<2];
ll a[M];
void build(ll l,ll r,ll i){
  tree[i].left = l;
  tree[i].right = r;
  if(l==r) {
   tree[i].val = a[l];
   return ;
  }
  ll mid = (l+r) >>1;
  build(l,mid,lson);
  build(mid+1,r,rson);
  tree[i].val= tree[lson].val|tree[rson].val;
}
ll query(ll l,ll r,ll i){
 if(tree[i].left==l&&tree[i].right==r) {
  return tree[i].val;
 }
 ll mid=(tree[i].left + tree[i].right) >>1;
 if(r<=mid) return query(l,r,lson);
 else if(l>mid) return query(l,r,rson);
 else return query(l,mid,lson)|query(mid+1,r,rson);
}
ll bin(ll l,ll r,ll k){
    ll tmin;
    tmin=inf;
    ll u=l;
  while(l<=r){
  ll mid =(l+r) >>1;
  ll o= query(u,mid,1);
  //printf("o is %d ****\n",o);
  if(o<k) {
   l=mid+1;
  }
  else{
    tmin=mid;
    r=mid-1;
  }
 }
 //system("pause");
 return tmin;
}
int main(){
  ll T;
  ll u=1;
  //printf("%d\n",(1<<30)-inf);
  cin>>T;
  while(T--){
   ll n,m;
   cin>>n>>m;
   for(ll i=1;i<=n;i++)
   scanf("%d",a+i);
   a[n+1]=inf;
   build(1,n+1,1);
   __int64 ans=0;
   for(ll i=1;i<=n;i++){
    if(a[i]>=m) continue;
    ll p=bin(i,n+1,m);
   // printf("%d***\n",p);
    ans+=(p-i);
   }
   printf("Case #%d: %I64d\n",u++,ans);
  }
}
