#include<cstdio>
#include<cstring>
#define M 1000000
char str[M];
char ans[M];
int main(){
    while(~scanf("%s",str)){
        int flag=0;
        int j=-1;
        for(int i=0;str[i];i++){
            if(j<2){
                int t1=str[i];
                if(j==1){
                    if(t1==str[j]&&t1==str[j-1]) continue;
                    ans[++j]=t1;
                }else ans[++j]=t1;
//                ans[++j]=str[i];
            }
            else{
                char t1=str[i];
                if(ans[j]==t1){
                    if(ans[j-1]==ans[j]) continue;
                    else if(ans[j-1]==ans[j-2]) continue;
                    else ans[++j]=t1;
                }
                else ans[++j]=t1;
            }
        }
        for(int i=0;i<=j;i++) printf("%c",ans[i]);
        puts("");
    }
    return 0;
}
