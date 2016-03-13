#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<algorithm>
#define M 10008
#define N 108
using namespace std;
struct E
{
    int u,v,next;
    double c;
}e[M];
int head[M];
int g;
void init()
{
    memset(head,-1,sizeof(head));
    g=0;
}
void add(int u,int v,double c)
{
    e[g].u=u,e[g].v=v,e[g].c=c;

}
int main()
{
    return 0;
}
