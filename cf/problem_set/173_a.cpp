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
    int n,i,ans;
    char a[10];
    while(~scanf("%d",&n))
    {
        ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",a);
                if(a[1]=='-')
            {
                ans--;
            }
            else
            {
                ans++;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
