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
    int cas;
    while(cin>>cas)
    {
        while(cas--)
        {
            int n;
            cin>>n;
            int flag=0;
            if(n>=11&&n<=12)
            {
                flag=1;
                puts("Basic Training");
            }
            if(n>=12&&n<=12)
            {
                flag=1;
                puts("Rookie Contest");
            }
            if(n>=2&&n<=4)
            {
                flag=1;
                puts("Spring Training");
            }
            if(n>=4&&n<=4)
            {
                flag=1;
                puts("BNU Contest");
            }
            if(n>=7&&n<=7)
            {
                flag=1;
                puts("Practice Week");
            }
            if(n>=7&&n<=8)
            {
                flag=1;
                puts("Summer Training");
            }
            if(n>=9&&n<=11)
            {
                flag=1;
                puts("Regional Contest");
            }
            if(!flag)
            puts("Unknown");
        }
    }
    return 0;
}
