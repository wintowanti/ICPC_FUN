#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
#include<map>
#define M 20
using namespace std;
char str[M];
map<string,int> map1;
struct E{
    char str[M];
    int step;
    int num;
    friend bool operator <(const E a,const E b){
        if(a.step>=b.step) return 1;return 0;
    }
};
int judge(char *p){
    int i=0;
    int j=strlen(p)-1;
    for(;i<j;i++,j--){
        if(p[i]!=p[j]) return 0;
    }
    return 1;
}
priority_queue<E> q1;
int bfs(char *p){
    map1.clear();
    while(!q1.empty()) q1.pop();
    map1[p]=1;
    E e1,e2;
    strcpy(e1.str,p);
    e1.step=0;
    e1.num=strlen(e1.str);
    q1.push(e1);
    while(!q1.empty()){
        e1=q1.top();q1.pop();
//        printf("%s   %d!!!!\n",e1.str,e1.step);
        if(e1.str[0]=='\0') return e1.step;
        bool vis[200];
        memset(vis,0,sizeof(vis));
        int flag=0;
        for(int i=0;i<e1.num;i++){
            int t1=e1.str[i];
//            printf("!!!%d    %d\n",t1,vis[t1]);
            if(vis[t1]==0){
                vis[t1]=1;
                flag++;
            }
        }
        if(flag==e1.num){
//            printf("%d    %d\n",flag,e1.num);
//            puts("&&&&&&&&&");
            e2.str[0]='\0';
            e2.step=e1.step+e1.num;
            q1.push(e2);
            continue;
        }
        for(int i=0;i<(1<<e1.num)-1;i++){
            int en1=0;
            int en2=0;
            char tmp1[M];
            char tmp2[M];
            for(int j=0;j<e1.num;j++){
                if(i&(1<<j)){
                    tmp1[en1++]=e1.str[j];
                }
                else{
                    tmp2[en2++]=e1.str[j];
                }
            }
            tmp1[en1]='\0';
            tmp2[en2]='\0';
            if(judge(tmp2)){
             //   puts(tmp2);
             //   puts(tmp1);
                if(map1[tmp1]==0){
                    map1[tmp1]=1;
                    strcpy(e2.str,tmp1);
                    e2.step=e1.step+1;
                    e2.num=strlen(e2.str);
                    q1.push(e2);
                }
            }
        }
    }
}
int main(){
    int cas;
    while(~scanf("%d",&cas)){
        while(cas--){
            scanf("%s",str);
            int t1=bfs(str);
            printf("%d\n",t1);
        }
    }
    return 0;
}
