//#include<stdio.h>
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
//#define M 50
//#define pf printf("~~~~~~~~~~~~~\n");
//#define pn printf("\n");
//#define pff(x) printf("%d\n",x);
//#define inf 0x3f3f3f3f
//#define stop system("pause");
//#define ll long long
//using namespace std;
//int coutnum[M];
//int flag1;
//int ans[M],tans;
//char str1[M];
//queue<int >q1;
//int f1(char p1,char p2)
//{
//    int t1,t2;
//    t1=p1-'0';
//    if(p2=='m')
//        t2=0;
//    if(p2=='p')
//        t2=9;
//    if(p2=='s')
//        t2=18;
//    if(p2=='z')
//        t2=27;
//    t1=t2+t1;
//    return t1;
//}
//void mypf(int x)
//{
//    if(x<=9)
//    {
//        printf("%dm",x);
//    }
//    else if(x<=18)
//    {
//        printf("%dp",x-9);
//    }
//    else if(x<=27)
//    {
//        printf("%ds",x-18);
//    }
//    else
//    {
//        printf("%dz",x-27);
//    }
//    return ;
//}
//int f2(int x)
//{
//    if(x<=9)
//        return x;
//    if(x<=18)
//        return x-9;
//    if(x<=27)
//        return x-18;
//}
//void dfs(int x)
//{
//    int i,j,k;
//    if(flag1)
//        return ;
//    if(x==5)
//    {
//        flag1=1;
//        return ;
//    }
//    if(x==0)
//    {
//        for(i=1;i<=34;i++)
//        {
//            if(coutnum[i]>=2)
//            {
//                coutnum[i]=coutnum[i]-2;
//                dfs(x+1);
//                coutnum[i]=coutnum[i]+2;
//                if(flag1)
//                    return ;
//            }
//        }
//    }
//    else
//    {
//        for(i=1;i<=34;i++)
//        {
//            if(i<=27&&coutnum[i]>=0)
//            {
//                int t1=f2(i);
//                if(t1<8)
//                {
//                    if(coutnum[i]&&coutnum[i+1]&&coutnum[i+2])
//                    {
//                        coutnum[i]--;
//                        coutnum[i+1]--;
//                        coutnum[i+2]--;
//                        dfs(x+1);
//                        coutnum[i]++;
//                        coutnum[i+1]++;
//                        coutnum[i+2]++;
//                        if(flag1)
//                            return ;
//                    }
//                }
//            }
//        }
//        for(i=1;i<=34;i++)
//        {
//            if(coutnum[i]>=3)
//            {
//                coutnum[i]=coutnum[i]-3;
//                dfs(x+1);
//                coutnum[i]=coutnum[i]+3;
//                if(flag1)
//                    return ;
//            }
//        }
//    }
//}
//int main()
//{
//    int i,j,k;
//    while(~scanf("%s",str1))
//    {
//        memset(coutnum,0,sizeof(coutnum));
//        for(i=0;str1[i];i=i+2)
//        {
//            int t1=f1(str1[i],str1[i+1]);
////            printf("%d\n",t1);
//            coutnum[t1]++;
//        }
//        tans=0;
//     //   pf
//        for(i=1;i<=34;i++)
//        {
//            if(coutnum[i]<4)
//            {
//                coutnum[i]++;
//                flag1=0;
//                dfs(0);
//                coutnum[i]--;
//                if(flag1){
////                    printf("%d~~\n",i);
//                    tans++;
//                    q1.push(i);
//                }
//            }
//        }
//        printf("%d",tans);
//        if(tans)
//        {
//            printf(" ");
//            while(!q1.empty())
//            {
//                int t1=q1.front();
//                q1.pop();
//                mypf(t1);
//            }
//        }
//        printf("\n");
//    }
//    return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
