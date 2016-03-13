/***************************************************
   #>File Name: 3264_1.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/8 23:00:41
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
const int MV=50008;
const int ME=2000006;
const int MOD=1000000007;
const int LOG=18;

int tmin[MV][LOG];
int tmax[MV][LOG];
int value[MV];
int dex[MV];
void init_dex(){
	dex[0]=-1;
	for(int i=1;i<MV;i++){
		if(i&(i-1)) dex[i]=dex[i-1];
		else dex[i]=dex[i-1]+1;
	}
}
void init(int n){
	for(int i=0;i<n;i++){
		tmin[i][0]=value[i];
		tmax[i][0]=value[i];
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=0;i+(1<<j)-1<n;i++){
			int next=i+(1<<(j-1));
			tmin[i][j]=min(tmin[i][j-1],tmin[next][j-1]);
			tmax[i][j]=max(tmax[i][j-1],tmax[next][j-1]);
		}
	}
}
int query(int l,int r){
	int len=r-l+1;
	len=dex[len];
	r-=(1<<len)-1;
	int t1=max(tmax[l][len],tmax[r][len]);
	int t2=min(tmin[l][len],tmin[r][len]);
	return t1-t2;
}
int main(){
	int n,m;
	init_dex();
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++) scanf("%d",&value[i]);
		init(n);
		while(m--){
			int x,y;scanf("%d%d",&x,&y);x--;y--;
			int ans=query(x,y);
			printf("%d\n",ans);
		}
	}
	return 0;
}
