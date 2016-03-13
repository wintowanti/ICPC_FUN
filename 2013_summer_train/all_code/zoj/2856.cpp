#include<cstdio>
#include<cstring>
#include<iostream>
#define M 302
#define inf 0x3f3f3f3f
using namespace std;
int dex[M];
int ma[M][M];
void init_dex(){
    dex[0]=-1;
    for(int i=1;i<M;i++){
        if(i&(i-1))dex[i]=dex[i-1];
        else dex[i]=dex[i-1]+1;
    }
}
struct RMQ{
    int tmin[M][M][9][9];
    void init(int n){
        memset(tmin,inf,sizeof(tmin));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                tmin[i][j][0][0]=ma[i][j];
            }
        }
        for(int i=0;(1<<i)<=n;i++){
            for(int j=0;(1<<j)<=n;j++){
                if(i==0&&j==0) continue;
                for(int x1=0;x1+(1<<i)-1<n;x1++){
                    for(int y1=0;y1+(1<<j)-1<n;y1++){
                        int nextx=x1+(1<<(i-1));
                        int nexty=y1+(1<<(j-1));
                        if(i==0){
                            tmin[x1][y1][i][j]=min(tmin[x1][y1][i][j-1],tmin[x1][nexty][i][j-1]);
                        }
                        else if(j==0){
                            tmin[x1][y1][i][j]=min(tmin[x1][y1][i-1][j],tmin[nextx][y1][i-1][j]);
                        }
                        else{
                            int t1=min(tmin[x1][y1][i-1][j-1],tmin[x1][nexty][i-1][j-1]);
                            int t2=min(tmin[nextx][y1][i-1][j-1],tmin[nextx][nexty][i-1][j-1]);
                            tmin[x1][y1][i][j]=min(t1,t2);
                        }
                    }
                }
            }
        }
    }
    int query(int x1,int y1,int x2,int y2){
        int p1=x2-x1+1;p1=dex[p1];
        int p2=y2-y1+1;p2=dex[p2];
        x2-=(1<<p1)-1;
        y2-=(1<<p2)-1;
        int t1=min(tmin[x1][y1][p1][p2],tmin[x1][y2][p1][p2]);
        int t2=min(tmin[x2][y1][p1][p2],tmin[x2][y2][p1][p2]);
        return min(t1,t2);
    }
}rmq;
int main(){
    init_dex();
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&ma[i][j]);
            }
        }
        rmq.init(n);
//        printf("%d  !!!\n",rmq.tmin[0][0][1][1]);
        int q;scanf("%d",&q);
        for(int i=0;i<q;i++){
            int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);x1--;y1--;x2--;y2--;
            int ans=rmq.query(x1,y1,x2,y2);
            printf("%d\n",ans);
        }
        }
    }
}
/*
1
2
2 -1
2 3
3
1 1 1 1
1 1 2 2
1 1 2 1
*/
