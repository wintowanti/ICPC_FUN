#include<cstdio>
#include<cstring>
#include<iostream>
#define inf 0x3f3f3f3f
#define M 500000
using namespace std;
int a[M];
int b[M];
int sum1[M];
int sum2[M];
int binary1(int l,int r,int k,int d){
    int tmax=0;
    while(r>=l){
        int mid=(l+r)>>1;
        if(k-a[mid]>=d){
            tmax=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return tmax;
}
int binary2(int l,int r,int k,int d){
    int tmin=r;
    while(r>=l){
        int mid=(l+r)>>1;
        if(a[mid]-k>=d){
            tmin=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return tmin;
}
int main(){
    int n,d;
    while(~scanf("%d%d",&n,&d)){
        a[0]=-inf;a[n+1]=inf;
        b[0]=b[n+1]=-inf;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i],&b[i]);
        }
        memset(sum1,-inf,sizeof(sum1));
        memset(sum2,-inf,sizeof(sum2));
        sum1[0]=-inf;
        for(int i=1;i<=n+1;i++){
            sum1[i]=max(sum1[i-1],b[i]);
        }
        sum2[n+1]=-inf;
        for(int i=n;i>=0;i--){
            sum2[i]=max(sum2[i+1],b[i]);
        }
        int flag1=-1,flag2=-1;
        int tmax=-inf;
        for(int i=1;i<=n;i++){
            int id1=binary1(0,i-1,a[i],d);
            if(b[i]+sum1[id1]>tmax){
                tmax=b[i]+sum1[id1];
                flag1=i;
                flag2=id1;
            }
            int id2=binary2(i+1,n+1,a[i],d);
            if(b[i]+sum2[id2]>tmax){
                tmax=b[i]+sum2[id2];
                flag1=i;
                flag2=id2;
            }
//            printf("%d   %d \n",id1,id2);
        }
//        printf("***%d\n",tmax);
        if(tmax<0){
            puts("-1 -1");
        }
        else{
            printf("%d %d\n",flag1,flag2);
        }
    }
    return 0;
}
/*
6 1
1 1
3 5
4 8
6 4
10 3
11 2
*/
