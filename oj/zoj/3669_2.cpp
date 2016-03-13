#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<functional>
#include<queue>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
#define M 100
#define pf printf("~~~~~~~~~~~~~\n");
#define pn printf("\n");
#define pff(x) printf("%d\n",x);
#define inf 0x3f3f3f3f
#define stop system("pause");
#define ll long long
using namespace std;
char s1[M];
char s2[M];
int coutnum[M],flag;
int tmp[M];
queue<int >q1;
int f(char p1,char p2)
{
    int t1,t2;
    if(p1=='m')
    t1=1;
    else if(p1=='p')
    t1=10;
    else if(p1=='s')
    t1=19;
    else if(p1=='z')
    t1=28;
    t2=p2-'1';
    t1=t1+t2;
    return t1;
}
int f2(int x)
{
    if(x<=9)
    return x;
    else if(x<=18)
    return x-9;
    else if(x<=27)
    return x-18;
    else return x-27;
}
void mypf(int x)
{
    if(x<=9)
    printf("%dm",f2(x));
    else if(x<=18)
    printf("%dp",f2(x));
    else if(x<=27)
    printf("%ds",f2(x));
    else printf("%dz",f2(x));
    return ;
}
void dfs(int x)
{
    int i,j,k,t1,t2,t3;
    if(x>=5)
    {
//        for(i=1;i<=34;i++)
//        {
//          //if(coutnum[i])
//             // pf
//        }
        flag=1;
        return ;
    }
    if(flag)
    return ;
    if(x==0){
        for(i=1;i<=34;i++)
        {
            if(coutnum[i]>=2)
            {
            //    printf("%d~~~~\n",i);
             //   stop
                coutnum[i]=coutnum[i]-2;
                dfs(x+1);
                coutnum[i]=coutnum[i]+2;
            }
            if(flag)
            return ;
        }
    }
    else
    {
        for(i=1;i<=27;i++)
        {
            if(coutnum[i]>0)
            {
                if(i<=27)
                {
                    t1=f2(i);
                    if(t1<8)
                    {
                        if(coutnum[i]>0&&coutnum[i+1]>0&&coutnum[i+2]>0)
                        {
                            coutnum[i]--;
                            coutnum[i+1]--;
                            coutnum[i+2]--;
                            dfs(x+1);
                            coutnum[i]++;
                            coutnum[i+1]++;
                            coutnum[i+2]++;
                        }
                    }
                }
            }
            if(flag)
            return ;
    }
        for(i=1;i<=34;i++)
        {
            if(coutnum[i]>=3)
            {
                coutnum[i]=coutnum[i]-3;
                dfs(x+1);
                coutnum[i]=coutnum[i]+3;
            }
            if(flag)
            return ;
        }
    }
    return ;
}
while(q1.empty())
{
    printf("%D,",)
}
int main()
{
    int i,j,k,t1,t2,t3,tsum;
    while(~scanf("%s",s1))
    {
        memset(coutnum,0,sizeof(coutnum));
        for(i=0;i<25;i=i+2){
            t1=f(s1[i+1],s1[i]);
        //    printf("%d  **\n",t1);
            coutnum[t1]++;
        }
        for(i=1,tsum=0;i<=34;i++)
        {
            if(coutnum[i]<4)
            {
                coutnum[i]++;
                flag=0;
                dfs(0);
                if(flag)
                {
                    tsum++;
                    q1.push(i);
                }
                coutnum[i]--;
            }
        }
        printf("%d",tsum);
        if(tsum)printf(" ");
        while(!q1.empty())
        {
           // printf("%d\n",q1.front());
            t1=q1.front();
            mypf(t1);
            q1.pop();
        }
        printf("\n");
    }
   return 0;
}
