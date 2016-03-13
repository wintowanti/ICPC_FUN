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
//int n,m;
//char str[M];
//int a[M],g;
//int flag1;
//int flag2;
//void dfs1(int x,int y,int z)
//{
////    printf("%d    %d   %d  \n",x,y,z);
//    if(y>n)
//    return ;
//    if(z>n)
//    return ;
//    if(x==m)
//    {
//        if(y>flag1)
//        {
//            flag1=y;
//            flag2=1;
//        }
//        else if(y==flag1)
//        {
//            flag2++;
//        }
//        return ;
//    }
//    int t1=str[x]-'0';
//    if(x!=m-1)
//    {
//        dfs1(x+1,y,z*10+t1);
//        dfs1(x+1,y+z*10+t1,0);
//    }
//    else
//    {
//
//        dfs1(x+1,y+z*10+t1,0);
//    }
//}
//void dfs2(int x,int y,int z)
//{
////    printf("%d    %d   %d  \n",x,y,z);
//    if(y>n)
//    return ;
//    if(z>n)
//    return ;
//    if(flag2)
//    return ;
//    if(x==m)
//    {
//         if(y==flag1)
//        {
//            flag2=1;
//            return ;
//        }
//        return ;
//    }
//    int t1=str[x]-'0';
//    if(x!=m-1)
//    {
//        dfs2(x+1,y,z*10+t1);
//        if(flag2) return ;
//        a[g++]=z*10+t1;
//        dfs2(x+1,y+z*10+t1,0);
//        if(flag2)
//        return ;
//        else
//        {
//            g--;
//        }
//    }
//    else
//    {
//        a[g++]=z*10+t1;
//        dfs2(x+1,y+z*10+t1,0);
//        if(flag2)
//        return ;
//        else
//        {
//            g--;
//        }
//    }
//}
//int main()
//{
//    while(~scanf("%d%s",&n,str))
//    {
//        if(n==0&&strcmp(str,"0")==0)
//            break;
//        flag1=-1;
//        flag2=0;
//        m=strlen(str);
//        dfs1(0,0,0);
//   //     printf("%d   %d   \n",flag1,flag2);
//        if(flag1==-1)
//        {
//            puts("error");
//        }
//        else
//        {
//            if(flag2>1)
//            {
//                puts("rejected");
//            }
//            else
//            {
//                g=0;
//                flag2=0;
//                dfs2(0,0,0);
//               // pf
//                printf("%d",flag1);
//                for(int i=0;i<g;i++)
//                {
//                    printf(" %d",a[i]);
//                }
//                pn
//            }
//        }
//    }
//   return 0;
//}
