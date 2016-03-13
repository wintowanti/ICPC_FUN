#include<cstdio>
int main(){
    int n;while(~scanf("%d",&n)){
        long long tsum=0;long long t1;
        for(int i=0;i<n;i++)scanf("%I64d",&t1),tsum^=t1;
        printf("%I64d\n",tsum);
    }
}
