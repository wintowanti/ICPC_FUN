#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<functional>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define M 100
#define pf printf("~~~~~~~~~~~~~\n");
#define pn printf("\n");
#define pff(x) printf("%d\n",x);
#define inf 0x3f3f3f3f
#define stop system("pause");
#define ll long long
using namespace std;
int n,m;
char map1[M][M];
bool vis[M][M];
char s1[M];
char s2[M];
int judge(int x,int y)
{
    if(x<0||x>n+1||y<0||y>m+1)
    return 0;
    return 1;
}
int main()
{
    int i,j,k,t1,t2,tmax;
    while(~scanf("%d%d",&m,&n)&&(n+m))
    {
    //    printf("%d   %d  \n",n,m);
        getchar();
        for(i=0;i<=n+1;i++)
        {
            if(i==0||i==n+1)
            {
                for(j=0;j<=m+1;j++)
                {
                    map1[i][j]='*';
                }
            }
            else
            {
                strcpy(s1,"*");
                gets(s2);
                strcat(s1,s2);
                strcat(s1,"*");
                strcpy(map1[i],s1);
            }
        }
        for(i=0;i<=n+1;i++)
        {
            for(j=0;j<=m+1;j++)
            {
                if(map1[i][j]==' ')
                {
                    map1[i][j]='*';
                }
            }
        }
        pf
        for(i=0;i<n+2;i++)
        {
            puts(map1[i]);
        }
    }
   return 0;
}
