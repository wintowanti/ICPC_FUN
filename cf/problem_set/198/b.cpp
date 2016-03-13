#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const double inf=1e15;
const double eps=1e-8;
struct point{
    double x,y;
}p[305],res[305];
double mult(point sp,point ep,point op){
    return (sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y);
}
bool operator<(const point &l,const point &r){
    return l.y<r.y||(l.y==r.y&&l.x<r.x);
}
int graham(point pnt[],int n,point res[]){
    int i,len,k=0,top=1;
    sort(pnt,pnt+n);
    if(n==0) return 0;res[0]=pnt[0];
    if(n==1) return 1;res[1]=pnt[1];
    if(n==2) return 2;res[2]=pnt[2];
    for(i=2;i<n;i++){
        while(top&&mult(pnt[i],res[top],res[top-1])>=eps) top--;
        res[++top]=pnt[i];
    }
    len=top;res[++top]=pnt[n-2];
    for(i=n-3;i>=0;i--){
        while(top!=len&&mult(pnt[i],res[top],res[top-1])>=eps) top--;
        res[++top]=pnt[i];
    }
    return top;
}
int n;
double solve(point p[]){
    double maxarea=-inf;
    for(int i=0;i<n;i++){
        for(int k=i+2;k<n;k++){
            int j=i;
            while(j!=k&&fabs(mult(p[j+1],p[k],p[i]))>fabs(mult(p[j],p[k],p[i]))) j=(j+1)%n;
            double area1=fabs(mult(p[j],p[k],p[i]))*0.5;
            j=k;
            while(j!=i&&fabs(mult(p[j+1],p[k],p[i]))>fabs(mult(p[j],p[k],p[i]))) j=(j+1)%n;
            double area2=fabs(mult(p[j],p[k],p[i]))*0.5;
            maxarea=max(maxarea,area1+area2);
        }
    }
    return maxarea;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
        int cnt=graham(p,n,res);
        n=cnt;
        res[n]=res[0];
        printf("%.6lf\n",solve(res));
    }
}
