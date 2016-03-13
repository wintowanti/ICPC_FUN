#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<algorithm>
#define M 1000330
char s1[M];
char s2[M];
using namespace std;
int main()
{
    int i;
    while(~scanf("%s%s",s1,s2))
    {
        if(strlen(s1)!=strlen(s2))
        {
            puts("NO");
        }
        else
        {
            int n=strlen(s1);
            int flag1=0;
            for(i=0;i<n;i++)
            {
                if(s1[i]=='1')
                {
                    flag1=1;
                    break;
                }
            }
            int flag2=0;
            for(i=0;i<n;i++)
            {
                if(s2[i]=='1')
                {
                    flag2=1;
                    break;
                }
            }
            if(flag1==flag2)
            {
                puts("YES");
            }
            else
            {
                puts("NO");
            }
        }
    }
    return 0;
}
