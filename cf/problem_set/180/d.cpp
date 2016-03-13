#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 880000
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int a1[M];
int a2[M];
int cmp(int x,int y)
{
    if(x>y)
    return 0;
    return 1;
}
int binfind(int x,int l,int r)
{
    int min=r+1;
    int mid;
    while(r>=l)
    {
        mid=(l+r)>>1;
        if(a2[mid]>=x)
        {
            min=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return min;
}
int main()
{
    int k,n,m;
   while(~scanf("%d%d%d",&n,&m,&k))
//    scanf("%d%d%d",&n,&m,&k);
    {
        for(int i=0;i<n;i++) scanf("%d",&a1[i]);
        for(int i=0;i<m;i++) scanf("%d",&a2[i]);
        if(n>m)
        {
            puts("YES");
            continue;
        }
        sort(a1,a1+n,cmp); sort(a2,a2+m,cmp);
    //    printf("!!!!");
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(i&&a1[i-1]==a1[i]) continue;
            int tcout1=n-i;
            int tcout2=binfind(a1[i],0,m-1);
            tcout2=m-tcout2;
            if(tcout1>tcout2){flag=1;break;}
        }
        if(flag) puts("YES");else puts("NO");
    }
    return 0;
}
/*
50 66 10
10 9 10 5 5 2 2 6 4 8 9 1 6 3 9 7 8 3 8 5 6 6 5 7 2 10 3 6 8 1 8 8 9 5 10 1 5 10 9 4 7 8 10 3 3 4 7 8 6 3
5 3 2 6 4 10 2 3 1 8 8 10 1 1 4 3 9 2 9 9 8 8 7 9 4 1 1 10 5 6 3 7 2 10 2 3 3 3 7 4 1 3 1 6 7 6 1 9 1 7 6 8 6 1 3 3 3 4 3 6 7 8 2 5 4 1 4
*/
