#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MX = 500000;
typedef __int64 LL;
struct LR
{
	/* data */
	LL l,r,id;
	friend bool operator < (const LR lr1,const LR lr2){
		if(lr1.l!=lr2.l){
			if(lr1.l<lr2.l) return 1;
			return 0;
		}
		else{
			if(lr1.r<lr2.r) return 1;
			return 0;
		}
	}
};
struct RL
{
	/* data */
	LL l,r,id;
	friend bool operator < (const RL lr1,const RL lr2){
		if(lr1.r!=lr2.r){
			if(lr1.r>lr2.r) return 1;
			return 0;
		}
		else{
			if(lr1.l<lr2.l) return 1;
			return 0;
		}
	}
};
struct E
{
	LL length;
	LL id;
	friend bool operator < (const E e1,const E e2){
		if(e1.length<e2.length)	 return 1;
		return 0;
	}
	/* data */
};
LL num[MX][2];
vector< E > stick;
vector<LR > v_lr;
LL ans[MX];
priority_queue<RL > pq_rl;
int main(){
	LL n,m;
	while(cin>>n>>m){
		for(LL i=0;i<n;i++) cin>>num[i][0]>>num[i][1];
		stick.clear();
		for(LL i=0;i<m;i++){
			E e1; cin>>e1.length;e1.id=i+1;
			stick.push_back(e1);
		}
		sort(stick.begin(),stick.end());
		v_lr.clear();
		for(LL i=1;i<n;i++){
			LR lr1;
			lr1.l=num[i][0]-num[i-1][1];
			lr1.r=num[i][1]-num[i-1][0];
			lr1.id=i;
			v_lr.push_back(lr1);
		}
		sort(v_lr.begin(),v_lr.end());
		memset(ans,-1,sizeof(ans));
		LL j=0;
		while(!pq_rl.empty())pq_rl.pop();
		LL flag=0;
		for(LL i=0;i<stick.size();i++){
			if(flag) continue;
			while(j<v_lr.size()&&v_lr[j].l<=stick[i].length){
				RL rl1;
				rl1.l=v_lr[j].l;
				rl1.r=v_lr[j].r;
				rl1.id=v_lr[j].id;
				pq_rl.push(rl1);
				j++;
			}
			while(!pq_rl.empty()){
				RL rl1;rl1=pq_rl.top();pq_rl.pop();
				if(rl1.r>=stick[i].length){
					ans[rl1.id]=stick[i].id;
					break;
				}
				else{
					flag=1;
					break;
				}
			}
		}
		for(LL i=1;i<n;i++){
			if(ans[i]==-1) flag=1;
		}
		if(flag) puts("No");
		else{
			puts("Yes");
			for(LL i=1;i<n;i++){
				if(i==1){
					cout<<ans[i];
				}
				else{
					cout<<" "<<ans[i];
				}
			}
			puts("");
		}
	}
	return 0;
}
