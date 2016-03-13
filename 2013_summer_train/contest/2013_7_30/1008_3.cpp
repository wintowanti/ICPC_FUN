#include<cstdio>
#include<queue>
#include<cstring>
#define M 1<<17
#define N 20
#define inf 0x3f3f3f3f
using namespace std;
int o[M];
char map1[M][20];
int dp[M];
int en;
char str[M];
int n;
int judge(char *p){
    int i=0;
    int j=strlen(p)-1;
    for( ;j>i;i++,j--){
        if(p[i]!=p[j]) return 0;
    }
    return 1;
}
void dfs(char *p,int flag,int n1){
    if(n1==n){
        if(judge(p)) o[en]=flag,strcpy(map1[en++],p);
    }
    else{
        int t1=strlen(p);
        p[t1]=str[n1];
        p[t1+1]='\0';
        dfs(p,flag+(1<<n1),n1+1);
        p[t1]='\0';
        dfs(p,flag,n1+1);
    }
}
struct E{
    int x,step;
}
queue<E> q1;
int bfs(int sx){
    while(!q1.empty()) q1.pop();
    dp[sx]=0;
    E e1,e2;
    e1.x=sx;
    e1.step=0;
    while(!q1.empty()){
        e1=q1.front();q1.pop();
        if(e1.x==0) return e1.step;
        for(int i=0;i<en;i++){
            int t1=e[i];
            if(t1&e1.x==t1){
                int t2=e1.x^t1;
                if(dp[t2]>e1.step+1){
                    dp[t2]=e1.step+1;
                    e2.x=t2;
                    e2.step=e1.step+1;
                    q1.push(e2);
                }
            }
        }
    }
}
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            en=0;
            scanf("%s",str);
            n=strlen(str);
            char tmp[N];
            tmp[0]='\0';
            dfs(tmp,0,0);
            for(int i=0;i<en;i++){
                printf("%d   %s    ~~",o[i],map1[i]);
            }
            puts("");
            memset(dp,inf,sizeof(dp));
            int ans=bfs((1<<n)-1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
