#include <cstdio>
#include <iostream>
#include <cstring>
#define lson (rt<<1)
#define rson (rt<<1|1)
using namespace std;

const int MX = 123456;
struct E{
	int left,top,right;
	int l,r,lazy;
	E(){ left = top = right = l = r = lazy = 0; }
	void init(int key){
		left = top = right = 0;
		if(key == 0){
			top = r - l +1;
		}
		else if(key == 1){
			left = r - l +1;
		}
		else if(key == -1){
			right = r - l +1;
		}
	}
	friend E operator + (const E e1,const E e2){
		E ans;
		ans.left = e1.left + e2.left;
		ans.top = e1.top + e2.top;
		ans.right = e1.right + e2.right;
		return ans;
	}
	void zero(){
		right = top = left = lazy = 0;
	}
	void display(){
			cout<<left<<" "<<top<<" "<<right<<endl;
	}
};
struct T{
	E e[MX<<2];
	void push_up(int rt){
		e[rt].left = e[lson].left + e[rson].left;
		e[rt].top = e[lson].top + e[rson].top;
		e[rt].right = e[lson].right + e[rson].right;
	}
	void push_down(int rt){
		if(e[rt].lazy != 0){
			if(e[rt].lazy == 1){
				e[lson].lazy = 1; e[lson].init(1);
				e[rson].lazy = 1; e[rson].init(1);
			}
			else if(e[rt].lazy == -1){
				e[lson].lazy = -1; e[lson].init(-1);
				e[rson].lazy = -1; e[rson].init(-1);
			}
		}
		e[rt].lazy = 0;
	}
	void build(int l,int r,int rt){
		e[rt].zero(); e[rt].l = l; e[rt].r = r;
		if(l == r){
			e[rt].top = 1;
			return ;
		}
		int mid = (l + r)>>1;
		build(l,mid,lson);
		build(mid+1,r,rson);
		push_up(rt);
	}
	void set(int l,int r,int rt,int flag){
		if(l <= e[rt].l && r >= e[rt].r){
			e[rt].lazy = flag;
			e[rt].init(flag);
			return ;
		}
		push_down(rt);
		int mid = (e[rt].l + e[rt].r)>>1;
		if(l <= mid) set(l,r,lson,flag);
		if(r > mid)  set(l,r,rson,flag);
		push_up(rt);
	}
	E  query(int l,int r,int rt){
		if(l <= e[rt].l && r >= e[rt].r){
			return e[rt];
		}
		push_down(rt);
		E tmp;
		int mid = (e[rt].l + e[rt].r)>>1;
		if(l <= mid) tmp = tmp + query(l,r,lson);
		if(r > mid)  tmp = tmp + query(l,r,rson);
		push_up(rt);
		return tmp;
	}
}tr;
int main(){
	int m,n;
	while(cin>>m>>n){
		tr.build(1,n,1);
		//tr.e[1].display();
		for(int i = 0; i < m; i++){
			char tmp; int l,r; cin>>tmp>>l>>r;
			if(tmp == 'F'){
				if(l > r) tr.set(r,l,1,1);
				else if(l < r) tr.set(l,r,1,-1);
			}
			else{
				E ans = tr.query(l,r,1);
				ans.display();
			}
		}
	}
	return 0;
}
