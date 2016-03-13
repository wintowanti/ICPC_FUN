#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#define lson i<<1
#define rson i<<1|1
using namespace std;
int const M = 25330;
struct node {
int left,right,val;
}tree[M<<2];
void build(int l,int r,int i){
tree[i].left = l;
tree[i].right = r;
tree[i].val =0;
if(l==r) return ;
int mi = (l+r) >>1;
build(l,mi,lson);
build(mi+1,r,rson);
}
void push(int i){
tree[i].val =tree[lson].val + tree[rson].val;
}
void insert(int l,int i){
if(tree[i].left ==l&&tree[i].right==l) {
tree[i].val ++;
return ;
}
int mi = (tree[i].left+ tree[i].right ) >>1;
if(l<=mi) insert(l,lson);
else insert(l,rson);
push(i);
}
int query(int l,int r,int i){
// puts("fdklgjfd");
if(tree[i].left==l&&tree[i].right==r) {
return tree[i].val;
}
int mid =(tree[i].left +tree[i].right) >>1;
if(r<=mid) return query(l,r,lson);
else if(l>mid) return query(l,r,rson);
else return query(l,mid,lson)+query(mid+1,r,rson);
}
map<string,int > mp;
int main(){
int n;
while(cin>>n){
string b;
mp.clear();
for(int i=0;i<n;i++){
cin>>b;
mp[b]=i+1;
// printf("%d\n",mp[b]);
}
build(1,n,1);
int ans=0;
// cin>>b;
// insert(mp[b],1);
for(int i=1;i<=n;i++){
cin>>b;
ans+=query(1,mp[b],1);

//rintf("%d\n",mp[b]);
insert(mp[b],1);
// puts("dfkgjf");
}
int u =(n*(n-1))/2;
printf("%d/%d\n",ans,u);
}
}
