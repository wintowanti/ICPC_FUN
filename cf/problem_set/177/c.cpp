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
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(m>n)
        {
            puts("-1");
        }
        else
        {
            if(m==1)
            {
                if(n==1)
                {
                    puts("a");
                }
                else
                {
                    puts("-1");
                }
            }
            else
            {
                int n1=m-2;
                for(int i=0;i+n1<n;i++)
                {
                    if(!(i%2))
                    {
                        printf("a");
                    }
                    else
                    {
                        printf("b");
                    }
                }
                for(int i=0;i<n1;i++)
                {
                    printf("%c",i+'c');
                }
                puts("");
            }
        }
    }
    return 0;
}
