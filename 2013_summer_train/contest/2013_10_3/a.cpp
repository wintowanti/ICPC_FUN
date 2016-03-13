#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
struct point{
    ll x,y;
}p[50100],res[50100];
ll are[50100];
ll mult(point a,point b,point c){
    return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&p[i].x,&p[i].y);
    }
    p[n]=p[0];
    are[1]=are[0]=0.0000;
    for(int i=2;i<=n;i++){
        are[i]=are[i-1]+abs(mult(p[i-1],p[i],p[0]));
    }
    ll sum=are[n];
    //for(int i=0;i<=n;i++) printf("%lf\n",are[i]);
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        if(u>v) swap(u,v);
        ll area=00000;
        area+=are[u];
        area+=(are[n]-are[v]);
        area+=abs(mult(p[u],p[v],p[0]));
        area=min(area,sum-area);
        if(area%2) printf("%lld.5\n",area/2);
        else printf("%lld.0\n",area/2);
//        printf("%.1lf\n",min(area,sum-area));
    }
}
