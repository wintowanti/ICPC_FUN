#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 500000
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
char str1[M];
int f(char p)
{
    if(p=='W')
    return 0;
    if(p=='E')
    return 1;
    if(p=='S')
    return 2;
    if(p=='N')
    return 3;
}
int main()
{
    int n,sx,sy,ex,ey;
    ll need[10];
    while(~scanf("%d%d%d%d%d",&n,&sx,&sy,&ex,&ey))
    {
        int x1=ex-sx;
        int y1=ey-sy;
    //    printf("%d   %d \n",x1,y1);
        scanf("%s",str1);
        if(abs(x1)+abs(y1)>n)
        {
            puts("-1");
            continue;
        }
        memset(need,0,sizeof(need));
        if(x1<0) need[0]=-x1;else need[1]=x1;
        if(y1<0) need[2]=-y1;else need[3]=y1;
        int ans=0;
        int flag=0;
        for(int i=0;str1[i];i++)
        {
            if(need[0]==0&&need[1]==0&&need[2]==0&&need[3]==0)
            {
                flag=1;
                break;
            }
            int t1=f(str1[i]);
        //    printf("~~~%d \n",t1);
            if(need[t1]>0)
            {
           //     printf("~~~%d\n",t1);
                need[t1]--;
            }
            ans++;
        }
        if(need[0]==0&&need[1]==0&&need[2]==0&&need[3]==0)
        {
                flag=1;
            //    break;
        }
        if(flag)
        {
            cout<<ans<<endl;
        }
        else
        {
            puts("-1");
        }
    }
    return 0;
}
/*
5 0 0 1 0
EESNW
*/
