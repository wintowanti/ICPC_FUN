#include<cstdio>
#include<cstring>
#define M 201
#define kind 2
#define mod 1000000007
using namespace std;
int n,m;
int dp[M][101][M+1][4];
int dp1[M];
struct AC{
    int root,en,my_que[M];
    struct E{
        int flag,fail;
        int next[kind];
    }e[M];
    void flash(int id){
        e[id].flag=0;
        memset(e[id].next,-1,sizeof(e[id].next));
    }
    void init(){
        root=0;en=1;
        flash(root);
        e[root].fail=-1;
    }
    void insert(char *p,int id){
        int tr=root;
        for(int i=0;p[i];i++){
            int dex=p[i]-'a';
            if(e[tr].next[dex]==-1){
                int t2=en++;flash(t2);
                e[tr].next[dex]=t2;
            }
            tr=e[tr].next[dex];
        }
        e[tr].flag=id;
    }
    void build(){
        int hp=0,tp=-1;
        my_que[++tp]=root;
        while(tp>=hp){
            int now=my_que[hp++];
            for(int i=0;i<kind;i++){
                if(e[now].next[i]!=-1){
                    int nxt=e[now].next[i];
                    int dex=i;
                    if(now==root){
                        e[nxt].fail=root;
                    }
                    else{
                        int tmp=e[now].fail;
                        while(tmp!=-1&&e[tmp].next[dex]==-1) tmp=e[tmp].fail;
                        if(tmp==-1) tmp=root;
                        else tmp=e[tmp].next[dex];
                        e[nxt].fail=tmp;
                    }
                    my_que[++tp]=nxt;
                }
            }
        }
    }
    int dfs(int tmp){
        int ans=0;
        if(dp1[tmp]!=-1){
            return dp1[tmp];
        }
        ans|=e[tmp].flag;
        ans|=dfs(e[tmp].fail);
        return dp1[tmp]=ans;
    }
    int query(){
        for(int i=0;i<n+m+1;i++){
            for(int j=0;j<n+1;j++){
                for(int k=0;k<=n+m+1;k++){
                    for(int k1=0;k1<4;k1++){
                        dp[i][j][k][k1]=0;
                    }
                }
            }
        }
        dp[0][0][0][0]=1;
        memset(dp1,-1,sizeof(dp1));
        dp1[0]=0;
        for(int i=0;i<n+m;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n+m+1;k++){
                    for(int k1=0;k1<4;k1++){
                        if(dp[i][j][k][k1]==0) continue;
                        int t1=i-j;
                        if(j<n){
                            int tr=k;
                            int dex=0;
                            while(e[tr].next[dex]==-1&&tr!=root) tr=e[tr].fail;
                            tr=e[tr].next[dex];
                            if(tr==-1) tr=root;
                            int tmp=tr;
                            int mark=k1|dfs(tmp);
                            dp[i+1][j+1][tr][mark]+=dp[i][j][k][k1];
                            dp[i+1][j+1][tr][mark]%=mod;
                        }
                        if(t1<m){
                            int tr=k;
                            int dex=1;
                            while(e[tr].next[dex]==-1&&tr!=root) tr=e[tr].fail;
                            tr=e[tr].next[dex];
                            if(tr==-1) tr=root;
                            int tmp=tr;
                            int mark=k1|dfs(tmp);
                            dp[i+1][j][tr][mark]+=dp[i][j][k][k1];
                            dp[i+1][j][tr][mark]%=mod;
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<=n+m+1;i++){
            ans+=dp[n+m][n][i][3];
            ans%=mod;
        }
        return ans;
    }
}ac;
char str[M*2];
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            ac.init();
            scanf("%d%d",&n,&m);
            scanf("%s",str);
            for(int i=0;str[i];i++){
                if(str[i]=='R') str[i]='a';
                else str[i]='b';
            }
            ac.insert(str,1);
            scanf("%s",str);
            for(int i=0;str[i];i++){
                if(str[i]=='R') str[i]='a';
                else str[i]='b';
            }
            ac.insert(str,2);
            ac.build();
            int ans=ac.query();
            printf("%d\n",ans);
        }
    }
    return 0;
}
