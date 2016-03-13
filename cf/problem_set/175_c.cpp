#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<algorithm>
#define M 100
using namespace std;
int main()
{
    int n,m,i,j,k;
    while(cin>>n>>m)
    {
       int flag=0;
       for(i=0;i<m;i++)
       {
           if(flag)
           {
               printf(" %d",n-i);
           }
           else
           {
               flag=1;
               printf("%d",n-i);
           }
       }
       for(i=1;i<=n-m;i++)
       {
           if(flag)
           {
               printf(" %d",i);
           }
           else
           {
               flag=1;
               printf("%d",i);
           }
       }
       puts("");
    }
    return 0;
}
