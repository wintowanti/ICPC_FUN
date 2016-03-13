#include<cstdio>
#include<cstring>
#define M 120000
#define kind 127
using namespace std;
struct AC{
    int root,en,my_que[M];
    bool vis[700];
    struct E{
        int flag,fail,vv;
        int next[kind];
    }e[M];
    void flash(int id){
        e[id].flag=0;
        e[id].vv=0;
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
            int dex=p[i];
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
    int query(char *p,int id){
        memset(vis,0,sizeof(vis));
        int ans=0;
        int tr=root;
        for(int i=0;p[i];i++){
            int dex=p[i];
            while(e[tr].next[dex]==-1&&tr!=root)tr=e[tr].fail;
            tr=e[tr].next[dex];
            if(tr==-1)tr=root;
            int tmp=tr;
            while(tmp!=root){
                vis[e[tmp].flag]=1;
                ans+=e[tmp].flag;
                tmp=e[tmp].fail;
                e[tmp].vv=-id;
            }
        }
        return ans;
    }
}ac;
char str[M];
int main(){
    int n;while(~scanf("%d",&n)){
    {
            ac.init();
//            int n;scanf("%d",&n);
            char tmp[300];
            for(int i=1;i<=n;i++){
                scanf("%s",tmp);
                ac.insert(tmp,i);
            }
            ac.build();
            int m;scanf("%d",&m);
            int ans=0;
            for(int i=1;i<=m;i++){
                scanf("%s",str);
                ac.query(str,i);
                int flag=0;
                for(int j=1;j<=n;j++){
                    if(ac.vis[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag){
                    ans++;
                    printf("web %d:",i);
                    for(int i=1;i<=n;i++){
                        if(ac.vis[i]){
                            printf(" %d",i);
                        }
                    }
                    puts("");
                }
            }
            printf("total: %d\n",ans);
        }
    }
    return 0;
}
/*
3
aaa
bbb
cc
2
aaabbbccc
bbaacc
*/
