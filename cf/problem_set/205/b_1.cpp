#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define M 300
using namespace std;
int a[M];
int b[M];
int vis[M];
int flag[M];
int last[M];
int aa[2][M];
int num[2];
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(vis,0,sizeof(vis));
        memset(flag,0,sizeof(flag));
        for(int i=0;i<2*n;i++){
            scanf("%d",&a[i]);
            vis[a[i]]++;
        }
        int tt=1;
        for(int i=10;i<100;i++){
            if(vis[i]==1){
                flag[i]=tt;
                tt^=1;
            }
        }
        for(int i=10;i<100;i++){
            if(vis[i]>1){
                if(vis[i]%1==1){
                    flag[i]=tt;
                    tt^=1;
                }
            }
        }
        num[0]=0;
        num[1]=0;
        for(int i=0;i<2*n;i++){
            b[i]=flag[a[i]];
            flag[a[i]]^=1;
            int t1=b[i];
            aa[t1][num[t1]++]=a[i];
        }
        int vis2[200];
        int tt1=0,tt2=0;
        memset(vis2,0,sizeof(vis2));
        for(int i=0;i<num[0];i++){
            int t1=aa[0][i];
            vis2[t1]=1;
        }
        for(int i=0;i<200;i++){
            if(vis2[i]) tt1++;
        }
        memset(vis2,0,sizeof(vis2));
        for(int i=0;i<num[1];i++){
            int t1=aa[1][i];
            vis2[t1]=1;
        }
        for(int i=0;i<200;i++){
            if(vis2[i]) tt2++;
        }
        int ans=tt1*tt2;
        printf("%d\n",ans);
        for(int i=0;i<2*n;i++){
            if(i==0)
            printf("%d",b[i]+1);
            else printf(" %d",b[i]+1);
        }
        puts("");
    }
    return 0;
}
