#include<cstdio>
#define M 100
int a[M][3];
int main(){
    int n,m,t;
    while(~scanf("%d%d%d",&n,&m,&t)){
        double tsum=0;
        for(int i=0;i<t;i++){
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        }
        for(int i=0;i<t;i++){
            if(a[i][1]*n<a[i][0]){
                tsum+=a[i][2]*(a[i][0]-a[i][1]*n);
            }
        }
        tsum=tsum/n;
        printf("%.3lf\n",tsum);
    }
    return 0;
}
/*
2 3 2
3 1 2
3 2 2
*/
