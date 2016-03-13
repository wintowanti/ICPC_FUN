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
//char s1[M];
//char s2[M];
//bool vis[M];
//int n,m;
//int flag1;
//void rv(char *p)
//{
//    int i,j;
//    char tmp;
//    for(i=0,j=strlen(p)-1;j>i;j--,i++)
//    {
//        tmp=p[i];
//        p[i]=p[j];
//        p[j]=tmp;
//    }
//    return ;
//}
//int cmp(char x,char y)
//{
//    if(x>y)
//    return 1;
//    return 0;
//}
//void dfs(int x,char *p)
//{
//    int i,j,k;
//    if(flag1)
//    {
//        return ;
//    }
//    if(x==5)
//    {
//        int a[10];
//    //    puts(p);
//        for(i=0;i<5;i++)
//        {
//            a[i]=p[i]-'A'+1;
//        }
//        if(a[0]-a[1]*a[1]+a[2]*a[2]*a[2]-a[3]*a[3]*a[3]*a[3]+a[4]*a[4]*a[4]*a[4]*a[4]==n)
//        {
//            flag1=1;
//            puts(p);
//        }
//    }
//    else
//    {
//        for(i=0;i<m;i++)
//        {
//            if(vis[i])
//            {
//                vis[i]=0;
//                p[x]=s1[i];
//                p[x+1]='\0';
//                dfs(x+1,p);
//                vis[i]=1;
//                p[x]='\0';
//            }
//            if(flag1)
//            return ;
//        }
//    }
//}
//int main()
//{
//    while(~scanf("%d%s",&n,s1))
//    {
//        if(n==0&&strcmp(s1,"END")==0)
//        {
//            break;
//        }
//        else
//        {
//            memset(vis,1,sizeof(vis));
//      //      rv(s1);
//            m=strlen(s1);
//            sort(s1,s1+m,cmp);
//            flag1=0;
//            s2[0]='\0';
//          //  puts(s1);
//            dfs(0,s2);
//            if(flag1==0)
//            {
//                puts("no solution");
//            }
//        }
//    }
//   return 0;
//}
