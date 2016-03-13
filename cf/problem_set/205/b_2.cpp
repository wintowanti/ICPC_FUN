#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#define M 300
using namespace std;
vector<int> vc[2];
int a[M];
int b[M];
int vis[M];
int flag[M];
int f(int x){
    bool vis1[M];
    memset(vis1,0,sizeof(vis1));
    for(int i=0;i<vc[x].size();i++){
        int t1=vc[x][i];
        vis1[t1]=1;
    }
    int tsum=0;
    for(int i=0;i<M;i++){
        if(vis1[i]) tsum++;
    }
    return tsum;
}
int main(){
    int n;while(~scanf("%d",&n)){
        memset(vis,0,sizeof(vis));
        memset(flag,0,sizeof(flag));
        vc[0].clear();
        vc[1].clear();
        for(int i=0;i<2*n;i++){
            scanf("%d",&a[i]);
            vis[a[i]]++;
        }
        int t1=0;
        for(int i=10;i<100;i++){
            if(vis[i]==1){
                flag[i]=t1;
                t1^=1;
            }
        }
        for(int i=10;i<100;i++){
            if(vis[i]>1){
                if(vis[i]%2==1){
                    flag[i]=t1;
                    t1^=1;
                }
            }
        }
        for(int i=0;i<2*n;i++){
            int t1=a[i];
            b[i]=flag[t1];
            flag[t1]^=1;
            vc[b[i]].push_back(t1);
        }
        int tt1=f(0);
        int tt2=f(1);
        int ans=tt1*tt2;
        printf("%d\n",ans);
        for(int i=0;i<2*n;i++){
            if(i)printf(" %d",b[i]+1);
            else printf("%d",b[i]+1);
        }
        puts("");
    }
    return 0;
}
