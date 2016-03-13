#include<cstdio>
int main(){
    int cas;while(~scanf("%d",&cas)){
        for(int q=1;q<=cas;q++){
            double x,y,t,s;
            scanf("%lf%lf%lf%lf",&x,&y,&t,&s);
            printf("Case #%d: ",q);
            if(y>=x){
                double ans=(s/x);
                printf("%.3lf\n",ans);
                continue;
            }
            double ans=t;
            while(1){
                double yu=(ans*y);
                double t1=yu/(x-y);
                if(x*t1>=s){
                    ans=ans+s/x;
                    break;
                }
                else{
                    ans+=t1;
                }
            }
            printf("%.3lf\n",ans-t);
        }
    }
    return 0;
}
