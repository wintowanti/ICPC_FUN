#include<cstdio>
#include<cmath>
#define exp 0.000000001
#define inf 0x3f3f3f3f
double a1,a2,b1,b2;
double ans(double t1){
    double t2=(t1+a2)*(t1+a2)+b2;t2=sqrt(t2);t2=t2*(2*t1+2*a1);
    double t3=(t1+a1)*(t1+a1)+b1;t3=sqrt(t3);t3=t3*(2*t1+2*a2);
    t2=t2+t3;
    if(t2>0) return 1;
    return 0;
}
double binary(double l,double r){
    double mid;
    while(r>=l+exp){
        mid=(l+r)/2;
//        printf("%.3lf   %.3lf     %.3lf\n",l,r,mid);
        if(ans(mid)){
            r=mid-exp;
        }else{
            l=mid+exp;
        }
    }
//    printf("%.3lf",mid);
    return mid;
}
int main(){
    while(~scanf("%lf%lf%lf%lf",&a1,&b1,&a2,&b2)){
        double t1=binary(-inf*10,inf*1.0);
//        printf("~~~~%.3lf\n",t1);
        double t2=(t1+a1)*(t1+a1)+b1; t2=sqrt(t2);
        double t3=(t1+a2)*(t1+a2)+b2; t3=sqrt(t3);
        t2=t2+t3;
        printf("%.3lf\n",t2);
    }
    return 0;
}
