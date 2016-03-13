#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int main(){
    int x1,y1,x2,y2;
    while(~scanf("%d%d%d%d",&x1,&y1,&x2,&y2)){
        int ans1,ans2,ans3;
        if(x1==x2||y1==y2) ans1=1;
        else ans1=2;
        int t1=abs(y1-y2);
        int t2=abs(x1-x2);
        ans3=max(t1,t2);
        t1=(x1+y1)%2;
        t2=(x2+y2)%2;
        if(t1==t2){
            t1=abs(x1-x2);
            t2=abs(y1-y2);N
            if(t1==t2) ans2=1;
            else ans2=2;
        }
        else ans2=0;
        printf("%d %d %d\n",ans1,ans2,ans3);
    }
    return 0;
}
