#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 100
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
char **f()
{
    char **map1=new char *[100];
    for(int i=0;i<10;i++)
    {
        map1[i]=new char[100];
    }
    cout<<"!!!"<<endl;
    strcpy(map1[0],"1sadfasdfasdf11");
    strcpy(map1[1],"112123241234");
    puts(map1[0]);
    puts(map1[1]);
    return map1;
}
int main()
{
    char **p;
    p=f();
    puts(p[0]);
    puts(p[1]);
    return 0;
}
