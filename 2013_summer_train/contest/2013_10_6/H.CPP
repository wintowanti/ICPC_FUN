#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const double inf=1e15;
const double eps=1e-8;
struct point{
    double x,y;
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    bool friend operator<(const point &a,const point &b){
        return a.y<b.y;
    }
}p[1005];
struct edge{
    int u,v;
    double c;
    bool friend operator<(const edge &a,const edge &b){
        return a.c<b.c;
    }
}e[1005*1005];
int m;
double dist(point a,point b){
    double x=a.x-b.x;
    double y=a.y-b.y;
    return sqrt(x*x+y*y);
}
int pa[1005*1005];
int find(int x){
    if(x==pa[x]) return x;
    return pa[x]=find(pa[x]);
}
double kelusi(){
    for(int i=0;i<=m;i++) pa[i]=i;
    double ans=0.0000;
    sort(e,e+m);
    for(int i=0;i<m;i++){
        if(find(e[i].u)==find(e[i].v)) continue;
        int x=find(e[i].u);
        int y=find(e[i].v);
        if(p[x].y>=p[y].y){
            pa[x]=y;
            ans+=e[i].c;
        }else{
            pa[y]=x;
            ans+=e[i].c;
        }
    }
    return ans;
}
int main(){
    int n;
    while(scanf("%d",&n)&&n){
        double miny=inf;
        for(int i=0;i<n;i++){
            p[i].input();
        }
        m=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                e[m].u=i,e[m].v=j;
                e[m].c=dist(p[i],p[j]);
                m++;
            }
        }
        printf("%lf\n",kelusi());
    }
}
