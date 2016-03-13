#include<cstdio>
#include<cstring>
#define M 2000
#define N 1080000
char str1[M];
char  str2[30];
int vis[N];
int main(){
    int k;
    while(~scanf("%s%s%d",str1,str2,&k)){
        int n=strlen(str1);
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<n;i++){
            int hash=0;
            int flag=0;
            for(int j=i;j<n;j++){
                int t1=str1[j]-'a';
                if(str2[t1]=='1') flag++;
//                printf("%d   %c %d!!!\n",t1,str2[t1],flag);
                if(flag>k) break;
                hash=str1[j]+(hash<<6)+(hash<<16)-hash;
                hash=(hash &0x7FFFFFFF)%N;
                if(vis[hash]==0){
                    vis[hash]=1;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
bbbbbb
01000000000000000000000000
1
*/
