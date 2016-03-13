#include<cstdio>
#include<cstring>
#define M 1040000
#define N 26
bool  vis[600];
struct AC{
    int en;
    int my_que[M<<2];
    int sp,tp,root;
    void init(){
        en=1;root=0;
        flash(e[root]);
    }
    struct E{
        int next[N];
        int fail,flag;
    }e[M];
    void flash(E &e){
        memset(e.next,-1,sizeof(e.next));
        e.fail=-1;
        e.flag=0;
    }
    void insert(char *p,int id){
        int tr=root;
        for(int i=0;p[i];i++){
            int dex=p[i]-'a';
            if(e[tr].next[dex]==-1){
                int t2=en++;
                flash(e[t2]);
                e[tr].next[dex]=t2;
            }
            tr=e[tr].next[dex];
        }
        e[tr].flag=id;
    }
   void bfs(){
        sp=0,tp=-1;
        my_que[++tp]=root;
        while(sp<=tp){
            int pu=my_que[sp++];
            for(int i=0;i<N;i++){
                if(e[pu].next[i]!=-1){
                    if(pu==root){
                       e[e[pu].next[i]].fail=root;
                    }
                    else{
                        int pv=e[pu].fail;
                        while(pv!=-1){
                            if(e[pv].next[i]!=-1){
                                e[e[pu].next[i]].fail=e[pv].next[i];
                                break;
                            }
                            pv=e[pv].fail;
                        }
                        if(pv==-1){
                            e[e[pu].next[i]].fail=root;
                        }
                    }
                    my_que[++tp]=e[pu].next[i];
                }
            }
        }
    }
    int query(char *p){
        int tr=root;
        int ans=0;
        for(int i=0;p[i];i++){
            int t1=p[i]-'a';
            while(e[tr].next[t1]==-1&&tr!=root) tr=e[tr].fail;
            tr=e[tr].next[t1];
            if(tr==-1) tr=root;
            int tmp=tr;
            while(tmp!=root&&e[tmp].flag!=-1){
                vis[e[tmp].flag]=1;
                tmp=e[tmp].fail;
            }
        }
        return ans;
    }
}ac;
char str1[1000006];
int main(){
    int n;
    while(~scanf("%d",&n)){
        ac.init();
        for(int i=1;i<=n;i++){
            char str[300];scanf("%s",str);
            ac.insert(str,i);
        }
        ac.bfs();
        int m;scanf("%d",&m);
        int ans=0;
        for(int i=1;i<=m;i++){
            memset(vis,0,sizeof(vis));
            scanf("%s",str1);
            ac.query(str1);
            int pflag=0;
            for(int j=1;j<600;j++){
                if(vis[j]==1){
                    if(pflag) printf(" %d",j);
                    else{
                        pflag=1;
                        printf("web %d: %d",i,j);
                    }
                }
            }
            if(pflag) puts(""),ans++;
        }
        printf("total: %d\n",ans);
    }
    return 0;
}
/*
4
aaa
bbb
ccc
cccd
2
aaabbbcccd
bbaabaccbcd
*/
