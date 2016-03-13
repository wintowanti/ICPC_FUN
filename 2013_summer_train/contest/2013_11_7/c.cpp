#include<cstdio>
#include<cstring>
#include<ctime>
#include<cstdlib>
#define M 3
int b[M][M];
int a[M][M];
int o[4][2]={
    0,1,
    0,-1,
    1,0,
    -1,0
};
int n;
int judge(int x,int y){
    if(x<0||x>n-1||y<0||y>n-1) return 1;
    return 0;
}
int ju(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tsum=0;
            for(int k=0;k<4;k++){
                int x1=i+o[k][0];
                int y1=j+o[k][1];
                if(judge(x1,y1)) continue;
                if(a[x1][y1]>a[i][j]) tsum++;
            }
            if(tsum!=b[i][j]) return 0;
        }
    }
    return 1;
}
int main(){
    srand(time(NULL));
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&b[i][j]);
            }
        }
        int tt=2700000;
        int flag=0;
        while(tt--){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    a[i][j]=rand()%10;
                }
            }
            flag=ju();
            if(flag) break;
        }
        if(flag){
//            printf("%d\n",4000000-tt);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(j) printf(" %d",a[i][j]);
                    else printf("%d",a[i][j]);
                }
                puts("");
            }
        }
        else puts("NO SOLUTION");
    }
    return 0;
}
