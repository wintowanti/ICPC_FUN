#include<cstdio>
#include<cstring>
#define M 108
int sg[M];
int dfs(int x){
    if(sg[x]!=-1)
        return sg[x];
    bool mark[M];
    memset(mark,0,sizeof(mark));
    for(int i=((x+1)/2);i<=x-1;i++){
        int t1=dfs(i);
        mark[t1]=1;
    }
    int i;
    for( i=0;i<100;i++){
        if(mark[i]==0) break;
    }
    return sg[x]=i;
}
int main(){
    memset(sg,-1,sizeof(sg));
    sg[0]=0;sg[1]=0;
    for(int i=1;i<=100;i++){
        printf("%d %d\n",i,dfs(i));
    }
    return 0;
}
