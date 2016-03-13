#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#define M 30
#define inf 0x3f3f3f3f
using namespace std;
set<string> set1[M][M];
struct G{
    int head[M],end[M],en;
    struct E{
        int u,v,flag;
        friend bool operator <(const E a,const E b){
            if(a.u!=b.u){
                if(a.u<b.u) return 1;return 0;
            }
            else{
                if(a.v<b.v) return 1;return 0;
            }
        }
    }e[M<<10];
    void init(){
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en++].flag=1;
    }
    void work(){
        sort(e,e+en);
        memset(head,-1,sizeof(head));
        memset(end,-inf,sizeof(end));
        for(int i=0;i<en;i++){
//            printf("%c   %c~~~\n",e[i].u+'a',e[i].v+'a');
            int u=e[i].u;
            if(head[u]==-1){
                head[u]=i;
            }
            end[u]=i;
        }
    }
}g1;
int in[M],out[M],fa[M];
int find_fa(int u){
    if(u==fa[u]) return u;
    else return fa[u]=find_fa(fa[u]);
}
int un(int u,int v){
    int fa1=find_fa(u);
    int fa2=find_fa(v);
    fa[fa2]=fa1;
}
int ans[M<<10],ans_en;
void dfs(int u){
    for(int i=g1.end[u];i>=g1.head[u];i--){
        int v=g1.e[i].v;
        if(g1.e[i].flag){
            g1.e[i].flag=0;
            dfs(v);
            ans[ans_en++]=v;
        }
    }
}
void my_pf(){
    int pflag=0;
    string str1;
    for(int i=ans_en-1;i>0;i--){
        int t1=ans[i];
        int t2=ans[i-1];
        str1=*set1[t1][t2].begin();
        set1[t1][t2].erase(str1);
        if(pflag) printf(".");
        else pflag=1;
        cout<<str1;
    }
    puts("");
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            int n;scanf("%d",&n);
            char str[M];
            memset(in,0,sizeof(in));
            memset(out,0,sizeof(out));
            for(int i=0;i<M;i++) for(int j=0;j<M;j++)
            set1[i][j].clear();
            for(int i=0;i<M;i++) fa[i]=i;
            g1.init();
            for(int i=0;i<n;i++){
                scanf("%s",str);
                int l=str[0]-'a';
                int r=str[strlen(str)-1]-'a';
                g1.add(l,r);
                un(l,r);
                set1[l][r].insert(str);
                out[l]++;
                in[r]++;
            }
            int flag1=0;
            int flag2=0;
            int flag3=0;
            for(int i=0;i<M;i++){
                if(in[i]!=out[i]){
                    if(in[i]==out[i]+1){
                        flag1++;
                    }
                    if(in[i]==out[i]-1){
                        flag2++;
                    }
                }
                if(fa[i]==i&&(in[i]||out[i])) flag3++;
            }
//            printf("%d   %d   %d\n",flag1,flag2,flag3);
            int flag=1;
            int start;
            if(flag3==1){
                if(flag1^flag2) flag=0;
                else{
                    if(flag1==0){
                        for(int i=0;i<M;i++){
                            if(in[i]!=0){ start=i;break;}
                        }
                    }
                    else{
                        for(int i=0;i<M;i++){
                            if(in[i]==out[i]-1){
                                start=i;break;
                            }
                        }
                    }
                }
            }else flag=0;
            if(flag){
                ans_en=0;
                g1.work();
//                printf("%d\n",start);
                dfs(start);
                ans[ans_en++]=start;
                my_pf();
            }else{
                puts("***");
            }
        }
    }
    return 0;
}
/*
2
5
aba
aca
aa
ada
aka
*/
