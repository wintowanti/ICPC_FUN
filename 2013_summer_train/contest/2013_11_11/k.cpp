#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int inf=10000000;
bool getgra(int n,int m,int a,int b,int c,int d){
    int a1[120][2],a2[120][2];
    memset(a1,0,sizeof(a1));memset(a2,0,sizeof(a2));
    for(int i=1;i<=n;i++){
        int t=a1[i][0];
        for(int j=1;j<=n;j++){
            if(t==a) break;
            if(j==i) continue;
            if(a1[j][0]==a) continue;
            a1[j][0]++;a1[i][0]++;t++;
        }
        t=a1[i][1];
        for(int j=1;j<=m;j++){
            if(t==b) break;
            if(a2[j][0]==c) continue;
            a2[j][0]++;a1[i][1]++;t++;
        }
    }
    for(int i=1;i<=m;i++){
        int t=a2[i][0];
        for(int j=1;j<=n;j++){
            if(t==c) break;
            if(a1[j][1]==b) continue;
            a1[j][1]++;a2[i][0]++;t++;
        }
        t=a2[i][1];
        for(int j=1;j<=m;j++){
            if(i==j) continue;
            if(t==d) break;
            if(a2[j][1]==d) continue;
            a2[i][1]++;a2[j][1]++;
        }
    }
    bool flag=0;
    for(int i=1)
    if(flag) return 1;
    return 0;
}
void cnt(int a,int b,int c,int d,int &ansn,int &ansm){
    int maxn=a+c+2;
    int maxm=b+d+2;
    for(int i=a+1;i<=maxn;i++){
        int low=1,hig=maxn,mid;
        while(low<hig){
            mid=(low+hig)/2;
            if(getgra(i,mid,a,b,c,d)) hig=mid-1;
            else low=mid;
        }
        if(getgra(i,low,a,b,c,d)&&i+low<ansn+ansm){
            ansn=i,ansm=low;
        }
    }
}
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int ansn=-1,ansm=-1;
    cnt(a,b,c,d,ansn,ansm);
    cnt(c,d,a,b,ansm,ansn);
    printf("%d %d\n",ansn,ansm);
}
