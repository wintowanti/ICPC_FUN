#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 100
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
bool can[5][M];
int a[M];
int main()
{
    int n,cas,x,l;
    while(~scanf("%d",&cas))
    {
        while(cas--)
        {
            scanf("%d%d%d",&l,&x,&n);
            for(int i=0;i<n;i++) scanf("%d",&a[i]);
            memset(can,0,sizeof(can));
            can[0][0]=1;
            for(int i=0;i<n;i++)
            {
                for(int j=1;j<=4;j++)
                {
                    int t1=a[i];
                    for(int k=1000;k-t1>=0;k--)
                    {
                        if(can[j-1][k-t1]==1)
                        {
                            can[j][k]=1;
                        }
                    }
                }
            }
//            for(int i=0;i<=4;i++)
//            {
//                printf("%d  ~~",i);
//                for(int j=0;j<10;j++)
//                {
//                    printf("%d  ",can[i][j]);
//                }
//                puts("");
//            }
            if(can[4][l-x])
            {
                puts("Yes");
            }
            else puts("No");
        }
    }
    return 0;
}
