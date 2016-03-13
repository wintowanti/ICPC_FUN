#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 10099
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
char str1[M];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        scanf("%s",str1);
        int flag1=-1;
        int flag2=-1;
        int flag3=-1;
        int flag4=-1;
        for(int i=0;str1[i];i++)
        {
            if(str1[i]=='R')
            {
                if(flag1==-1)
                {
                    flag1=i+1;
                }
                flag2=i+1;
            }
            else if(str1[i]=='L')
            {
                if(flag3==-1)
                {
                    flag3=i+1;
                }
                flag4=i+1;
            }
        }
        if(flag1!=-1&&flag3==-1)
        {
            cout<<flag1<<" "<<flag2+1;
        }
        else if(flag1==-1&&flag3!=-1)
        {
            cout<<flag4<<" "<<flag3-1;
        }
        else if(flag1!=-1&&flag3!=-1)
        {
            cout<<flag1<<" "<<flag2<<endl;
        }
    }
    return 0;
}
