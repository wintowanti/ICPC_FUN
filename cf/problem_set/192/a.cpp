#include<cstdio>
#include<cstring>
#define M 100
using namespace std;
char map1[M][M];
int vis[M][M];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++) scanf("%s",map1[i]);
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=0;j<m;j++){
                if(map1[i][j]=='S'){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                for(int j=0;j<m;j++){
                    vis[i][j]=1;
                }
            }
        }
         for(int i=0;i<m;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                if(map1[j][i]=='S'){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                for(int j=0;j<n;j++){
                    vis[j][i]=1;
                }
            }
        }
        int tsum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]) tsum++;
            }
        }
        printf("%d\n",tsum);
    }
    return 0;
}
/*
3 4
SSSS
.SS.
..S.
*/
