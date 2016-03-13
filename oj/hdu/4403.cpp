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
//int ans;
//int f(char x)
//{
//    return x-'0';
//}
//void dfs(int a,int b,int n,int flag ,int tmp)
//{
////    printf("%d  %d  ~~%d  ~~~ %d ~~~~tmp~%d \n",a,b,n,flag,tmp);
//   // stop
//    int i,j,k,t1;
//    t1=f(s1[n]);
//    if(n==strlen(s1))
//    {
//        b+=tmp;
//        printf("%d   %d  !!!!!!!!!!!!\n",a,b);
//        if(flag)
//        {
//        //    b+=tmp;
////            printf("%d   %d\n",a,b);
//            if(a==b)
//            {
////                printf("%d   %d~~~~~~~~~~~~~~~~~~~~~~~~~~~\n",a,b);
//                ans++;
//            }
//        }
//        return ;
//    }
//    if(flag)
//    {
//        if(flag!=1)
//        dfs(a,b,n+1,flag+1,tmp*10+t1);
//        dfs(a,b+tmp,n+1,flag+1,t1);
//    }
//    else
//    {
//        if(n!=0)
//        dfs(a,b,n+1,flag,tmp*10+t1);
//        dfs(a+tmp,b,n+1,flag,t1);
//        if(n!=0)
//        dfs(a+tmp*10+t1,b,n+1,1,0);
//        dfs(a+tmp+t1,b,n+1,1,0);
//    }
//}
//int main()
//{
//    while(~scanf("%s",s1))
//    {
//        if(strcmp(s1,"END")!=0)
//        {
//            ans=0;
//            dfs(0,0,0,0,0);
//            pff(ans);
//        }
//    }
//   return 0;
//}
