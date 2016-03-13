#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#define M 100
#define eps 0.0000001
using namespace std;
struct G{
    double a[M][M];
    double ans[M];
    bool free[M];
    void debug(int equ,int var){
        for(int i=0;i<equ;i++){
            for(int j=0;j<var+1;j++){
                printf("%lf  ",a[i][j]);
            }
            puts(" ");
        }
    }
    int work(int equ,int var){
        int k;
        int max_r;
        int col;
        for(int i=0;i<=var;i++){
            free[i]=1;
            ans[i]=0.00;
        }
//        puts("~~~~~");
        debug(2,2);
        for(k=0,col=0;k<equ,col<var;k++,col++){
            printf("%d^^  %d^\n",k,col);
            max_r=k;
            for(int i=k+1;i<equ;i++){
                if(abs(a[i][col])>abs(a[max_r][col])){
                    max_r=i;
                }
            }
            for(int i=0;i<var+1;i++){
                swap(a[k][i],a[max_r][i]);
            }
            if(abs(a[k][col])<eps){
                k--;
                continue;
            }
            for(int i=k+1;i<equ;i++){
                if(abs(a[i][col])>eps){
                    double x1=a[k][col];
                    double x2=a[i][col];
                    double x3=x2/x1;
                    for(int j=col;j<var+1;j++){
                        a[i][j]-=a[k][j]*x3;
                    }
                }
            }
        }
//        printf("~~~~~~~~");
        debug(equ,var);
        printf("%d  %d  ~~~\n",k,col);
        for(int i=k;i<equ;i++){
            if(abs(a[i][col])>eps) return -1;
        }
        if(k<var){
            for(int i=k-1;i>=0;i--){
                int free_num=0;
                int free_index=1000000;
                for(int j=0;j<var;j++){
                    if(free[j]==0) continue;
                    if(abs(a[i][j])<eps) continue;
                    free_num++;
                    free_index=j;
                }
                if(free_num>1) continue;
                double tmp=a[i][var];
                for(int j=0;j<var;j++){
                    if(abs(a[i][j])<eps) continue;
                    if(j==free_index) continue;
                    tmp-=a[i][j]*ans[j];
                }
                ans[free_index]=tmp/a[i][free_index];
                free[free_index]=0;
            }
            return var-k;
        }
        for(int i=var-1;i>=0;i--){
            double tmp=a[i][var];
            for(int j=i+1;j<var;j++){
                tmp-=a[i][j]*ans[j];
            }
            ans[i]=tmp/a[i][i];
        }
        return 8;
    }
}g1;
int main(){
    g1.a[0][0]=1;g1.a[0][1]=1;g1.a[0][2]=3;
    g1.a[1][0]=1;g1.a[1][1]=1;g1.a[1][2]=3;
    int t1=g1.work(2,2);
    for(int i=0;i<2;i++){
        printf("%lf~~~~\n",g1.ans[i]);
    }
    printf("%d\n",t1);
    return 0;
}
