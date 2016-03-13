#include< iostream>
#include< cstdio>
#include< cstdlib>
#include< cstring>
using namespace std;
const int maxn=800,maxm=500000,INF=1< < 30;
int tot,ans,n,m,S,T,V[maxm],G[maxm],C[maxm],N[maxm],F[maxn],B[maxm],v[maxn],slk[maxn],d[maxn];
int tt[80][80];
int get(int a,int b){ return (a-1)*n+b+n; }
void dw(int &a,int b){ if (b< a) a=b; }
void add(int a,int b,int up,int co)
{
  ++tot;V[tot]=b;G[tot]=up;C[tot]=co;N[tot]=F[a];F[a]=tot;
  ++tot;V[tot]=a;G[tot]=0;C[tot]=-co;N[tot]=F[b];F[b]=tot;
  B[tot]=tot-1;B[tot-1]=tot;
}
int aug(int u,int f)
{
   int p,t,left=f;
   if (u==T) { ans+=f*d[S];return f; }
   v[u]=1;
   for (p=F[u];p;p=N[p])
     if (G[p]>0&&!v[V[p]])
     {
       t=d[V[p]]+C[p]-d[u];
       if (t==0)
       {
          int delt=aug(V[p],G[p]< left? G[p] : left);
          if (delt>0) G[p]-=delt,G[B[p]]+=delt,left-=delt;
          if (left==0) return f;
       }else dw(slk[V[p]],t);
     }
   return f-left;
}
bool modlabel()
{
    int delt=INF,i;
    for (i=1;i<=T;i++)
      if (!v[i]) { dw(delt,slk[i]);slk[i]=INF;}
    if (delt==INF) return true;
    for (i=1;i< =T;i++)
      if (v[i]) d[i]+=delt;
    return false;
}
void Zkw_Flow()
{
     int i;ans=0;
     for (i=1;i<=T;i++) d[i]=0,slk[i]=INF;
     do{
         do {memset(v,0,sizeof(v));}while (aug(S,INF));
     }while (!modlabel());
     printf("%.2lf\n",(1.0*ans)/(1.0*n));
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,z;tot=0;
    scanf("%d%d",&m,&n);
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++) scanf("%d",&tt[i][j]);
    S=n*m+n+1;T=S+1;
    for (i=1;i<=n;i++) add(S,i,1,0);
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        for (z=1;z<=n;z++)
          add(i,get(j,z),1,z*tt[i][j]);
    for (i=1;i<=m;i++)
      for (j=1;j<=n;j++)
        add(get(i,j),T,1,0);
    Zkw_Flow();
    return 0;
}
