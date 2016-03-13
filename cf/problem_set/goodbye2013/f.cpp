/***************************************************
   #>File Name: f.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/4 10:24:27
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
const int ME=1000006;
const int MOD=1000000007;

#define M ME
#define inf 0x3f3f3f3f
/*
init(n*(log(n)) query(1)
first init_dex;
before dfs en=0
*/
using namespace std;
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M+100];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int lv[2*M];
int aa[2*M],bb[2*M],en;
void dfs(int u,int level){
    lv[u]=level;
    aa[en]=u;
    bb[en++]=level;
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        dfs(v,level+1);
        aa[en]=u;bb[en++]=level;
    }
}
int dex[M];
void init_dex(){
    dex[0]=-1;
    for(int i=1;i<M-10;i++){
        if(i&(i-1))dex[i]=dex[i-1];
        else dex[i]=dex[i-1]+1;
    }
}
struct R{
    int raa[M*2][21],rbb[M*2][21];
    int head[M];
    void init(){
        memset(head,-1,sizeof(head));
        memset(rbb,inf,sizeof(inf));
        for(int i=0;i<en;i++){
            int t1=aa[i];
            if(head[t1]==-1) head[t1]=i;
        }
        for(int i=0;i<en;i++){
            rbb[i][0]=bb[i];
            raa[i][0]=aa[i];
        }
        for(int i=1;(1<<i)<=en;i++){
            for(int j=0;j+(1<<i)<en;j++){
                int next=j+(1<<(i-1));
                if(rbb[j][i-1]<=rbb[next][i-1]){
                    rbb[j][i]=rbb[j][i-1];
                    raa[j][i]=raa[j][i-1];
                }
                else{
                    rbb[j][i]=rbb[next][i-1];
                    raa[j][i]=raa[next][i-1];
                }
            }
        }
    }
    int query(int l,int r){
        l=head[l];r=head[r];
        if(l>r) swap(l,r);
        int p2=dex[r-l+1];
        r-=(1<<p2)-1;
        if(rbb[l][p2]<=rbb[r][p2]) return raa[l][p2];
        else return raa[r][p2];

    }
}rmq;
int query[ME];
int main(){
	int n;
	init_dex();
	int id=5;
	while(~scanf("%d",&n)){
		g1.init();
		en=0;
		g1.add(1,2);
		g1.add(1,3);
		g1.add(1,4);
		for(int i=0;i<n;i++){
			scanf("%d",&query[i]);
			g1.add(query[i],id++);
			g1.add(query[i],id++);
		}
		dfs(1,1);
		rmq.init();
		int flag1=2,flag2=3;
		for(int i=0;i<n;i++){
			int id=5+(2*i);
			int t1=lv[flag2]+lv[flag1]-2*lv[rmq.query(flag1,flag2)];
			int t2=lv[flag1]+lv[id]-2*lv[rmq.query(flag1,id)];
			int t3=lv[flag2]+lv[id]-2*lv[rmq.query(flag2,id)];
			int next1=flag1,next2=flag2;
			if(t1<t2){
				t1=t2;
				next1=flag1,next2=id;
			}
			if(t1<t3){
				t1=t3;
				next1=flag2;
				next2=id;
			}
			flag1=next1;flag2=next2;
			printf("%d\n",t1);
		}
	}
	return 0;
}
