#include<cstdio>
#include<cstring>
#include<iostream>
#define M 4000
using namespace std;
int a[M][2];
int b[M];
int judge(int x,int y){
    int x1=a[x][0];
    int x2=a[x][1];
    if(x1>x2) swap(x1,x2);
    int y1=a[y][0];
    int y2=a[y][1];
    if(y1>y2) swap(y1,y2);
    if(x1>y1&&x1<y2&&x2>y2) return 1;
    if(y1>x1&&y1<x2&&y2>x2) return 1;
    return 0;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);
        }
        for(int i=0;i<n-1;i++){
            a[i][0]=b[i];
            a[i][1]=b[i+1];
        }
        int flag=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n-1;j++){
                if(judge(i,j)) flag=1;
            }
        }
        if(flag) puts("yes");
        else puts("no");
    }
    return 0;
}
