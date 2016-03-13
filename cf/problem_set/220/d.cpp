/***************************************************
   #>File Name: d.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2013/12/19 21:36:30
***************************************************/

#include<cstdio>
#include<iostream>
#include<cstring>
#define M 1000800
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std ;
int lowbit(int x){
	return x&(-x);
}
struct Z{
	int value[M];
	void insert(int id,int k){
		while(id<M){
			value[id]+=k;
			id+=lowbit(id);
		}
	}
	int query(int id){
		int tsum=0;
		while(id>0){
			tsum+=value[id];
			id-=lowbit(id);
		}
		return tsum;
	}
	void init(){
		memset(value,0,sizeof(value));
	}
}ztree;
int dex[M];
int flag[M];
int n,m;
int en;
int binary(int l,int r,int k){
	int tmin=r;
	while(l<=r){
		int mid=(l+r)>>1;
		int t1=ztree.query(mid);
		if(t1>=k){
			tmin=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return tmin;
}
int f(int num){
	int tsum=0;
	int mark=-1;
	for(int i=0;i<m;i++){
		if(dex[i]>num) break;
		mark=i;
	}
	for(int i=mark;i>=0;i--){
		tsum++;
		int id=binary(1,en,dex[i]);
		ztree.insert(id,-1);
	}
	tsum=num-tsum;
	return tsum;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<m;i++) scanf("%d",&dex[i]);
		en=0;
		int num=0;
		ztree.init();
		for(int i=0;i<n;i++){
			int t1;scanf("%d",&t1);
			if(t1==0){
				en++;
				num++;
				ztree.insert(en,1);
				flag[en]=0; 
			}
			else if(t1==1){
				en++;
				num++;
				ztree.insert(en,1);
				flag[en]=1;
			}
			else if(t1==-1){
				num=f(num);
			}
		}
		if(num==0){
			puts("Poor stack!");
		}else{
			for(int i=1;i<=en;i++){
				int t1;
				if(i==1) t1=ztree.query(1);
				else t1=ztree.query(i)-ztree.query(i-1);
				if(t1==1){
					printf("%d",flag[i]);
				}
			}
			puts("");
		}
	}
	return 0;
}
