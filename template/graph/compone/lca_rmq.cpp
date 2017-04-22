#define M 3000
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
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int lv[M];
int aa[M],bb[M],en;
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
    int raa[M][20],rbb[M][20];
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
