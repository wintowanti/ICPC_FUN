#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdexcept>
#include<bitset>
#include<cassert>
#include<deque>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
const double eps=1e-12;
const int INF=0x3f3f3f3f;
const ll MOD=1000000007;
const int N=100005;
struct node
{
    int l,r,L,R;
}tree[N*4];
int num[N];
int a[N],b[N];
map<int,int>mt;
void dfsb(int x,int l,int r)
{
    tree[x].l=l;
    tree[x].r=r;
    tree[x].L=0;
    tree[x].R=0;
    if(l==r) return ;
    int mid=(l+r)>>1;
    dfsb((x<<1),l,mid);
    dfsb((x<<1)|1,mid+1,r);
}
void dfsm(int x,int l,int r,int &L,int &R)
{
    if(l>r) return;
    if(tree[x].l==l&&tree[x].r==r)
    {
        L=max(tree[x].L,L);
        R=max(tree[x].R,R);
        return ;
    }
    int mid=(tree[x].l+tree[x].r)>>1;
    if(r<=mid)
    dfsm((x<<1),l,r,L,R);
    else if(l>mid)
    dfsm((x<<1)|1,l,r,L,R);
    else
    {
        dfsm((x<<1),l,mid,L,R);
        dfsm((x<<1)|1,mid+1,r,L,R);
    }
}
void dfsu(int x,int k,int L,int R)
{
    tree[x].L=max(tree[x].L,L);
    tree[x].R=max(tree[x].R,R);
    if(tree[x].l==tree[x].r)
    return ;
    int mid=(tree[x].l+tree[x].r)>>1;
    if(k<=mid)
    dfsu((x<<1),k,L,R);
    else
    dfsu((x<<1)|1,k,L,R);
}
int solve(int *a,int n)
{
    memset(num,0,sizeof(num));
    int ans=0;
    dfsb(1,1,n);
    for(int i=n-1;i>=0;--i)
    {
        int k=a[i];
        int L=0,R=0;
        L=0;
        dfsm(1,1,k,L,R);
        int s1=L+1;
        L=0;
        dfsm(1,1,k-1,L,R);
        int r1=L;
        R=0;
        dfsm(1,k,n,L,R);
        int s2=R+1;
        R=0;
        dfsm(1,k+1,n,L,R);
        int r2=R;
        ++num[k];
        ans=max(ans,max(s1+r2,s2+r1));
        dfsu(1,k,s1,s2);
    }
    return ans;
}
int main()
{
    //freopen("data.in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
       int n;
       scanf("%d",&n);
       for(int i=0;i<n;++i)
       {
           scanf("%d",&a[i]);
           b[i]=a[i];
       }
       mt.clear();
       sort(b,b+n);
       int l=0;
       for(int i=0;i<n;++i)
       {
           if(i==0||b[i]!=b[i-1])
           b[l++]=b[i];
       }
       int ln=l;
       for(int i=0;i<ln;++i)
       mt[b[i]]=i+1;
       for(int i=0;i<n;++i)
       a[i]=mt[a[i]];
       printf("%d\n",solve(a,n));
    }
    return 0;
}
