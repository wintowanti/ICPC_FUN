#include <iostream>
#include<stdio.h>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
const int maxn=100;
int g[maxn][maxn],lx[maxn],ly[maxn];
int match[maxn];
bool visx[maxn],visy[maxn];
int slack[maxn];
int  n;

bool DFS(int cur)//匈牙利深度搜索算法
{
   visx[cur]=true;
   for(int y=1;y<=n;y++)
   {
    if(visy[y]) continue;
    int t=lx[cur]+ly[y]-g[cur][y];
    if(t==0)
    {
      visy[y]=true;
      if(match[y]==-1||DFS(match[y]))
      {
        match[y]=cur;
        return true;
      }
    }
    else
    slack[y] = min(slack[y],t);  //不在相等子图
   }
return false;
}

int KM_Maxmatch()
{
memset(match,-1,sizeof(match)); //初始化顶标
memset(ly,0,sizeof(ly));//ly[i]为0

for(int i=1;i<=n;i++)
{
lx[i]=-INT_MAX;
for(int j=1;j<=n;j++)//lx[i]为权值最大的边
    {
     if(g[i][j]>lx[i])
     lx[i]=g[i][j];
    }
}
for(int k=1;k<=n;k++) //对n个点匹配
{
for(int m=1;m<=n;m++) slack[m]=INT_MAX;
 while(true)
 {
   memset(visx,false,sizeof(visx));
   memset(visy,false,sizeof(visy));
   if(DFS(k))  break; //匹配成功

  int d=INT_MAX;//匹配失败，找最小值
  for(int i=1;i<=n;i++)//x在交错树中
  {
   if(!visy[i]&&d>slack[i])
    d=slack[i];
  }
  for(int i=1;i<=n;i++)//y在交错树外
  {
   if(visx[i])
    lx[i]-=d;
  }
  for(int i=1;i<=n;i++)//更新顶标
  {
    if(visy[i]) visy[i]+=d;
    else  slack[i]-=d;
  }
 }
}

int result=0; //权值相加
for(int i=1;i<=n;i++)
{
 if(match[i]>-1)
 result+=g[match[i]][i];
}
return result;
}
int num[20000];
int main()
{
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            int n1,m,k;scanf("%d%d%d",&n1,&k,&m);
            char str[10];
            for(int i=0;i<n1;i++){
                scanf("%s",str);int t1=str[i]-'A'+1;
                num[i]=t1;
            }
            for(int i=0;i<m;i++){
                memset(g,0,sizeof(g));
                for(int j=0;j<n1;j++){
                    scanf("%s",str);
                    int t1=str[0]-'A'+1;
                    g[num[i]][t1]++;
                }
                n=30;
                int ans=KM_Maxmatch();
                printf("%d",ans);
            }
        }
    }
return 0;
}
