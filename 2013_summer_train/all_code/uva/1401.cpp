#include<cstdio>
#include<cstring>
#define M 4010
struct T{
    int root,en;
    struct E{
        int flag;
        int next[26];
    }e[M*110];
    void flash(E & e1){
        e1.flag=0;
        memset(e1.next,-1,sizeof(e1.next));
    }
    void init(){
        root=0;en=1;
        flash(e[root]);
    }
    void insert(char *p){
        int tr=root;
        for(int i=0;p[i];i++){
            int next=p[i]-'a';
            if(e[tr].next[next]==-1){
                int t2=en++;
                flash(e[t2]);
                e[tr].next[next]=t2;
            }
            tr=e[tr].next[next];
        }
        e[tr].flag++;
    }
}tr;
char str[M*100];
int dp[M*100];
int main(){
    int cas=1;
    while(~scanf("%s",str)){
        memset(dp,0,sizeof(dp));
        int n;
        char tmp[200];
        scanf("%d",&n);
        tr.init();
        for(int i=0;i<n;i++){
            scanf("%s",tmp);
            tr.insert(tmp);
        }
        dp[0]=1;
        int len=strlen(str);
        for(int i=0;i<len;i++){
            int t=0;
            for(int j=i;j<len;j++){
                int next=str[j]-'a';
                printf("%d^^^\n",next);
                if(tr.e[t].next[next]!=-1){
                    t=tr.e[t].next[next];
                    if(tr.e[t].flag){
                        printf("%d !!\n~~~~",j+1);
                        dp[j+1]+=dp[i];
                    }
                }
                else{
                    break;
                }
            }
        }
        for(int i=0;i<=len;i++){
            printf("%d ** ^^\n",dp[i]);
        }
        printf("Case %d: %d\n",cas++,dp[len]);
    }
    return 0;
}
