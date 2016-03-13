#include<cstdio>
int main(){
    int cas;
    while(~scanf("%d",&cas)){
        while(cas--){
            int n;int t1;scanf("%d%d",&n,&t1);
            char str1[100];
            for(int i=0;i<n;i++) scanf("%s",str1);
            if(t1) puts("lolanv");
            else puts("wind");
        }
    }
    return 0;
}
