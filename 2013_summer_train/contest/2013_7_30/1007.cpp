#include<cstdio>
int gcd(int x,int y){
  //  printf("%d   %d  \n",x,y);
    if(x==0) return y;
    return gcd(y%x,x);
}
int main(){
    for(int n=4;n<1000;n++){
        int tmax=0;
        int flagi;
        int flagj;
        for(int i=1;i<n;i++){
            int j=n-i;
            int t1=gcd(i,j);
    //        printf("%d  %d   %d\n",i,j,t1);
            t1=(i*j)/t1;
            if(t1>tmax){
                tmax=t1;
                flagi=i;
                flagj=n-i;
            }
        }
        printf("%d   %d    %d  %d\n",n,tmax,flagi,flagj);
    }
    return 0;
}
