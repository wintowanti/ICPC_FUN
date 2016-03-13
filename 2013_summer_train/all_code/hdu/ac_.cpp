/*
statci AC_Automation M point
must build before point
*/
#include<cstdio>
#include<cstring>
#define M 60000
#defien kind  26
using namespace std;
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
    void insert(char *p){
        int tr=root;
        for(int i=0;p[i];i++){
            int dex=p[i]-'a';
            if(e[tr].next[dex]==-1){
                int t2=en++;flash(t2);
                e[tr].next[dex]=t2;
            }
            tr=e[tr].next[dex];
        }
        e[tr].flag++;
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
        for(int i=0;p[i];i++){
            int dex=p[i]-'a';
            while(e[tr].next[dex]==-1&&tr!=root)tr=e[tr].fail;
            tr=e[tr].next[dex];
            if(tr==-1)tr=root;
            int tmp=tr;
            while(tmp!=root&&e[tmp].flag!=-1){
                ans+=e[tmp].flag;
                e[tmp].flag=-1;
                tmp=e[tmp].fail;
            }
        }
        return ans;
    }
}ac;
char str[M*2];
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            ac.init();
            int n;scanf("%d",&n);
            char tmp[300];
            for(int i=0;i<n;i++){
                scanf("%s",tmp);
                ac.insert(tmp);
            }
            ac.build();
            scanf("%s",str);
            int ans=ac.query(str);
            printf("%d\n",ans);
        }
    }
    return 0;
}
