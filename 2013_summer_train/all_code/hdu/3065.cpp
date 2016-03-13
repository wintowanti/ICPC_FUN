#include<cstdio>
#include<cstring>
#define M 2000
#define kind 26
using namespace std;
int vis[M];
char str[M][60];
char str1[2080000];
int is_ok(char p){
    if(p>='A'&&p<='Z') return 1;return 0;
}
struct AC{
    int root,en,my_que[M*100];
    struct E{
        int flag,fail;
        int next[kind];
    }e[M*60*10];
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
            int dex=p[i]-'A';
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
    int query(char *p){
        int ans=0;
        int tr=root;
        memset(vis,0,sizeof(vis));
        for(int i=0;p[i];i++){
            if(!is_ok(p[i])){
                tr=root;
                continue;
            }
            int dex=p[i]-'A';
            while(e[tr].next[dex]==-1&&tr!=root) tr=e[tr].fail;
            tr=e[tr].next[dex];
            if(tr==-1)tr=root;
            int tmp=tr;
            while(tmp!=root){
                vis[e[tmp].flag]++;
                tmp=e[tmp].fail;
            }
        }
        return ans;
    }
}ac;
int main(){
    int n;
    while(~scanf("%d",&n)){
        ac.init();
        for(int i=1;i<=n;i++){
            scanf("%s",str[i]);
            ac.insert(str[i],i);
        }
        scanf("%s",str1);
        ac.build();
        ac.query(str1);
        for(int i=1;i<=n;i++){
            if(vis[i]){
                printf("%s: %d\n",str[i],vis[i]);
            }
        }
    }
    return 0;
}
/*
1
AA
AAAAA]
*/
