#include<cstdio>
#define M 300
int a[M][2];
int main(){
    int n;while(~scanf("%d",&n)){
        int tsum1=0,tsum2=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i][0],&a[i][1]);
            tsum1+=a[i][0];
            tsum2+=a[i][1];
        }
        if(tsum1%2==0&&tsum2%2==0){
            puts("0");
        }
        else{
            if(n==1){
                puts("-1");
            }
            else{
                int t1=tsum1%2+tsum2%2;
//                printf("%d!!\n",t1);
                if(t1==2){
                    puts("1");
                }
                else{
                    puts("-1");
                }
            }
        }
    }
    return 0;
}
