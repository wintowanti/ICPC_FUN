#include<stdio.h>
#include<stack>
#include<string.h>
#include<algorithm>
using namespace std;
struct in{
    char c;
    int id;
}tt;
bool vis[1000010];
char s[1000010];
stack<in> ass;
int main(){
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        while(!ass.empty()) ass.pop();
        scanf("%s",s);
        int len=strlen(s);
        int ans=0;
        int cnt=0;
        memset(vis,1,sizeof(vis));
        for(int i=0;i<len;i++){
            tt.c=s[i];
            tt.id=i;
            if(s[i]==')'){
                if(ass.empty()){
                    ass.push(tt);
                }
                else if(ass.top().c=='('){
                    vis[ass.top().id]=0;
                    vis[tt.id]=0;
                    ass.pop();
                }
                else{
                    ass.push(tt);
                }
            }else if(s[i]==']'){
                if(ass.empty()){
                    ass.push(tt);
                }
                else if(ass.top().c=='['){
                    vis[ass.top().id]=0;
                    vis[tt.id]=0;
                    ass.pop();
                }
                else{
                    ass.push(tt);
                }
            }
            else if(s[i]=='}'){
                if(ass.empty()){
                    ass.push(tt);
                }
                else if(ass.top().c=='{'){
                    vis[ass.top().id]=0;
                    vis[tt.id]=0;
                    ass.pop();
                }
                else{
                    ass.push(tt);
                }
            }
            else ass.push(tt);
        }
//        for(int i=0;i<len;i++) printf("%d",vis[i]);
//        puts("");
        cnt=0;
        ans=0;
        for(int i=0;i<len;i++){
            if(!vis[i]) cnt++;
            else if(vis[i]==1){
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        ans=max(ans,cnt);
        printf("Case #%d: ",cas);
        if(ans==0) puts("I think H is wrong!");
        else printf("%d\n",ans);
    }
}
