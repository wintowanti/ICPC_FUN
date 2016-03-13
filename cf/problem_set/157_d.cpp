#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<stack>
#define M 13
#define N 1000000007
#define ll long long
#define pf printf("~~~~~~~~~~~~~~~~!!!~~~~~~~~~~~~~\n");
using namespace std;
int dp[M][13];
int dp1[13];
int a[M];
ll ans[M];
ll dp2[M];
int vis[M];
ll dfs_ans;
ll c(int x,int y)
{
    int i,j,k;
    if(x>y)
    {
        return 0;
    }
    ll sum=1;
    for(i=0;i<x;i++)
    {
        sum=(sum*(y-i))%N;
    }
    int sum1=1;
    for(i=1;i<=x;i++)
    {
        sum1=sum1*i;
    }
    sum=sum/sum1;
  //  printf("%I64d$$$\n",sum);
    return sum;
}
void dfs(int x,int y,int z)
{
    int i,j,k;
    //printf("%d   %d  %d\n",x,y,z);
    if((6-x)*y>z-1)
    {
        return ;
    }
    if(z<0)
    {
        return ;
    }
    if(x==5)
    {
        if(z-1>=y)
        {
            vis[z-1]++;
            ll t1=1;
            for(i=0;i<M;i++)
            {
                if(vis[i]!=0)
                {
       //             printf("%d   %d  ~~~~\n",vis[i],dp1[i]);
                    t1=(t1*c(vis[i],dp1[i]))%N;
                }

            }
            dfs_ans=(dfs_ans+t1)%N;
//            pf
     //       printf("******%I64d\n",t1);
        }
    }
    else
    {
        for(i=y;i<=(z/(6-x)+1+1) ;i++)
        {
            vis[i]++;
            dfs(x+1,i,z-i);
            vis[i]--;
        }
    }
}
int main()
{
    int i,j,k,m,n,len;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(i=1;i<M;i++)
    {
        for(j=0;j<M;j++)
        {
           if(j==0)
           {
               dp[i][j]=dp[i-1][j]*8;
           }
           else
           {
               dp[i][j]=dp[i-1][j]*8+dp[i-1][j-1]*2;
           }
        }
    }
//    for(i=0;i<M;i++)
//    {
//        for(j=0;j<M-1;j++)
//        {
//            printf("%d  ",dp[i][j]);
//        }
//        printf("\n");
//    }
    while(~scanf("%d",&n))
    {
        memset(dp1,0,sizeof(dp1));
        int t1=n+1;
        int i=0;
        while(t1)
        {
            a[i++]=t1%10;
            t1=t1/10;
        }
        len=i;
//        for(i=0;i<len;i++)
//        {
//            printf("%d  ",a[i]);
//        }
//        printf("\n");
        int flag=0;
        for(i=len-1;i>=0;i--)
        {
            for(j=0;j<a[i];j++)
            {
                for(k=flag;k<M-1;k++)
                {
//                    if(flag==2)
//                    {
//                        printf("%d~~~~~~~~!!!!!!!~~~~~&&&",flag);
//                    }
                    if(j==4||j==7)
                    {
                        dp1[k]+=dp[i][k-1-flag];
                    }
                    else
                    {

                        dp1[k]+=dp[i][k-flag];
//                        printf("%d  ~~ \n",dp1[k]);
                    }
                }
            }
            if(a[i]==4||a[i]==7)
            {
                flag++;
            }
        }
        int tans=0;
        dp1[0]-=1;
        for(i=0;i<M;i++)
        {
//            printf("%d  ",dp1[i]);
            tans+=dp1[i];
        }
   //     printf("~~~~~~~~~~~~%d\n",tans);
        int tmax;
        for(i=M;i>=0;i--)
        {
            if(dp1[i]>0)
            {
                tmax=i;
                break;
            }
        }
        memset(ans,0,sizeof(ans));
        ans[0]=0;
        int dflag;
        for(i=1;i<=tmax;i++)
        {
            memset(vis,0,sizeof(vis));
            dfs_ans=0;
            dflag=0;
            dfs(0,0,i);
//            printf("~~~%I64d!!!\n",dfs_ans);
            dp2[i]=dfs_ans;
        }
        memset(ans,0,sizeof(ans));
        for(i=1;i<=tmax;i++)
        {
            ll tans=0;
            for(j=1;j<=i;j++)
            {
                tans=(tans+dp2[j])%N;
            }
            ans[i]=((tans*720)%N*dp1[i])%N;
        }
        ll lans=0;
        for(i=1;i<=tmax;i++)
        {
            lans=(lans+ans[i])%N;
//            printf("%I64d$$$$$$$$$$$\n",lans);
        }
      //  printf("%I64d\n",lans);
      cout<<lans<<endl;
    }
    return 0;
}
