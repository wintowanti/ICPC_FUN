#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<map>
#include<set>
#include<math.h>
#include<algorithm>
using namespace std;
const double eps=1e-8;
int dblcmp(double x){
    if(x<-eps) return -1;
    if(x>eps) return 1;
    return 0;
}
struct in{
    int x,y;
    bool friend operator<(const in &a,const in &b){
        if(a.x==b.x) return a.y<b.y;
        return a.x<b.x;
    }
}p,st,en;
map<in,int>mymap;
set<in> myset;
set<in> ::iterator it;
char map1[16][16];
int sum[16*16];
bool vis[16][16];
int n,m,sx,sy,e;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
double mat1[16*16][16*16];
bool judge(int x,int y){
    if(map1[x][y]=='#'||x<0||x>=n||y<0||y>=m) return 0;
    return 1;
}
bool bfs(){
    st.x=sx,st.y=sy;
    vis[st.x][st.y]=1;
    queue<in> q;
    q.push(st);
    bool flag=0;
    myset.insert(st);
    while(!q.empty()){
        en=q.front();
        q.pop();
        myset.insert(en);
        if(map1[en.x][en.y]=='E') flag=1;
        for(int i=0;i<4;i++){
            st.x=en.x+dir[i][0];
            st.y=en.y+dir[i][1];
            if(!judge(st.x,st.y)||vis[st.x][st.y]) continue;
            vis[st.x][st.y]=1;
            q.push(st);
        }
    }
    return flag;
}
int gauss(int n){
        int i,j,k,r;
        for(i=0;i<n;i++){
            r=i;
            for(j=i+1;j<n;j++) if(fabs(mat1[j][i])>fabs(mat1[r][i])) r=j;
            if(r!=i) for(j=0;j<=n;j++) swap(mat1[r][j],mat1[i][j]);
            for(j=n;j>=i;j--)
                for(k=i+1;k<n;k++) mat1[k][j]-=mat1[k][i]/mat1[i][i]*mat1[i][j];
        }
        for(i=n-1;i>=0;i--){
            for(j=i+1;j<n;j++) mat1[i][n]-=mat1[j][n]*mat1[i][j];
            mat1[i][n]/=mat1[i][i];
        }
        return 0;
}
void init(){
    memset(mat1,0,sizeof(mat1));
    for(it=myset.begin();it!=myset.end();++it){
        int x=(*it).x;
        int y=(*it).y;
        p.x=x,p.y=y;
        mymap[p]=e++;
        for(int i=0;i<4;i++){
            int x1=x+dir[i][0];
            int y1=y+dir[i][1];
            if(!judge(x1,y1)) continue;
            sum[mymap[p]]++;
        }
    }
    for(it=myset.begin();it!=myset.end();++it){
        int x=(*it).x;
        int y=(*it).y;
        p.x=x,p.y=y;
        int id=mymap[p];
        mat1[id][id]=sum[id]+0.0;
        mat1[id][e]=sum[id]+0.00;
        for(int i=0;i<4;i++){
            int x1=x+dir[i][0];
            int y1=y+dir[i][1];
            if(!judge(x1,y1)) continue;
            if(map1[x1][y1]=='E') continue;
            p.x=x1,p.y=y1;
            int di=mymap[p];
            mat1[id][di]=-1;
        }
    }
}
void debug(){
    p.x=sx,p.y=sy;
    int id=mymap[p];
    if(dblcmp(gauss(e)+1)==0) puts("-1");
    else printf("%.2f\n",mat1[id][e]);
}
int main(){
//    freopen("test_in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF){
        mymap.clear();
        myset.clear();
        e=0;
        memset(sum,0,sizeof(sum));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%s",map1[i]);
            for(int j=0;j<m;j++) if(map1[i][j]=='S') sx=i,sy=j;
        }
        if(!bfs()){
            puts("-1");
            continue;
        }
        init();
        debug();
    }
}
/*
12 3
##E
#S.
#.E
.#.
#E#
...
..E
.##
..E
.E.
...
#E#
11 10
ES...E.#.#
E.#..#E.##
#.E..##.##
E...#E....
.E.#..#E.#
..E#.#E...
.E#.....E.
.E.#..E...
#...E..#E#
.#.###.E#.
#...E.#E..
3 2
E#
S.
.E
13 6
#ES.E.
#..E#.
E#....
.##..#
.E..#E
.#.#E.
..##E.
E..E#.
#.E#..
#E.#..
#.#.E.
....E.
E.##..
14 8
E.#E.ES#
#...E...
#E.E#...
..E.#.E.
#.E.E..#
E....###
.###..#E
..E.E.#.
.#E##.#.
#.E.####
##.##..#
E#.#E..#
.#E.E#.#
..E.E.##
7 8
##SE##..
#E.E....
.E..#.#E
.E#..E.#
E#...E..
#E.#.E#.
E#.E..E#
3 5
ES###
.E.#.
...E.
8 3
E.#
E.S
E.#
#E#
.E.
##E
.#.
E#.
5 9
##E#S#.#.
E##.#.#.#
E..#...##
.#.E.##.#
E.#.E.##E
5 11
##E##S...#.
E.#E#.E.###
#.E..#.##E.
.E##.....#.
#.##.###.E.
*/
