#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<iostream>
#define M 30
#define N 1008
using namespace std;
int fa[M];
int has[M];
int flagin[M];
int flagout[M];
int map1[N][N][21];
int num[M];
int vis[M];
int cmp(char *p1,char *p2)
{
    if(strcmp(p1,p2)>0)
        return 0;
    return 1;
}
int findfa(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=findfa(fa[x]);
}
void un(int x,int y)
{
    int fa1=findfa(x);
    int fa2=findfa(y);
    if(fa1!=fa2)
    {
        fa[fa2]=fa1;
    }
}
void dfs(int x)
{

}
int main()
{
    int cas;
    while(~scanf("%d",&cas))
    {
        while(cas--)
        {
            int n;
            scanf("%d",n);
            memset(has,0,sizeof(has));
            memset(num,0,sizeof(num));
            memset(flagin,0,sizeof(flagin));
            memset(flagout,0,sizeof(flagout));
            memset(vis,0,sizeof(vis));
            for(int i=0;i<26;i++) fa[i]=i;
            for(int i=0;i<n;i++)
            {
                char str[30];
                scanf("%s",str);
                int t1=strlen(str);
                int t2=str[0]-'a';
                int t3=str[t1-1]-'a';
                un(t2,t3);
                has[t2]=1;
                has[t3]=1;
                flagin[t2]++;
                flagout[t3]++;
                strcmp(map1[num[t2]++],str);
            }
            int flag1=0;
            int flag2=0;
            int flag=0;
            int flag3=0;
            int st=-1;
            for(int i=0;i<n;i++)
            {
                if(has[i])
                {
                    flag++;
                    if(flagin[i]!=flagout[i])
                    {
                        if(flagin[i]==flagout[i]+1) flag1++,st=i;
                        else if(flagin[i]==flagout[i]-1) flag2++;
                        else flag3++;
                    }
                }
            }
            if(flag==1&&flag3==0
               &&((flag1==0&&flag2==0)
                  ||(flag1==1&&flag2==1)))
            {
                for(int i=0;i<26;i++)
                {
                    if(has[i])
                    {
                        sort(map1[i],map1[i]+num[i],cmp);
                    }
                }
                if(st==-1) for(int i=0;i<26;i++) if(has[i]){ st=i,break;}
                dfs(st);
            }
            else puts("***");
        }
    }
    return 0;
}
