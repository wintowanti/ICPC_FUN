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
int dfs(int x,int y)
{
    if((x&1)&&(y&1))
    {
        return 0;
    }
    int tmin=1;
    if(!(x&1))
    {
        int t1=!dfs(x/2,y);
        if(t1<tmin) tmin=t1;
    }
    if(!(y&1))
    {
        int t1=!dfs(x,y/2);
        if(t1<tmin) tmin=t1;
    }
    return tmin;
}
int main()
{
    int cas,x,y;
    while(cin>>cas)
    {
        while(cas--)
        {
            scanf("%d%d",&x,&y);
            int t1=dfs(x,y);
        //    printf("%d !!\n",t1);
            if(t1)
            {
                puts("Adidas loses");
            }
            else
            {
                puts("Adivon prevails");
            }
        }
    }
    return 0;
}
