#include<cstdio>
#include<cstring>
#define mt(a,b) memset(a,b,sizeof(a))
#define MV 200000
struct G{
	int head[MV],en;
	struct E{
		int u,v,flag,next;
	}e[MV<<2];
	void init(){
		mt(head,-1);
		en=0; 
	}
	void add(int u,int v,int flag){
		e[en].u=u;e[en].v=v;e[en].next=head[u];e[en].flag=flag;head[u]=en++;
	}
}g1;
int ans[MV];
int dfs(int u,int fa,int id){
	int tmax=0;
	for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
		int v=g1.e[i].v;
		if(v==fa) continue;
		int t1=dfs(v,u,i);
		if(t1>tmax) tmax=t1;
	}
	if(fa!=-1){
		if(tmax==1){
			g1.e[id].flag=1;
		}else{
			if(g1.e[id].flag==2){
				tmax=1;
				g1.e[id].flag=1;
				ans[u]=1;
			}
		}
	}
	return tmax;
}
int main()
{
	int n;
	while(~scanf("%d",&n)) {
		g1.init();
		for(int i=0;i<n-1;i++){
			int u,v,flag;scanf("%d%d%d",&u,&v,&flag);
			g1.add(u,v,flag);
			g1.add(v,u,flag);
		}
		mt(ans,0);
		dfs(1,-1,0);
		int num=0;
		for(int i=1;i<=n;i++){
			if(ans[i]==1){
				num++;
			}
		}
		printf("%d\n",num);
		int pflag=0;
		for(int i=1;i<=n;i++){
			if(ans[i]==0) continue;
			if(pflag) printf(" %d",i);
			else {
				pflag=1;printf("%d",i);
			}
		}
		puts("");
	}
	return 0;
}
