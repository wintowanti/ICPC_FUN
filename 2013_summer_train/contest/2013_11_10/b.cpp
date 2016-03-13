#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
    int t;scanf("%d",&t);
    while(t--){
        double sy,ey,sm,em;
        scanf("%lf%lf%lf%lf",&sm,&sy,&em,&ey);
        double ans=0.000;
        if(sy==ey){
            ans+=(em-sm)*0.5/(12.00-sm+1.00);
        }else{
            ans+=ey-sy+(em-1.00)/12.00-0.5;
        }
        ans=round(ans*10000.000);
        printf("%.4lf\n",ans/10000.00);
    }
}
