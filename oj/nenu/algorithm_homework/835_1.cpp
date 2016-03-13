#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<algorithm>
#define M 100
using namespace std;
char str[M];
char tmp[M];
bool use[M];
int n,num;
int cmp(char a,char b)
{
    if(a>b)
    return 0;
    return 1;
}
void dfs(int x,char *p)
{
  //  puts(p);
    if(x==n)
    {
        p[x]='\0';
        puts(p);
        num++;
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(use[i]==1)
        {
            if(i>0&&str[i]==str[i-1]&&use[i-1]==1)
            {
                continue ;
            }
            use[i]=0;
            tmp[x]=str[i];
            tmp[x+1]='\0';
            dfs(x+1,tmp);
            use[i]=1;
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(~scanf("%d",&n))
    {
            scanf("%s",str);
            n=strlen(str);
            sort(str,str+n,cmp);
            memset(use,1,sizeof(use));
            num=0;
            tmp[0]='\0';
            dfs(0,tmp);
            cout<<num<<endl;
    }
    return 0;
}
