#include<cstdio>
#include<cstring>
#include<queue>
#define M 10
using namespace std;
bool vis[M][M][M][M];
int pre[M*M*M*M][2];
int bit[M];
int o[4][2]={
    1,0,
    0,-1,
    0,1,
    -1,0,
};
int check[2][4]={
    3,2,0,1,
    1,0,2,3
};
int two[2][M][M];
int map1[30][M][M];
int judge(int x,int y){
    if(x<0||x>5||y<0||y>5) return 1;
    return 0;
}
struct E{
    int x1,y1,x2,y2,step;
};
int change(E e1){
    return e1.x1*(10*10*10)+e1.y1*(10*10)+e1.x2*10+e1.y2;
}
int is_can(E e1,int id,E & e2){
    int xx1,xx2,yy1,yy2;
    int t1=check[1][id];
    int t2=check[0][id];
    if(two[0][e1.x1][e1.y1]&bit[t1]){
        xx1=e1.x1;yy1=e1.y1;
    }
    else{
        xx1=e1.x1+o[id][0];
        yy1=e1.y1+o[id][1];
        if(two[0][xx1][yy1]&bit[t2]){
            xx1=e1.x1;
            yy1=e1.y1;
        }
    }
    if(two[1][e1.x2][e1.y2]&bit[t1]){
        xx2=e1.x2;yy2=e1.y2;
    }
    else{
        xx2=e1.x2+o[id][0];
        yy2=e1.y2+o[id][1];
        if(two[1][xx2][yy2]&bit[t2]){
            xx2=e1.x2;
            yy2=e1.y2;
        }
    }
    if(judge(xx1,yy1)) return 1;
    if(judge(xx2,yy2)) return 1;
    if(!(two[0][xx1][yy1]&bit[4])) return 1;
    if(!(two[1][xx2][yy2]&bit[4])) return 1;
    e2.x1=xx1;e2.y1=yy1;
    e2.x2=xx2;e2.y2=yy2;
    e2.step=e1.step+1;
    return 0;
}
int can_in(E e2){
    if(vis[e2.x1][e2.y1][e2.x2][e2.y2]){
        vis[e2.x1][e2.y1][e2.x2][e2.y2]=0;
        return 1;
    }
    return 0;
}
int good(E e1){
    int flag=0;
    if(two[0][e1.x1][e1.y1]&bit[6]) flag++;
    if(two[1][e1.x2][e1.y2]&bit[6]) flag++;
    if(flag==2) return 1;
    else return 0;
}
void pf(E e1){
    printf(" mark  %d   %d    %d   %d     %d   \n",e1.x1,e1.y1,e1.x2,e1.y2,e1.step);
}
queue<E> q1;
int bfs(int sx1,int sy1,int sx2,int sy2,int &tr){
    while(!q1.empty()) q1.pop();
    E e1,e2;
    memset(vis,1,sizeof(vis));
    vis[sx1][sy1][sx2][sy2]=0;
    e1.x1=sx1;e1.y1=sy1;
    e1.x2=sx2;e1.y2=sy2;
    e1.step=0;
    q1.push(e1);
    while(!q1.empty()){
        e1=q1.front();q1.pop();
//        pf(e1);
        if(good(e1)){
            tr=change(e1);
            return e1.step;
        }
        for(int i=0;i<4;i++){
            if(is_can(e1,i,e2)) continue;
            if(can_in(e2)){
                int t1=change(e1);
                int t2=change(e2);
                pre[t2][0]=t1;
                pre[t2][1]=i;
                q1.push(e2);
            }
        }
    }
    return -1;
}
void my_out(int ans,int tr){
    int ans1[M*M*M*M];
    if(ans==-1){
        puts("-1");
    }
    else{
        int len=ans;
        char str1[10];
        strcpy(str1,"DLRU");
        while(len>0){
//            printf("%d",pre[tr][1]);
            ans1[len--]=pre[tr][1];
            tr=pre[tr][0];
        }
        for(int i=1;i<=ans;i++){
            printf("%c",str1[ans1[i]]);
        }
        puts("");
    }
}
void start(){
    int sx1,sy1,sx2,sy2;
    int m=6;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(two[0][i][j]&bit[5]){
//                printf("%d   %d\n",i,j);
                sx1=i;sy1=j;
            }
            if(two[1][i][j]&bit[5]){
                sx2=i;sy2=j;
            }
        }
    }
//    printf("start is   %d   %d   %d   %d~~\n",sx1,sy1,sx2,sy2);
    int tr;
    int ans=bfs(sx1,sy1,sx2,sy2,tr);
    my_out(ans,tr);
//    printf("~~~~%d\n",ans);
}
void work(int n){
    int m=6;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                two[0][j][k]=map1[i][j][k];
                two[1][j][k]=map1[i+1][j][k];
            }
        }
        start();
    }
}
void read(int n){
    int m=6;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                scanf("%d",&map1[i][j][k]);
            }
        }
    }
    for(int i=0;i<10;i++){
        bit[i]=1<<i;
    }
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        read(n);
        work(n);
    }
    return 0;
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
