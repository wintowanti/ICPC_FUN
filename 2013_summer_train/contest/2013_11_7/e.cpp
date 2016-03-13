#include<cstdio>
#include<cstring>
int num[10];
char str[10];
int main(){
    int m,n;while(~scanf("%d%d",&m,&n)){
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++){
            scanf("%s",str);
            int t1=str[0]-'0';
            num[t1]++;
        }
        int ans=2;
        for(int i=0;i<10;i++){
            if(num[i]){
                ans+=(num[i]+m-1)/m;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
