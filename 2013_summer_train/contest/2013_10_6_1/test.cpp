#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define ll int
#define M 500
#define eps 0.00000001
using namespace std;
struct G{
    double a[M][M];
    double ans[M];
    bool free[M];
    int work(int n,int var){
        int i,j,k,r;
        for(i=0;i<n;i++){
            r=i;
            for(j=i+1;j<n;j++) if(fabs(a[j][i])>fabs(a[r][i])) r=j;
            if(r!=i) for(j=0;j<=n;j++) swap(a[r][j],a[i][j]);
            for(j=n;j>=i;j--)
                for(k=i+1;k<n;k++) a[k][j]-=a[k][i]/a[i][i]*a[i][j];
        }
        for(int i=n-1;i>=0;i--){
            ans[i]=a[i][var];
            for(int j=i+1;j<n;j++){
                ans[i]-=a[i][j]*ans[j];
            }
            ans[i]/=a[i][i];
        }
        return 0;
    }
}g1;
ll n,m;
char map1[M][M];
ll map2[M][M];
bool vis[M][M];
struct E{
    ll x,y;
};
ll judge(ll x,ll y){
    if(x<0||x>n-1||y<0||y>m-1) return 0;
    return 1;
}
ll o[4][2]={
    0,1,
    0,-1,
    1,0,
    -1,0
};
queue<E> q1;
ll bfs(ll sx,ll sy){
    while(!q1.empty()) q1.pop();
    memset(vis,1,sizeof(vis));
    E e1,e2;e1.x=sx;e1.y=sy;
    q1.push(e1);
    vis[sx][sy]=0;
    while(!q1.empty()){
        e1=q1.front();q1.pop();
        if(map1[e1.x][e1.y]=='E') return 1;
        for(ll i=0;i<4;i++){
            ll x1=e1.x+o[i][0];
            ll y1=e1.y+o[i][1];
            if(judge(x1,y1)==0) continue;
            if(map1[x1][y1]=='#') continue;
            if(vis[x1][y1]){
                vis[x1][y1]=0;
                e2.x=x1;e2.y=y1;q1.push(e2);
            }
        }
    }
    return 0;
}
double work(){
    ll en=0;
    memset(map2,-1,sizeof(map2));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(map1[i][j]!='E'&&map1[i][j]!='#'){
                map2[i][j]=en++;
            }
        }
    }
    int equ=en;int var=en;
    for(int i=0;i<equ;i++){
        for(int j=0;j<var+1;j++){
            g1.a[i][j]=0.00;
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(map1[i][j]!='E'&&map1[i][j]!='#'){
                ll tsum=0;
                for(ll k=0;k<4;k++){
                    ll x1=i+o[k][0];
                    ll y1=j+o[k][1];
                    if(judge(x1,y1)==0) continue;
                    if(map1[x1][y1]=='#') continue;
                    tsum++;
                }
                if(tsum==0) tsum=1;
                ll t1=map2[i][j];
                g1.a[t1][t1]=-tsum;
                g1.a[t1][var]=-tsum;
                for(ll k=0;k<4;k++){
                    ll x1=i+o[k][0];
                    ll y1=j+o[k][1];
                    if(judge(x1,y1)==0) continue;
                    if(map1[x1][y1]=='#') continue;
                    if(map2[x1][y1]==-1) continue;
                    ll t2=map2[x1][y1];
                    g1.a[t1][t2]=1;
                }
            }
        }
    }
    ll tt=g1.work(equ,var);
    double ans;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(map1[i][j]=='S'){
                ans=g1.ans[map2[i][j]];
                break;
            }
        }
    }
    return ans;
}
int main(void)
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&m)){
        for(ll i=0;i<n;i++){
            scanf("%s",map1[i]);
        }
        ll sx,sy;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(map1[i][j]=='S'){
                    sx=i;sy=j;
                    break;
                }
            }
        }
        if(bfs(sx,sy)){
            double ans=work();
            printf("%.2lf\n",ans);
        }
        else{
            puts("-1");
        }
    }
}
/*
3 3
-2 1 1 -2
1 -2 0 -2
1 0 -2 -2




15 15
E.......#SE#...
.......#E.E#...
........#E#....
........#E#....
.........#.....
..........#....
.........#E#...
.........##....
.........#E#...
..........#....
..........#....
...............
..........#....
..........####.
........#EE#E..
*/
