//#include<stdio.h>
//#include<string.h>
//#define M 100
//using namespace std;
//bool vis[M];
//bool visp[M];
//bool visn[M];
//int g,ans[M];
//void dfs(int x,int y)
//{
//    if(x==8)
//    {
//        ans[g++]=y;
//    }
//    for(int i=1;i<=8;i++)
//    {
//        int x1=x+1;
//        int y1=i;
//        int t1=y1-x1+10;
//        int t2=y1+x1;
//        if(vis[i]&&visp[t1]&&visn[t2])
//        {
//            vis[i]=0;
//            visp[t1]=0;
//            visn[t2]=0;
//            dfs(x+1,y*10+i);
//            vis[i]=1;
//            visp[t1]=1;
//            visn[t2]=1;
//        }
//    }
//}
//int main()
//{
//    int n,i,j,k;
//    memset(vis,1,sizeof(vis));
//    memset(visp,1,sizeof(visp));
//    memset(visn,1,sizeof(visn));
//    g=1;
//    dfs(0,0);
//    while(~scanf("%d",&n))
//    {
//        while(n--)
//        {
//            scanf("%d",&i);
//            printf("%d\n",ans[i]);
//        }
//    }
//   return 0;
//}
