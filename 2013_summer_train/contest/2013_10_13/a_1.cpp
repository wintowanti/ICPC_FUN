#include<stdio.h>
#include<string.h>
#define M 1200
char str1[M];
char str2[M];
int index_1[M];
int dp[M][M];
int is1(char p){
    if(p>='a'&&p<='z') return 1;
    if(p>='A'&&p<='Z') return 1;
    return 0;
}
char change1(char p){
    if(p>='A'&&p<='Z') return p-'A'+'a';
    return p;
}
int dfs(int x,int y){
    if(x>y){
        return 0;
    }
    if(x==y){
        return dp[x][y]=0;
    }
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    int t1=0;
    if(str2[x]!=str2[y]){
        t1=1+dfs(x+1,y-1);
    }
    else{
        t1=dfs(x+1,y-1);
    }
    return dp[x][y]=t1;
}
int main(){
    int n;
    int cas=1;
    char tt;
    int i;
    while(~scanf("%d%c",&n,&tt)){
//        getchar();
        gets(str1);
        int en=0;
        for(int i=0;str1[i];i++){
            if(is1(str1[i])){
                str2[en]=change1(str1[i]);
                index_1[en++]=i;
            }
        }
        str2[en]='\0';
//        puts(str2);
//        printf("%d\n",en);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<en;i++){
            for(int j=i;j<en;j++){
                int t1=dfs(i,j);
//                printf("%d   %d   %d\n",i,j,t1);
            }
        }
        int tmax=0;
        int flag=0;
        for(int i=0;i<en;i++){
            for(int j=i;j<en;j++){
                int t1=dfs(i,j);
                if(t1<=n){
                    int t2=index_1[j]-index_1[i]+1;
                    if(t2>tmax){
                        tmax=t2;
                        flag=index_1[i];
                    }
                }
            }
        }
        printf("Case %d: %d %d\n",cas++,tmax,flag+1);
//        getchar();
    }
    return 0;
}
/*
1
Wow, it is1 a Race cat!
0
abcdefg
0
Kitty: Madam, I'm adam.
*/
