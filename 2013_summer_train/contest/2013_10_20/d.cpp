#include<cstdio>
int main(){
    int n;while(~scanf("%d",&n)){
        if(n<=14){
            puts("-1");
        }
        else{
            int ans=n/14;
            int t1=n%14;
            if(ans==1){
                if(t1==7){
                    puts("1");
                }
                else{
                    puts("-1");
                }
            }
            else{
                if(t1<=12){
                    if(t1==1||t1==0){
                        puts("-1");
                    }
                    else
                    printf("%d\n",ans);
                }
                else{
                    puts("-1");
                }
            }
        }
    }
}
