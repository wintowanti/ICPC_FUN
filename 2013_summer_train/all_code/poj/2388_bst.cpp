/***************************************************
   #>File Name: 2388_bst.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/24 21:16:03
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

set<int> myset;
set<int> ::it it1;
struct Node{
	int value;
	Node *next[2];
}* root;
int value[MV];
void insert(int m1){
	Node *tr,*fa;
	tr=root;
	while(1){
		fa=tr;
		int id;
		if(tr->value>m1) id=0; else id=1;
		tr=tr->next[id];
		if(tr==NULL){
			tr=new Node();
			tr->value=m1;
			fa->next[id]=tr;
			break;
		}
	}
}
int en;
void dfs(Node * tr){
	if(tr->next[0]!=NULL) dfs(tr->next[0]);
	value[en++]=tr->value;
	if(tr->next[1]!=NULL) dfs(tr->next[1]);
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++) scanf("%d",&value[i]);
		/*root=new Node();
		root->value=value[0];
		for(int i=1;i<n;i++){
			insert(value[i]);
		}
		en=0;
		dfs(root);*/
		myset.clear();
		for(int i=0;i<n;i++) myset.insert(value[i]);
		int en=0;
		for(it1=myset.begin();it1!=myset.end();it1++){
			value[en++]=*it1;
		}
		if(n&1){
			printf("%d\n",value[n/2]);
		}
		else{
			int ans=value[n/2]+value[(n/2)-1];
			ans/=2;
			printf("%d\n",ans);
		}
	}
	return 0;
}
