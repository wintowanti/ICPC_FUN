#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<algorithm>
#define M 1004400
char s1[M];
int z(int x)
{
    if(x>=0)
    return x;
    return -x;
}
using namespace std;
int main()
{
    int i,j,n,t1,t2;
    while(~scanf("%d",&n))
    {
        t1=0;
        t2=0;
        for(i=0;i<n;i++)
        {
            int  x,y;
            scanf("%d%d",&x,&y);
            if(z(t1+x-t2)<=500)
            {
                t1=t1+x;
                s1[i]='A';
            }
            else
            {
                t2=t2+y;
                s1[i]='G';
            }
         //   printf("%d  %d \n",t1,t2);
        }
        s1[i]='\0';
        puts(s1);
    }
    return 0;
}
