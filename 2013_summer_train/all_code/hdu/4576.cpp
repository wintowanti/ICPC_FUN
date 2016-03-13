#include<cstdio>
#include<cstring>
#define M 205
double tmp[M][M];
double ** ans11;
double **new_matrix(int n){
    double **p1;p1=new double *[n];
    for(int i=0;i<n;i++) p1[i]=new double[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) p1[i][j]=0.00;
    }
    return p1;
}
double ** mul(double **p1,double **p2,int n,int m,int com){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            double tsum=0;
            for(int k=0;k<com;k++){
                tsum+=p1[i][k]*p2[k][j];
            }
            tmp[i][j]=tsum;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            p1[i][j]=tmp[i][j];
        }
    }
    return p1;
}
double **good_mul(double **p1,double **p2,int n,int m,int com){
    for(int i=0;i<m;i++){
        double tsum=0.00;
        for(int j=0;j<com;j++){
            tsum+=p1[0][j]*p2[j][i];
        }
        tmp[0][i]=tsum;
    }
    for(int i=0;i<n;i++){
       if(i==0){
            for(int j=0;j<m;j++){
                p1[i][j]=tmp[i][j];
            }
        }
        else{
            for(int j=1;j<m;j++){
                p1[i][j]=p1[i-1][j-1];
            }
            p1[i][0]=p1[i-1][m-1];
        }
    }
    return p1;
}
double **pow(double **p1,int n,int time){
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) ans11[i][j]=0.00;
//    double ** ans11=new_matrix(n);
    for(int i=0;i<n;i++) ans11[i][i]=1.00;
    int i=1;
    while(i<=time){
        if(i&time){
            ans11=good_mul(ans11,p1,n,n,n);
        }
        i=i<<1;
        p1=good_mul(p1,p1,n,n,n);
    }
    return ans11;
}
void pf(double **p1,int n,int m){
//    puts("~~~~~~~~~~~~~begin~~~~~~~~~~~~~~");
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            printf("%.3lf  ",p1[i][j]);
//        }
//        puts("");
//    }
//    puts("~~~~~~~~~~~~~~end~~~~~~~~~~~~~~~~~~~");
}
int num[M/2];
int main(){
    int n,m,l,r;
    while(~scanf("%d%d%d%d",&n,&m,&l,&r)&&(n+m+l+r)){
        memset(num,0,sizeof(num));
        for(int i=0;i<m;i++){
            int t1;scanf("%d",&t1);
            t1=t1%n;num[t1]++;
        }
        ans11=new_matrix(n);
        double **ans=new_matrix(n);ans[0][0]=1.00;
        pf(ans,1,n);
        double **tr=new_matrix(n); for(int i=0;i<n;i++) tr[i][i]=1.00;
        double **tr1=new_matrix(n);
        for(int i=1;i<n;i++){
            if(num[i]>0){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                        tr1[j][k]=0.00;
                    }
                }
                for(int j=0;j<n;j++){
                    int t1=(j+i)%n;
                    int t2=(j-i+n)%n;
                    tr1[j][t1]+=0.50;
                    tr1[j][t2]+=0.50;
                }
                pf(tr1,n,n);
                tr1=pow(tr1,n,num[i]);
                pf(tr1,n,n);
                tr=good_mul(tr,tr1,n,n,n);
            }
        }
        ans=mul(ans,tr,1,n,n);
        pf(ans,1,n);
        double tsum=0.000;
        for(int i=l-1;i<r;i++){
            tsum+=ans[0][i];
        }
        printf("%.4lf\n",tsum);
    }
    return 0;
}
/*
3 1 1 3
1
1
*/
