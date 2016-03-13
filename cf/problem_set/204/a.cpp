#include<cstdio>
#include<string>
int main(){
    int n;while(~scanf("%d",&n)){
        int t1=0,t2=0;
        for(int i=0;i<n;i++){
            int tt;scanf("%d",&tt);
            if(tt==0) t1++;
            else t2++;
        }
        if(t1==0){
            puts("-1");
        }
        else{
            int t3=t2/9;
            for(int i=0;i<t3;i++){
                printf("555555555");
            }
            printf("0");
            for(int i=1;i<t1;i++){
                if(t3)
                printf("0");
            }
            puts("");
        }
    }
    return 0;
}
