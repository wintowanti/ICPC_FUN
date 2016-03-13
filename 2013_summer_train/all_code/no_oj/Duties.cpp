#include<stdio.h>
#include<cstring>
#define M 150
using namespace std;
bool map1[M][M];
int flag[M];
int two[M*M][2];
int main(){
    int n,k,m;
    while(~scanf("%d%d%d",&n,&k,&m)){
        for(int i=1;i<=n;i++){
            flag[i]=((i-1)%k)+1;
        }
        memset(map1,1,sizeof(map1));
        int need=m;
        int en=0;
        if(n&1){
            need-=n/2;
            for(int i=1;i<n;i+=2){
              two[en][0]=i;two[en++][1]=i+1;
              map1[i][i+1]=0;map1[i+1][i]=0;
            }
            if(flag[n]!=flag[1]){
                two[en][0]=1;two[en++][1]=n;
                map1[1][n]=map1[n][1]=0;
            }else{
                two[en][0]=2;two[en++][1]=n;
                map1[2][n]=map1[n][2]=0;
            }
        }else{
            need-=n/2;
            for(int i=1;i<=n;i+=2){
              two[en][0]=i;two[en++][1]=i+1;
              map1[i][i+1]=0;map1[i+1][i]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(map1[i][j]&&flag[i]!=flag[j]){
                    two[en][0]=i;two[en++][1]=j;
                    map1[i][j]=map1[j][i]=0;
                    if(en==m){
                      ;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d\n",flag[i]);
        }
        for(int i=0;i<m;i++){
            printf("%d %d\n",two[i][0],two[i][1]);
        }
    }
    return 0;
}
