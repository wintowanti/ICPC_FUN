#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#define M 1000
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int fa[M];
int num[M];
int head[M][4];
int count1[M];
queue<int > q1;
void init()
{
    while(!q1.empty()) q1.pop();
    for(int i=0;i<100;i++) fa[i]=i,num[i]=1;
    memset(head,-1,sizeof(head));
    memset(count1,0,sizeof(count1));
}
int find(int x)
{
    if(x==fa[x])
    return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int f1=find(x);
    int f2=find(y);
    if(f1!=f2)
    {
        fa[f2]=f1;
        num[f1]+=num[f2];
    }
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=0;i<m;i++)
        {
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            merge(t1,t2);
        }
        int flag=0;
        int tsum1=0;
        for(int i=1;i<=n;i++)
        {
            if(fa[i]==i)
            {
                if(num[i]>3)
                {
                    flag=1;
                    break;
                }
                if(num[i]==1)
                {
                   tsum1++;
                    q1.push(i);
                }
                else if(num[i]==2)
                {
                    tsum1--;
                }
            }
        }
        if(flag==1||(tsum1%3)!=0||(tsum1<0))
        {
            puts("-1");
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            int t1=find(i);
            if(num[t1]>=2)
            head[t1][count1[t1]++]=i;
        }
        for(int i=1;i<=n;i++)
        {
            if(count1[i]==3)
            {
                for(int j=0;j<3;j++){
                if(j)
                printf(" %d",head[i][j]);
                else
                printf("%d",head[i][j]);
                }
                puts("");
            }
            if(count1[i]==2)
            {
                for(int j=0;j<2;j++)
                {
                    if(j)
                    printf(" %d",head[i][j]);
                    else
                    printf("%d",head[i][j]);
                }
                int t1=q1.front();
                q1.pop();
                printf(" %d",t1);
                puts("");
            }
        }
        int cas=0;
        while(!q1.empty())
        {
            int t2=q1.front();
            q1.pop();
            int t1=cas%3;
            cas++;
            if(t1)
            {
                printf(" %d",t2);
            }
            else printf("%d",t2);
            if(t1==2)
            puts("");
        }
    }
    return 0;
}
/*
6 4
1 2
2 3
5 4
5 6
*/
