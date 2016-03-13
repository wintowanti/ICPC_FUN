#include<cstdio>
#include<cstring>
#define M 500
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<3];
    void init(){
        en=0;
        memset(head,-1,sizeof(head));
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int vis[M],cat[M];
int crosspath(int u){
    for(int i=g1.head[u];i!=-1;i=g1.e[i].next){
        int v=g1.e[i].v;
        if(vis[v]){
            vis[v]=0;
            if(cat[v]==-1||crosspath(cat[v])){
                cat[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int hungary(int n){
    memset(cat,-1,sizeof(cat));
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(vis,-1,sizeof(vis));
        if(crosspath(i)){
//            puts("~~~~");
            ans++;
        }
    }
    return ans;
}
char str[M];
char str1[M<<2];
int num[M];
int main(){
    int n;
    while(~scanf("%d",&n)){
        scanf("%s",str);
        str1[0]='*';
        int j=1;
        for(int i=0;str[i];i++){
            if(str[i]=='S'){
                str1[j++]='S';
                str1[j++]='*';
            }
            else if(str[i]=='L'){
                str1[j++]='L';
                str1[j++]='L';
                str1[j++]='*';
                i++;
            }
        }
        str1[j]='\0';
//        puts(str1);
        int en1=1,en2=1;
        for(int i=0;str1[i];i++){
            if(str1[i]!='*'){
                num[i]=en1++;
            }
            else{
                num[i]=en2++;
            }
        }
        g1.init();
        for(int i=0;str1[i];i++){
            if(str1[i]!='*'){
                int t1=num[i];
                if(i-1>=0){
                    if(str1[i-1]=='*'){
                        g1.add(num[i],num[i-1]);
                    }
                }
                if(str1[i+1]=='*'){
                    g1.add(num[i],num[i+1]);
                }
            }
        }
//        for(int i=0;i<g1.en;i++){
//            printf("%d  %d~~~~\n",g1.e[i].u,g1.e[i].v);
//        }
        int ans=hungary(en1-1);
        printf("%d\n",ans);
    }
    return 0;
}
/*
4
SLLLL
*/
