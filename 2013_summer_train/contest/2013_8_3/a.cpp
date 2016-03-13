#include<cstdio>
#include<map>
#include<string>
#include<cstring>
using namespace std;
map<string,int> map1;
double tmp[3];
int num[200];
void pf(double tsum){
    double flag=1.0;
    for(int i=1;i<=100;i++){
        if(num[i]){
            flag*=i*num[i];
        }
        if(flag>tsum) break;
    }
//    printf("%lf   %lf\n",tsum,flag);
    tsum=tsum/flag;
    if(tsum<tmp[0]){
        puts("Slideshow");
    }
    else if(tsum>=tmp[1]){
        puts("Perfect");
    }
    else{
        puts("So-so");
    }
}
int main(){
    int n;
    double w,h,p,tsum;
    while(~scanf("%dn",&n)){
        tmp[0]=10.00;
        tmp[1]=60.00;
        map1.clear();
        tsum=1.0000;
        double t3=1.0;
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++){
            char str[30];
            int t1;
            scanf("%s%d",str,&t1);
            map1[str]=t1;
            num[t1]++;
        }
        scanf("%lf%lf%lf",&w,&h,&p);
        tsum=(p*tsum)/(w*h);
        pf(tsum);
        int m;scanf("%d",&m);
        for(int i=0;i<m;i++){
            char str[20];
            scanf("%s",str);
            if(str[1]=='n'){
                scanf("%s",str);
                int t1=map1[str];
                num[t1]++;
            }
            else if(str[1]=='f'){
                scanf("%s",str);
                int t1=map1[str];
                num[t1]--;
            }
            else{
                double w1,h1;scanf("%lf%lf",&w1,&h1);
                tsum=tsum*(w)/w1;
                tsum=tsum*(h)/h1;
                w=w1;h=h1;
            }
            pf(tsum);
        }
    }
    return 0;
}
/*
1
vsync 100000
640 480 10000000
2
Off vsync
Resolution 320 240
*/
