#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<functional>
#include<queue>
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
int n,m,sx,sy,ex,ey;
char map1[M][M];
int vis[M][M];
int o[4][2]={0,1,0,-1,1,0,-1,0};
char s1[M];
char s2[M];
struct E
{
    int x,y,step;
    friend bool operator <(const E &,const E &);
};
priority_queue<E> q1;
bool operator<(const E &a,const E &b)
{
    if(a.step>b.step)
    return 1;
    return 0;
}
int judge(int x,int y)
{
    if(x<0||x>n+1||y<0||y>m+1)
    return 0;
    return 1;
}
int f1(int x,int y)
{
    if(x==0||x==n+1||y==0||y==m+1)
    return 1;
    return 0;
}
int bfs(int x,int y)
{
    while(!q1.empty()) q1.pop();
    int x1,y1,x2,y2,i,j,k,t1,t2,t3;
    E e1,e2;
    e1.x=x;
    e1.y=y;
    e1.step=0;
    q1.push(e1);
    memset(vis,inf,sizeof(vis));
    vis[x][y]=0;
    while(!q1.empty())
    {
        e1=q1.top();
        q1.pop();
        x1=e1.x;
        y1=e1.y;
//        printf("%d   %d   %d \n",x1,y1,e1.step);
//        stop
        if(x1==ex&&y1==ey)
        {
            return e1.step;
        }
        for(i=0;i<4;i++)
        {
            x2=x1+o[i][0];
            y2=y1+o[i][1];
            if(judge(x2,y2)&&map1[x2][y2]!='X')
            {
                if(vis[x2][y2]<e1.step+1)
                    continue;
                t1=f1(x1,y1);
                t2=f1(x2,y2);
                e2.x=x2;
                e2.y=y2;
                if((x2==0||x2==n+1)&&(y2==0||y2==m+1))
                t3 =e1.step;
                else if(t1==t2) t3=e1.step+1;
                else t3=e1.step;
                if(t3<vis[x2][y2])
                {
                    vis[x2][y2]=t3;
                    e2.step=t3;
                    q1.push(e2);
                }
            }
        }
    }
    return -1;
}
int main()
{
    int i,j,k,t1,t2,tcout1,tcout2;
    tcout1=1;
    char tc;
    while(~scanf("%d%d",&m,&n)&&(n+m))
    {
        getchar();
        printf("Board #%d:\n",tcout1++);
        for(i=0;i<=n+1;i++)
        {
            if(i==0||i==n+1)
            {
                for(j=0;j<m+2;j++)
                {
                    map1[i][j]='*';
                }
                map1[i][j]='\0';
            }
            else
            {
                strcpy(s1,"*");
                gets(s2);
                strcat(s1,s2);
                strcat(s1,"*");
                strcpy(map1[i],s1);
            }
        }
        for(i=0;i<n+2;i++)
        {
            for(j=0;j<m+2;j++)
            {
                if(map1[i][j]==' ')
                    map1[i][j]='*';
            }
        }
//        for(i=0;i<n+2;i++)
//        {
//            puts(map1[i]);
//        }
        tcout2=1;
        while(~scanf("%d%d%d%d",&sy,&sx,&ey,&ex))
        {
            if(sx||sy||ex||ey)
            {
                printf("Pair %d: ",tcout2++);
                tc=map1[ex][ey];
                map1[ex][ey]='E';
                t1=bfs(sx,sy);
                map1[ex][ey]=tc;
                if(t1==-1)
                {
                    printf("impossible.\n");
                }
                else
                {
                    printf("%d segments.\n",t1-1);
                }
            }
            else break;
        }

    }
   return 0;
}
    /*
5 4
XXXXX
X   X
XXX
 XXX
    */
