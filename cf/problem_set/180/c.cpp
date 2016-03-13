#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 10088
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
char str1[M];
char str2[M];
int main()
{
    while(~scanf("%s%s",str1,str2))
    {
        int flag1=0;
        int flag2=0;
        for(int i=0;str1[i];i++)
        {
            if(str1[i]=='1') flag1++;
        }
        for(int i=0;str2[i];i++) if(str2[i]=='1') flag2++;
//        printf("%d  %d **\n",flag1,flag2);
        if(flag1>=flag2) puts("YES");
        else
        {
            if(flag1+1==flag2)
            {
             //   puts("!!!!");
                if(flag1&1)
                {
                    puts("YES");
                }
                else puts("NO");
            } else puts("NO");
        }
    }
    return 0;
}
