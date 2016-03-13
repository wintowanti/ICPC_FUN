#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<map>
#define M 1000020
#define N 1010
#define NV N
#define NE M
#define MAXN 100
#define ll long long
#define inf 0x3f3f3f3f
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
map<string,int> map1;
int has[MAXN];
int point[MAXN];
int a[MAXN][MAXN];
int mapn;
int S,T;
struct G{
    int head[N],en;
    struct E{
        int u,v,cap,next;
    }e[M];
    void init(){
        memset(head,-1,sizeof(head));en=0;
    }
    void add(int u,int v,int cap){
        e[en].u=u;e[en].v=v;e[en].cap=cap;e[en].next=head[u];head[u]=en++;
        e[en].u=v;e[en].v=u;e[en].cap=0  ;e[en].next=head[v];head[v]=en++;
    }
}g1;
int dis[N],dinic_sp,dinic_tp,cur[N];
int my_que[N];
int bfs(){
    int hp=0,tp=-1;
    my_que[++tp]=dinic_sp;
    memset(dis,0,sizeof(dis));
    dis[dinic_sp]=1;
    while(hp<=tp){
        int u=my_que[hp++];
        for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
            int v=g1.e[i].v;
            if(!dis[v]&&g1.e[i].cap>0){
                dis[v]=dis[u]+1;
                my_que[++tp]=v;
            }
        }
    }
   return dis[dinic_tp];
}
int dfs(int u,int tmax){
    if(u==dinic_tp||tmax==0){
        return tmax;
    }
    int tsum=0,f;
    for(int  & i=cur[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(dis[v]==dis[u]+1&&g1.e[i].cap>0){
            f=dfs(v,min(tmax,g1.e[i].cap));
            g1.e[i].cap-=f;
            g1.e[i^1].cap+=f;
            tmax-=f;
            tsum+=f;
            if(!tmax) break;
        }
    }
    return tsum;
}
int dinic(int sp,int tp){
    dinic_sp=sp;dinic_tp=tp;
    int tsum=0;
    while(bfs()){
        for(int i=0;i<=tp;i++) cur[i]=g1.head[i];
        tsum+=dfs(sp,inf);
    }
    return tsum;
}
int find1(char *p)
 {
   //  puts(p);
     if(map1.find((string)p)==map1.end())
     {
       //  puts(p);
         return map1[(string)p]=mapn++;
     }
     else
        return map1[p];
 }
 int main()
 {
     int n,m;
   //  freopen("in.txt","r",stdin);
     while(~scanf("%d%d",&n,&m))
     {
         map1.clear();
         mapn=1;
         g1.init();
         memset(has,0,sizeof(has));
         memset(point,0,sizeof(point));
         memset(a,0,sizeof(a));
         char str1[100],str2[100],str3[100];
         for(int i=0;i<m;i++)
         {
             scanf("%s%s%s",str1,str2,str3);
             int t1,t2;
             t1=find1(str1);
             t2=find1(str2);
             if(str3[0]=='w')
             {
                 has[t1]++;
             }
             else has[t2]++;
         }
         int m1;
         scanf("%d",&m1);
         strcpy(str3,"DD");
         int win1=find1(str3);
         int flag=0;
         for(int i=0;i<m1;i++)
         {
            scanf("%s%s",str1,str2);
             int t1=find1(str1);
             int t2=find1(str2);
             if(t1==win1||t2==win1)
             {
                 has[win1]++;
                 flag++;
                 continue;
             }
             else
             {
                 point[t1]++;
                 a[t1][t2]++;
             }
         }
       //  printf("!!!!!!!!!%d\n",has[win1]);
         S=0,T=mapn;
         int tmax=has[win1];
         for(int i=1;i<mapn;i++)
         {
             if(i!=win1&&point[i]){
                g1.add(S,i,point[i]);
               // printf("~~~SSS   %d   %d \n",i,point[i]);
             }
             if(i!=win1)
             {
                if(tmax-has[i]-1>0)
                {
                    g1.add(i,T,tmax-has[i]-1);
                  //  printf("TTTT   %d  %d   @@@@\n",i,tmax-has[i]-1);
                }
             }
         }
         for(int i=1;i<mapn;i++)
         {
             for(int j=1;j<mapn;j++)
             {
                 if(a[i][j]!=0)
                 {
                    // printf("*******%d   %d  %d \n",i,j,a[i][j]);
                     g1.add(i,j,a[i][j]);
                 }
             }
         }
         int flag2=0;
         for(int i=1;i<mapn;i++)
         {
             if(i!=win1)
             {
                 if(has[i]>=tmax)
                 {
                     puts("No");
                    flag2=1;
                     break;
                 }
             }
         }
         if(flag2)
         {
             continue;
         }
         int ans=dinic(S,T);
     //    cout<<ans<<endl;
         if(ans==m1-flag)
         {
             puts("Yes");
         }
         else
         {
             puts("No");
         }
     }
     return 0;
 }
