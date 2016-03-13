#include<stdio.h>
#include<iostream>
#include<string.h>
#define M 100008
#define N 1000000007
using namespace std;
int dp[M][4];
char str1[M];
char str2[M];
int main()
{
    int n;
    while(cin>>n)
    {
        scanf("%s%s",str1,str2);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;str1[i];i++)
        {
            int be1,end1,be2,end2;
            if(str1[i]=='?'){be1=0;end1=9;}
            else {be1=end1=str1[i]-'0';}
            if(str2[i]=='?'){be2=0;end2=9;}
            else {be2=end2=str2[i]-'0';}
            for(int j=be1;j<=end1;j++)
            {
                for(int k=be2;k<=end2;k++)
                {
                    if(j>k)
                    {
                        dp[i+1][1]=(dp[i+1][1]+dp[i][1])%N;
                        dp[i+1][1]=(dp[i+1][1]+dp[i][0])%N;
                        dp[i+1][3]=(dp[i+1][3]+dp[i][2])%N;
                    }
                    else if(j<k)
                    {
                        dp[i+1][2]=(dp[i+1][2]+dp[i][2])%N;
                        dp[i+1][2]=(dp[i+1][2]+dp[i][0])%N;
                        dp[i+1][3]=(dp[i+1][3]+dp[i][1])%N;
                    }
                    else if(j==k)
                    {
                        dp[i+1][0]=(dp[i+1][0]+dp[i][0])%N;
                        dp[i+1][1]=(dp[i+1][1]+dp[i][1])%N;
                        dp[i+1][2]=(dp[i+1][2]+dp[i][2])%N;
                    }
                    dp[i+1][3]=(dp[i+1][3]+dp[i][3])%N;
                }
            }
        }
        cout<<dp[n][3]<<endl;
    }
    return 0;
}
