#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int dir1[8][2]={0,1,0,-1,1,1,1,-1,1,0,-1,0,-1,1,-1,-1};
int dir2[8][2]={1,-2,-1,-2,1,2,-1,2,2,1,2,-1,-2,1,-2,-1};
int n;
bool judge(int x,int y){
    if(x<1||x>n||y<1||y>n) return 0;
    return 1;
}
int main(){
    scanf("%d",&n);
    int x,y;
    scanf("%d%d",&x,&y);
    int r,king=0,kn=0,q,b;
    r=n*2-2;
    for(int i=0;i<8;i++){
        int x1=x+dir1[i][0];
        int y1=y+dir1[i][1];
        if(judge(x1,y1)) king++;
    }
    for(int i=0;i<8;i++){
        int x1=x+dir2[i][0];
        int y1=y+dir2[i][1];
        if(judge(x1,y1)) kn++;
    }
    b=min(x,y)*2-2+n-1;
    q=r+b;
    printf("King: %d\n",king);
    printf("Knight: %d\n",kn);
    printf("Bishop: %d\n",b);
    printf("Rook: %d\n",r);
    printf("Queen: %d\n",q);
}
