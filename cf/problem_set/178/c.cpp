#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>                                                                                                                                                                                                                                                                                                                                                                                                                                                                   o.h>
#define M 1008
#define ll long long
#define N 1000000007
using namespace std;
ll dp[M][M];
ll a[M];
int num[M];
int cmp(int x,int y)
{
    if(x<y)
    return 1;
    return 0;
}
ll dfs(int x,int y)
{
    if(x<0||y<0)
    {
        return 0;
    }
    if(x==y||y==0)
    {
        return dp[x][y]=1;
    }
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    int t1=dfs(x-1,y);
    int t2=dfs(x-1,y-1);
    return dp[x][y]=(t1+t2)%N;
}
int main()
{
    int n,m;
    while(cin>>n)
    {
        cin>>m;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            cin>>num[i];
        }
        if(n==m)
        {
            puts("1");
            continue;
        }
     //   cout<<"!!!"<<endl;
        num[m]=n;
        a[0]=1;
        a[1]=1;
        for(int i=2;i<=n;i++)
        {
            a[i]=(a[i-1]*2)%N;
        }
//        for(int i=0;i<=m;i++)
//        {
//            cout<<num[i]<<"  ";
//        }
//        puts("");
        sort(num,num+m+1,cmp);
//        for(int i=0;i<=m;i++)
//        {
//            cout<<num[i]<<"  ";
//        }
//        puts("");
        int tsum=0;
        ll sum=1;
        for(int i=0;i<=m;i++)
        {
            if(i==0)
            {
                tsum+=num[i]-1;
                int t1=num[i]-1;
                sum=(sum*dfs(tsum,t1))%N;
            }
            else if(i==m)
            {
                tsum+=num[i]-num[i-1];
                int t1=num[i]-num[i-1];
                sum=(sum*dfs(tsum,t1))%N;
            }
            else
            {
                tsum+=(num[i]-num[i-1]-1);
                int t1=num[i]-num[i-1]-1;
            //    cout<<t1<<"$$"<<endl;
                int t2=dfs(tsum,t1);
          //      cout<<"t2!!"<<t2<<"!!!"<<t1<<"!!!"<<tsum<<endl;
                sum=sum*dfs(tsum,t1);
                sum=sum%N;
            //    cout<<"~~~"<<sum<<endl;
                sum=sum*a[t1];
                sum=sum%N;
            }
        //    cout<<sum<<"tsum:"<<tsum<<endl;
        }
        cout<<sum<<endl;
    }
    return 0;
}
