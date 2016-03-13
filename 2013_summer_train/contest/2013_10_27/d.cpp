#include<cstdio>
#include<cstring>
#define M 1<<20
using namespace std;
char dp[M][20];
int map1[30][30];
int n;
char dfs(int x,int fa){
    if(dp[x][fa]!='a'){
        return dp[x][fa];
    }
    else{
        if(x==(1<<n)-1&&fa==n-1){
//            puts("*******");
            return dp[x][fa]='c';
        }
        char ans='b';
        for(int i=0;i<n;i++){
            if((x&(1<<i))>0) continue;
            if(map1[fa][i]==0) continue;
            char t1=dfs(x+(1<<i),i);
            if(t1>ans) ans=t1;
        }
        return dp[x][fa]=ans;
    }
}
int main(){
    int cas;
    while(~scanf("%d",&n)){
        memset(map1,0,sizeof(map1));
        int m;scanf("%d",&m);
        for(int i=0;i<m;i++){
            int u,v;scanf("%d%d",&u,&v);
            u-=1;
            v-=1;
            map1[u][v]=1;
            map1[v][u]=1;
        }
        memset(dp,'a',sizeof(dp));
        char ans=dfs(1,0);
        if(ans=='c') puts("1");
        else puts("0");
    }
    return 0;
}
/*
3
2
1 2
2 3
*/
