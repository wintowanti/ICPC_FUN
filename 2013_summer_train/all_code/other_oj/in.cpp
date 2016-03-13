#include<cstdio>
int main(){
    int n=200000;
    freopen("in.txt","w",stdout);
    printf("%d  %d\n",n,n/2);
    for(int i=0;i<n-1;i++){
        printf("%d %d %d \n",i,i+1,1);
    }
}
