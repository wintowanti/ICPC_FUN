//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//#include<stdlib.h>
//#include<iostream>
//#include<functional>
//#include<queue>
//#include<stack>
//#include<vector>
//#include<algorithm>
//#define M 100
//#define pf printf("~~~~~~~~~~~~~\n");
//#define pn printf("\n");
//#define pff(x) printf("%d\n",x);
//#define inf 0x3f3f3f3f
//#define stop system("pause");
//#define ll long long
//using namespace std;
//int flag[M];
//bool vis[M];
//struct E
//{
//    int u,v,next;
//}e[M*4];
//int head[M],g,n;
//int add(int x,int y)
//{
//    e[g].u=x;
//    e[g].v=y;
//    e[g].next=head[x];
//    head[x]=g++;
//    return 0;
//}
//char  str[100];
//int main()
//{
//    int i,j,k;
//    while(~scanf("%d",&n)&&n)
//    {
//        memset(head,-1,sizeof(head));
//        g=0;
//        for(i=1;i<=n;i++)
//        {
//            scanf("%s",str);
//            for(j=2;str[j];j++)
//            {
//                int t1=str[j]-'A'+1;
//                add(i,t1);
//            }
//        }
//
//        memset(flag,0,sizeof(flag));
//        for(i=1;i<=n;i++)
//        {
//            memset(vis,0,sizeof(vis));
//            for(j=head[i];j!=-1;j=e[j].next)
//            {
//                int t1=e[j].v;
////                printf("%d   ",t1);
//                if(flag[t1])
//                {
//                    vis[flag[t1]]=1;
////                    printf("!!!%d  !!",flag[t1]);
//                }
//            }
////            pn
//            for(j=1;j<=30;j++)
//            {
//                if(vis[j]==0)
//                {
//                    flag[i]=j;
//                    break;
//                }
//            }
//        }
//        int tmax=1;
//        for(i=1;i<=n;i++)
//        {
//            if(flag[i]>tmax) tmax=flag[i];
//        }
//        if(tmax>1) printf("%d channels needed.\n",tmax);
//        else puts("1 channel needed.");
////        printf("%d\n",tmax);
//    }
//   return 0;
//}
