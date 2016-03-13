#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
struct point{
    int x,y;
    void input(){
        scanf("%d%d",&x,&y);
    }
    void output(){
        printf("%d %d\n",x,y);
    }
    bool friend operator<(const point &a,const point &b){
        if(a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    }
}st,en,p[10001],r[10001],pnt[20001];
int mult(point a,point b,point c){
    int d=(a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
    if(d<0) return -1;
    if(d>0) return 1;
    return 0;
}
map<point,int> mymap;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        mymap.clear();
        for(int i=0;i<n;i++){
            p[i].input(),r[i].input();
            mymap[p[i]]=i;
        }
        int l=0;
        pnt[l++]=p[0],pnt[l++]=r[0];
        int id=0;
        while(1){
            int id=mymap[r[id]];
            if(id==0) break;
            pnt[l++]=r[id];
        }
        for(int i=0;i<l;i++) pnt[i].output();
//        if(flag==0) puts("OUTSIDE");
//        else if(flag==1) puts("INSIDE");
//        else if(flag==2) puts("BORDER");
    }
}
/*
8
0 2 0 0
3 0 3 2
1 2 0 2
0 0 3 0
2 1 1 1
3 2 2 2
2 2 2 1
1 1 1 2
*/
