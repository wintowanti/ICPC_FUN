/*
index from 0
first must init_dex a is value arrest
*/
void init_dex(){
    dex[0]=-1;
    for(int i=1;i<M-10;i++){
        if(i&(i-1))dex[i]=dex[i-1];
        else dex[i]=dex[i-1]+1;
    }
}
struct RMQ{
    int tmin[M][20];
    void init(int n){
        memset(tmin,inf,sizeof(tmin));
        for(int i=0;i<n;i++){
            tmin[i][0]=a[i];
        }
        for(int i=1;(1<<i)<=n;i++){
            for(int j=0;(j+(1<<i))-1<n;j++){
                int next=j+(1<<(i-1));
                tmin[j][i]=min(tmin[j][i-1],tmin[next][i-1]);
            }
        }
    }
    int query(int l,int r){
        int t1=r-l+1;
        t1=dex[t1];
        r-=(1<<t1)-1;
        int ans=min(tmin[l][t1],tmin[r][t1]);
        return ans;
    }
}rmq_tmin;
----------------------------------------------
2-dimension
int dex[M];
int ma[M][M];
void init_dex(){
    dex[0]=-1;
    for(int i=1;i<M;i++){
        if(i&(i-1))dex[i]=dex[i-1];
        else dex[i]=dex[i-1]+1;
    }
}
struct RMQ{
    int tmin[M][M][9][9];
    void init(int n){
        memset(tmin,inf,sizeof(tmin));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                tmin[i][j][0][0]=ma[i][j];
            }
        }
        for(int i=0;(1<<i)<=n;i++){
            for(int j=0;(1<<j)<=n;j++){
                if(i==0&&j==0) continue;
                for(int x1=0;x1+(1<<i)-1<n;x1++){
                    for(int y1=0;y1+(1<<j)-1<n;y1++){
                        int nextx=x1+(1<<(i-1));
                        int nexty=y1+(1<<(j-1));
                        if(i==0){
                            tmin[x1][y1][i][j]=min(tmin[x1][y1][i][j-1],tmin[x1][nexty][i][j-1]);
                        }
                        else if(j==0){
                            tmin[x1][y1][i][j]=min(tmin[x1][y1][i-1][j],tmin[nextx][y1][i-1][j]);
                        }
                        else{
                            int t1=min(tmin[x1][y1][i-1][j-1],tmin[x1][nexty][i-1][j-1]);
                            int t2=min(tmin[nextx][y1][i-1][j-1],tmin[nextx][nexty][i-1][j-1]);
                            tmin[x1][y1][i][j]=min(t1,t2);
                        }
                    }
                }
            }
        }
    }
    int query(int x1,int y1,int x2,int y2){
        int p1=x2-x1+1;p1=dex[p1];
        int p2=y2-y1+1;p2=dex[p2];
        x2-=(1<<p1)-1;
        y2-=(1<<p2)-1;
        int t1=min(tmin[x1][y1][p1][p2],tmin[x1][y2][p1][p2]);
        int t2=min(tmin[x2][y1][p1][p2],tmin[x2][y2][p1][p2]);
        return min(t1,t2);
    }
}rmq;
------------------------------------------
rmq in tree
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<1];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int cost[M];
int stk[M],dis[M];
int tmax[M][17],pre[M][17];
void dfs(int u,int leavl){
    dis[u]=leavl;
    stk[leavl]=u;
    tmax[u][0]=cost[u];pre[u][0]=u;
    for(int i=1;(1<<i)<=leavl+1;i++){
        int next=stk[leavl-(1<<(i-1))];
        tmax[u][i]=max(tmax[u][i-1],tmax[next][i-1]);
        pre[u][i]=stk[leavl-(1<<(i))+1];
    }
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        dfs(v,leavl+1);
    }
}
int lowbit(int x){
    return x&(-x);
}
int bit(int x){
    int pa=-1;
    while(x){
        pa++;
        x=x>>1;
    }
    return pa;
}
int query(int u,int k){
    int tr=u;
    int tmax1=0;
    while(k){
        int t1=lowbit(k);
        k-=t1;
        t1=bit(t1);
        tmax1=max(tmax1,tmax[tr][t1]);
        if(k==0) break;
        tr=pre[tr][t1];
        tr=pre[tr][1];
    }
    return tmax1;
}
------------------------------------------
/*
 * mt(tmax,INF);
 * mt(fa,0);
 */
int tmax[MV][LOG];
int fa[MV][LOG];
int dp[MV][LOG];
int value[MV];
int dep[MV];
struct G{
	int ehead[MV],en,enext[ME],eu[ME],ev[ME];
	void init(){
		mt(ehead,-1);
		en=0;
	}
	void add(int u,int v){
		eu[en]=u;ev[en]=v;enext[en]=ehead[u];ehead[u]=en++;
	}
}g1;
int up(int x,int k){
	k<<=1;
	int ans=-INF;
	for(int i=0;i<LOG;i++){
		if(k&(1<<i)){
			ans=max(tmax[x][i],ans);
			x=fa[x][i];
		}
	}
	return ans;
}
void dfs(int x,int fa2){
	fa[x][0]=x; fa[x][1]=fa2;
	tmax[x][0]=value[x]; tmax[x][1]=max(tmax[x][0],tmax[fa2][0]);
	if(x!=0) dep[x]=dep[fa2]+1;
	for(int i=2;i<LOG-1;i++){
		int fa1=fa[x][i-1];
		tmax[x][i]=max(tmax[x][i-1],tmax[fa1][i-1]);
		fa[x][i]=fa[fa1][i-1];
	}
	for(int i=g1.ehead[x];i!=-1;i=g1.enext[i]){
		int v=g1.ev[i];
		if(v==fa2) continue;
		dfs(v,x);
	}
}
