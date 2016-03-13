//#include<stdio.h>
//#include<math.h>
//#include<string.h>
//#include<stdlib.h>
//#include<iostream>
//#include<functional>
//#include<queue>
//#include<map>
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
//map<string,int>map1;
//char str[M];
//char str2[M];
//int n;
//bool vis[M];
//int f(char x)
//{
//    if(x>='A'&&x<='Z')
//    return (x-'A')*2;
//    else
//    return (x-'a')*2+1;
//}
//int cmp(char x,char y)
//{
//    int t1,t2;
//    t1=f(x);
//    t2=f(y);
//    if(t1<t2)
//    return 1;
//    return 0;
//
//}
//void dfs(int x,char *p)
//{
//    if(x==n)
//    {
//        puts(p);
////        if(map1[p]==0)
////        {
////            map1[p]=1;
////            puts(p);
////        }
//        return ;
//    }
//    int flag=-1;
//    for(int i=0;i<n;i++)
//    {
//        if(vis[i])
//        {
//            if(flag!=-1&&(flag==str[i]-'A'))
//                continue;
//            flag=str[i]-'A';
//            vis[i]=0;
//            p[x]=str[i];
//            p[x+1]='\0';
//            dfs(x+1,p);
//            vis[i]=1;
//        }
//    }
//}
//int main()
//{
//    int i,j,k,t;
//    while(~scanf("%d",&t))
//    {
//        while(t--)
//        {
//            map1.clear();
//            scanf("%s",str);
//            n=strlen(str);
//            sort(str,str+n,cmp);
//          //  puts(str);
//            memset(vis,1,sizeof(vis));
//            dfs(0,str2);
//        }
//    }
//   return 0;
//}
