#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<algorithm>
#define M 308
using namespace std;
bool dp[M][M][M];
bool dp1[M][M];
int o[4][3]{
1,0,0,
0,1,0,
0,0,1,
1,1,1
};
int o1[3][2]{
0,1,
1,0,
1,1
};
int main()
{
    int i,j,k,n,x,y,z;
    memset(dp,0,sizeof(dp));
    memset(dp1,0,sizeof(dp1));
    for(i=0;i<=300;i++)
    {
        for(j=0;j<=300;j++)
        {
            for(k=0;k<=300;k++)
            {
                if(dp[i][j][k]==0)
                {
                    for(int i1=0;i1<4;i1++)
                    {
                        for(int j1=1;;j1++)
                        {
                            int t1=i+o[i1][0]*j1;
                            int t2=j+o[i1][1]*j1;
                            int t3=k+o[i1][2]*j1;
                            if(t1>300||t2>300||t3>300)
                            {
                                break;
                            }
                            else
                            {
                                dp[t1][t2][t3]=1;
                            }
                        }
                    }
                }
            }
        }
    }
  //  cout<<"mark"<<endl;
    for(i=0;i<=300;i++)
    {
        for(j=0;j<=300;j++)
        {
            if(dp1[i][j]==0)
            {
                for(int i1=0;i1<3;i1++)
                {
                    for(int j1=1;;j1++)
                    {
                        int t1=i+o1[i1][0]*j1;
                        int t2=j+o1[i1][1]*j1;
                        if(t1>300||t2>300)
                        {
                            break;
                        }
                        else
                        {
                            dp1[t1][t2]=1;
                        }
                    }
                }
            }
        }
    }
//    for(i=0;i<4;i++)
//    {
//        for(j=0;j<4;j++)
//        {
//            printf("%d ~~%d    %d \n",i,j,dp1[i][j]);
//        }
//    }
    while(~scanf("%d",&n))
    {
        if(n==1)
        {
            scanf("%d",&x);
            if(x==0)
            {
                puts("BitAryo");
            }
            else
            {
                puts("BitLGM");
            }
        }
        else if(n==2)
        {
            scanf("%d%d",&x,&y);
         //   cout<<dp1[x][y];
            if(dp1[x][y])
            {
                puts("BitLGM");
            }
            else
            {
                puts("BitAryo");
            }
        }
        else
        {
            scanf("%d%d%d",&x,&y,&z);
          //  printf("%d  ~~\n",dp[x][y][z]);
            if(!dp[x][y][z])
            {
                puts("BitAryo");
            }
            else
            {
                puts("BitLGM");
            }
        }
    }
    return 0;
}











