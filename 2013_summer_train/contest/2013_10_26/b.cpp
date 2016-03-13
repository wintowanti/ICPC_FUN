#include<cstdio>
#include<cstring>
#define M 30000
int a[M];
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        int tsum1=0,tsum2=0;
        for(int i=0;i<n;i++){
            int t1;scanf("%d",&a[i]);
            if(a[i]>=m){
                tsum1+=a[i]-m;
            }
            else{
                tsum2+=m-a[i];
            }
        }
        printf("%d %d\n",tsum1,tsum2);
    }
    return 0;
}
