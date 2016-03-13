#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int vis[9][9][9][9];
int const M = 908;
struct node33 {
int l,d,r,u;
int st,en,ho;
}mp[25][9][9];
struct node {
int x1,y1,step;
int x2,y2;
int fa;
int cm;
}q[M];
int stt[M];
int judge(int x,int y){
if(x<1||x>6||y<1||y>6) return 0;
return 1;
}
int hehe(int l,int r,node p){
if(mp[l][p.x1][p.y1].ho==1||mp[r][p.x2][p.y2].ho==1) return 0;
return 1;
}
void bfs(int l,int r,int x1,int y1,int x2,int y2){
memset(vis,0,sizeof(vis));
node t;
t.x1=x1;
t.x2=x2;
t.y1=y1;
t.y2=y2;
t.step=0;
t.cm=-1;
t.fa=-1;
int head=1,rear=0;
q[head++]=t;
vis[x1][y1][x2][y2]=1;
while(rear<head){
node p=q[rear++];
if(mp[l][p.x1][p.y1].en==1&&mp[r][p.x2][p.y2].en==1){
    int o=0;
    stt[o++]=p.cm;
    int ll=p.fa;
    while(1){
        if(ll==-1) break ;
        stt[o++]=q[ll].cm;
        ll=q[ll].fa;
    }
    while(o--){
     if(stt[o]==3) putchar('U');
     if(stt[o]==2) putchar('R');
     if(stt[o]==1) putchar('L');
     if(stt[o]==0) putchar('D');
    }
    printf("\n");
    return ;
}
for(int i=0;i<4;i++){
    if(i==1){
        if(mp[l][p.x1][p.y1].l==1&&mp[r][p.x2][p.y2].l==1) continue;
        else if(judge(p.x2,p.y2-1)&&mp[l][p.x1][p.y1].l==1&&mp[r][p.x2][p.y2].l!=1&&!vis[p.x1][p.y1][p.x2][p.y2-1]){
            node k;
            k.x1=p.x1;
            k.y1=p.y1;
            k.x2=p.x2;
            k.y2=p.y2-1;
            k.step=p.step+1;
            k.cm=1;
            k.fa=rear-1;
            if(hehe(l,r,k)==0) continue;
            q[head++]=k;
            vis[k.x1][k.y1][k.x2][k.y2]=1;
        }
       else if(judge(p.x1,p.y1-1)&&mp[l][p.x1][p.y1].l!=1&&mp[r][p.x2][p.y2].l==1&&!vis[p.x1][p.y1-1][p.x2][p.y2]){
            node k;
            k.x1=p.x1;
            k.y1=p.y1-1;
            k.x2=p.x2;
            k.y2=p.y2;
            k.step=p.step+1;
            k.cm=1;
            k.fa=rear-1;
            if(hehe(l,r,k)==0) continue;
            q[head++]=k;
            vis[k.x1][k.y1][k.x2][k.y2]=1;
        }
        else if(judge(p.x1,p.y1-1)&&judge(p.x2,p.y2-1)&&mp[l][p.x1][p.y1].l!=1&&mp[r][p.x2][p.y2].l!=1&&!vis[p.x1][p.y1-1][p.x2][p.y2-1]){
            node k;
            k.x1=p.x1;
            k.y1=p.y1-1;
            k.x2=p.x2;
            k.y2=p.y2-1;
            k.step=p.step+1;
            k.cm=1;
            k.fa=rear-1;
            if(hehe(l,r,k)==0) continue;
            q[head++]=k;
            vis[k.x1][k.y1][k.x2][k.y2]=1;
        }
    }

     if(i==0){
        if(mp[l][p.x1][p.y1].d==1&&mp[r][p.x2][p.y2].d==1) continue;
        else if(judge(p.x2+1,p.y2)&&mp[l][p.x1][p.y1].d==1&&mp[r][p.x2][p.y2].d!=1&&!vis[p.x1][p.y1][p.x2+1][p.y2]){
            node k;
            k.x1=p.x1;
            k.y1=p.y1;
            k.x2=p.x2+1;
            k.y2=p.y2;
            k.step=p.step+1;
            k.cm=0;
            k.fa=rear-1;
            if(hehe(l,r,k)==0) continue;
            q[head++]=k;
            vis[k.x1][k.y1][k.x2][k.y2]=1;
        }
       else if(judge(p.x1+1,p.y1)&&mp[l][p.x1][p.y1].d!=1&&mp[r][p.x2][p.y2].d==1&&!vis[p.x1+1][p.y1][p.x2][p.y2]){
            node k;
            k.x1=p.x1+1;
            k.y1=p.y1;
            k.x2=p.x2;
            k.y2=p.y2;
            k.step=p.step+1;
            k.cm=0;
            k.fa=rear-1;
            if(hehe(l,r,k)==0) continue;
            q[head++]=k;
            vis[k.x1][k.y1][k.x2][k.y2]=1;
        }
        else if(judge(p.x1+1,p.y1)&&judge(p.x2+1,p.y2)&&mp[l][p.x1][p.y1].d!=1&&mp[r][p.x2][p.y2].d!=1&&!vis[p.x1+1][p.y1][p.x2+1][p.y2]){
            node k;
            k.x1=p.x1+1;
            k.y1=p.y1;
            k.x2=p.x2+1;
            k.y2=p.y2;
            k.step=p.step+1;
            k.cm=0;
            k.fa=rear-1;
            if(hehe(l,r,k)==0) continue;
            q[head++]=k;
            vis[k.x1][k.y1][k.x2][k.y2]=1;
        }
    }

    if(i==2){
        if(mp[l][p.x1][p.y1].r==1&&mp[r][p.x2][p.y2].r==1) continue;
        else if(judge(p.x2,p.y2+1)&&mp[l][p.x1][p.y1].r==1&&mp[r][p.x2][p.y2].r!=1&&!vis[p.x1][p.y1][p.x2][p.y2+1]){
            node k;
            k.x1=p.x1;
            k.y1=p.y1;
            k.x2=p.x2;
            k.y2=p.y2+1;
            k.step=p.step+1;
            k.cm=2;
            k.fa=rear-1;
            if(hehe(l,r,k)==0) continue;
            q[head++]=k;
            vis[k.x1][k.y1][k.x2][k.y2]=1;
        }
       else if(judge(p.x1,p.y1+1)&&mp[l][p.x1][p.y1].r!=1&&mp[r][p.x2][p.y2].r==1&&!vis[p.x1][p.y1+1][p.x2][p.y2]){
            node k;
            k.x1=p.x1;
            k.y1=p.y1+1;
            k.x2=p.x2;
            k.y2=p.y2;
            k.step=p.step+1;
            k.cm=2;
            k.fa=rear-1;
            if(hehe(l,r,k)==0) continue;
            q[head++]=k;

            vis[k.x1][k.y1][k.x2][k.y2]=1;
        }
        else if(judge(p.x1,p.y1+1)&&judge(p.x2,p.y2+1)&&mp[l][p.x1][p.y1].r!=1&&mp[r][p.x2][p.y2].r!=1&&!vis[p.x1][p.y1+1][p.x2][p.y2+1]){
            node k;
            k.x1=p.x1;
            k.y1=p.y1+1;
            k.x2=p.x2;
            k.y2=p.y2+1;
            k.step=p.step+1;
            k.cm=2;
            k.fa=rear-1;
            if(hehe(l,r,k)==0) continue;
            q[head++]=k;

            vis[k.x1][k.y1][k.x2][k.y2]=1;
        }
    }

     if(i==3){
        if(mp[l][p.x1][p.y1].u==1&&mp[r][p.x2][p.y2].u==1) continue;
        else if(judge(p.x2-1,p.y2)&&mp[l][p.x1][p.y1].u==1&&mp[r][p.x2][p.y2].u!=1&&!vis[p.x1][p.y1][p.x2-1][p.y2]){
            node k;
            k.x1=p.x1;
            k.y1=p.y1;
            k.x2=p.x2-1;
            k.y2=p.y2;
            k.step=p.step+1;
            k.cm=3;
            k.fa=rear-1;
            if(hehe(l,r,k)==0) continue;
            q[head++]=k;

            vis[k.x1][k.y1][k.x2][k.y2]=1;
        }
       else if(judge(p.x1-1,p.y1)&&mp[l][p.x1][p.y1].u!=1&&mp[r][p.x2][p.y2].u==1&&!vis[p.x1-1][p.y1][p.x2][p.y2]){
            node k;
            k.x1=p.x1-1;
            k.y1=p.y1;
            k.x2=p.x2;
            k.y2=p.y2;
            k.step=p.step+1;
            k.cm=3;
            k.fa=rear-1;
            if(hehe(l,r,k)==0) continue;
            q[head++]=k;

            vis[k.x1][k.y1][k.x2][k.y2]=1;
        }
        else if(judge(p.x1-1,p.y1)&&judge(p.x2-1,p.y2)&&mp[l][p.x1][p.y1].u!=1&&mp[r][p.x2][p.y2].u!=1&&!vis[p.x1-1][p.y1][p.x2-1][p.y2]){
            node k;
            k.x1=p.x1-1;
            k.y1=p.y1;
            k.x2=p.x2-1;
            k.y2=p.y2;
            k.step=p.step+1;
            k.cm=3;
            k.fa=rear-1;
            if(hehe(l,r,k)==0) continue;
            q[head++]=k;
            vis[k.x1][k.y1][k.x2][k.y2]=1;
        }
    }
  }
}
puts("-1");
}
int main(){
int n;

while(cin>>n){
int a;
int stx,sty,enx,eny;
for(int i=1;i<=6;i++){
    for(int j=1;j<=6;j++){
        scanf("%d",&a);
        int k=0;
                int hj=(a)&1;
                if(hj==1){
                    mp[1][i][j].l=1;
                }
                k++;
                hj=(a>>(k))&1;
                if(hj==1){
                    mp[1][i][j].d=1;
                }
                k++;
                hj=(a>>(k))&1;
                if(hj==1){
                    mp[1][i][j].r=1;
                }
                 k++;
                hj=(a>>(k))&1;
                if(hj==1){
                    mp[1][i][j].u=1;
              }
               k++;
                hj=(a>>(k))&1;
                if(hj==0){
                    mp[1][i][j].ho=1;
                }
                k++;
                hj=(a>>(k))&1;
                if(hj==1){
                    mp[1][i][j].st=1;
                    stx=i,sty=j;
                }
                 k++;
                hj=(a>>(k))&1;
                if(hj==1){
                    mp[1][i][j].en=1;
                }
    }
}
for(int p=2,i,j;p<=n;p++){
    for(i=1;i<=6;i++){
     for(j=1;j<=6;j++){
        scanf("%d",&a);
        int k=0;
                int hj=(a>>k)&1;
                if(hj==1){
                    mp[p][i][j].l=1;
                }
                k++;
                hj=(a>>(k))&1;
                if(hj==1){
                    mp[p][i][j].d=1;
                }
                k++;
                hj=(a>>(k))&1;
                if(hj==1){
                    mp[p][i][j].r=1;
                }
                 k++;
                hj=(a>>(k))&1;
                if(hj==1){
                    mp[p][i][j].u=1;
               }
                k++;
                hj=(a>>(k))&1;
                if(hj==0){
                    mp[p][i][j].ho=1;
                }
                 k++;
                 hj=(a>>(k))&1;
                if(hj==1){
                    mp[p][i][j].st=1;
                    enx=i,eny=j;

                }
                 k++;
                hj=(a>>(k))&1;
                if(hj==1){
                   mp[p][i][j].en=1;
                }
    }

}
      bfs(p-1,p,stx,sty,enx,eny);
      stx=enx,sty=eny;
}
}
/*
2
16 0 18 16 18 24
20 19 24 20 29 1
18 28 17 16 22 17
8 20 1 18 24 20
19 80 48 24 16 0
24 16 16 16 22 19

18 16 18 16 18 80
24 18 24 16 24 18
18 24 0 0 18 24
24 18 0 0 24 18
18 24 18 16 18 24
56 18 24 18 24 18
*/
return 0;
}
