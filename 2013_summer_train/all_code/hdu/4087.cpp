#include<cstring>
#include<cstdio>
#include<cmath>
#define M 10
#define ll __int64
#define pi 3.141592653589793
double tmp[M][M];
void pf(double ** p1,ll n,ll m){
    puts("this is begin~~~~~~~~~~~~~~~~");
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++) printf(" %.3lf",p1[i][j]);
        puts("~~");
    }
    puts("~~~~~~~~~~~~~~~end~~~~~~~~~~~~~~~~~");
}
double **new_matrix(ll n){
    double ** p1=new double *[n];
    for(ll i=0;i<n;i++){
        p1[i]=new double[n];
        for(ll j=0;j<n;j++){
            p1[i][j]=0.00;
        }
    }
    return p1;
}
double **mul(double **p1,double **p2,ll n,ll m,ll com){
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            double tsum=0.0;
            for(ll k=0;k<com;k++){
                tsum+=p1[i][k]*p2[k][j];
            }
            tmp[i][j]=tsum;
        }
    }
    for(ll i=0;i<n;i++) for(ll j=0;j<m;j++) p1[i][j]=tmp[i][j];
    return p1;
}
double ** pow(double **p1,ll n,ll time){
    double ** ans=new_matrix(n);
    for(ll i=0;i<n;i++) ans[i][i]=1.00;
    ll i=1;
    while(i<=time){
        if(i&time){
            ans=mul(ans,p1,n,n,n);
        }
        p1=mul(p1,p1,n,n,n);
        i=i<<1;
    }
    return ans;
}
char str[100];
double **tr_(double x,double y,double z){
    double ** ans=new_matrix(4);
    for(ll i=0;i<4;i++) ans[i][i]=1.00;
    ans[3][0]=x;ans[3][1]=y;ans[3][2]=z;
    return ans;
}
double ** ro_(double x,double y,double z,double o){
    o=(-o*pi)/180.00;
    double **ans=new_matrix(4);
    double tsum=x*x+y*y+z*z;
    tsum=sqrt(tsum);
    x/=tsum;y/=tsum;z/=tsum;
    double coso=cos(o);
    double sino=sin(o);
    ans[0][0]=x*x+(1-x*x)*coso;    ans[0][1]=x*y*(1-coso)-z*sino;   ans[0][2]=x*z*(1-coso)+y*sino;
    ans[1][0]=y*x*(1-coso)+z*sino; ans[1][1]=y*y+(1-y*y)*coso;      ans[1][2]=y*z*(1-coso)-x*sino;
    ans[2][0]=z*x*(1-coso)-y*sino; ans[2][1]=z*y*(1-coso)+x*sino;   ans[2][2]=z*z+(1-z*z)*coso;
    ans[3][3]=1.00;
    return ans;
}
double **s_(double x,double y,double z){
    double **ans=new_matrix(4);
    ans[0][0]=x;ans[1][1]=y;ans[2][2]=z;ans[3][3]=1.00;
    return ans;
}
double **work(ll time){
    double **tr;tr=new_matrix(4);for(ll i=0;i<4;i++) tr[i][i]=1.0;
    while(1){
        scanf("%s",str);
        double **p1;
        if(str[0]=='r'){
            if(str[1]=='e'){
                ll time1;
                    scanf("%I64d",&time1);
                p1=work(time1);
            }
            else if(str[1]=='o'){
                double t1,t2,t3,o;scanf("%lf%lf%lf%lf",&t1,&t2,&t3,&o);
                p1=ro_(t1,t2,t3,o);
            }
        }
        else if(str[0]=='t'){
                double t1,t2,t3;scanf("%lf%lf%lf",&t1,&t2,&t3);
                p1=tr_(t1,t2,t3);
        }
        else if(str[0]=='s'){
            double t1,t2,t3;scanf("%lf%lf%lf",&t1,&t2,&t3);
            p1=s_(t1,t2,t3);
//             puts("p1 is the\n");
//            pf(p1,4,4);
        }
        else if(str[0]=='e'){
//            pf(tr,4,4);
            tr=pow(tr,4,time);
//            pf(tr,4,4);
            return tr;
        }
        tr=mul(tr,p1,4,4,4);
//        puts("*******************************");
     //   pf(tr,4,4);
    }
}
int main(){
    ll n;
    while(~scanf("%I64d",&n)&&n){
//        printf("!!!!!!!!!!\n");
        double **tr=work(1);
        double **ans=new_matrix(4);
//        pf(tr,4,4);
        for(ll i=0;i<n;i++){
            scanf("%lf%lf%lf",&ans[0][0],&ans[0][1],&ans[0][2]);
//            printf("%.3lf %.3lf %.3lf\n",ans[0][0],ans[0][1],ans[0][2]);
            ans[0][3]=1.00;
            ans=mul(ans,tr,1,4,4);
            for(int i=0;i<3;i++){
                if(ans[0][i]<0.0001&&ans[0][i]>-0.0001) ans[0][i]=0.00;
            }
            printf("%.2lf %.2lf %.2lf\n",ans[0][0],ans[0][1],ans[0][2]);
        }
        puts("");
    }
    return 0;
}
/*
2
repa  100000000
rotate 1.0 1.0 1.0 90.0
translate 2.0 2.0 2.0
end
end;
1.0 1.0 1.0
1.0 0.0 0.0
*/
