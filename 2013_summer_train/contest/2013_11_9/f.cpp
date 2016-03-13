#include<cstdio>
#define inf 0x3f3f3f3f
#define M 10
int a[4][5]={
    1,2,3,4,5,
    1,4,3,2,5,
    1,3,2,4,5,
    1,3,4,2,5,
};
int map1[M][M];
int main(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&map1[i][j]);
        }
    }
    int tmax=inf;
    int flag=0;
    for(int i=0;i<4;i++){
        int tsum=0;
        for(int j=0;j<4;j++){
            int t1=a[i][j];
            int t2=a[i][j+1];
            tsum+=map1[t1][t2];
        }
        if(tsum<tmax){
            tmax=tsum;
            flag=i;
        }
    }
    printf("%d\n",tmax);
    for(int i=0;i<5;i++){
        if(i) printf(" %d",a[flag][i]);
        else printf("%d",a[flag][i]);
    }
    return 0;
}
/*
0 2600 3800 2600 2500
2600 0 5300 3900 4400
3800 0 0 1900 4500
2600 3900 1900 0 3700
2500 4400 4500 3700 0
*/
