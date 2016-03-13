/***************************************************
   #>File Name: 1806.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/6 22:11:05
***************************************************/

#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<set>

using namespace std ;

#define int int
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define it iterator
#define mt(a,b) memset(a,b,sizeof(a))

typedef pair<int,int> pii;
typedef long long ll;

const int INF=0x3f3f3f3f;
const int MV=300008;
const int ME=2000006;
const int MOD=1000000007;
const int N=100000;

int dex[MV];
int l[MV],r[MV];
int tmax[MV][20];
int value[MV]; 
void init_dex(){
	dex[0]=-1;
	for(int i=1;i<MV;i++){
		if(i&(i-1)) dex[i]=dex[i-1];
		else dex[i]=dex[i-1]+1;
	}
}
int query(int l,int r){
	if(r<l)return 0;
	int len=r-l+1;
	len=dex[len];
	r-=(1<<len)-1;
	return max(tmax[l][len],tmax[r][len]);
}
int main(){
	init_dex();
	int n,q;
	while(~scanf("%d",&n)){
		if(n==0) break;
		scanf("%d",&q);
		mt(tmax,-INF);
		for(int i=0;i<n;i++){
			int t1;scanf("%d",&t1);t1+=N;value[i]=t1;
		}
		l[value[0]]=r[value[0]]=0;
		tmax[0][0]=1;
		for(int i=1;i<n;i++){
			if(value[i]==value[i-1]){
				tmax[i][0]=tmax[i-1][0]+1;
				r[value[i]]=i;
			}
			else{
				l[value[i]]=r[value[i]]=i;
				tmax[i][0]=1;
			}
		}
		for(int j=1;(1<<j)<=n;j++){
			for(int i=0;i+(1<<j)-1<n;i++){
				int nexti=i+(1<<(j-1));
				tmax[i][j]=max(tmax[i][j-1],tmax[nexti][j-1]);
			}
		}
		while(q--){
			int x,y;scanf("%d%d",&x,&y);x--;y--;
			int t1=r[value[x]]-x+1;
			t1=min(y-x+1,t1);
			int t2=y-l[value[y]]+1;
			t2=min(y-x+1,t2);
			t1=max(t1,t2);
			t2=query(r[value[x]]+1,l[value[y]]-1);
			t1=max(t1,t2);
			printf("%d\n",t1);
		}
	}
	return 0;
}
