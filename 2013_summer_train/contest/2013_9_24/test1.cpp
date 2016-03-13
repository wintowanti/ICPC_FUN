#include<cstdio>
#include<cstring>
#define M 50080
struct E{
    int next[26];
    int flag;
}e[M];
int en;
void flash(E &e1){
    memset(e1.next,-1,sizeof(e1.next));
    e1.flag=0;
}
void insert(char *p){
    int tr=0;
    for(int i=0;p[i];i++){
        int t1=p[i]-'a';
        if(e[tr].next[t1]==-1){
            int t2=en++;
            flash(e[t2]);
            e[tr].next[t1]=t2;
        }
        tr=e[tr].next[t1];
    }
    e[tr].flag=1;
}
int find(char *p){
    int tr=0;
    for(int i=0;p[i];i++){
        int t1=p[i]-'a';
        if(e[tr].next[t1]==-1){
            return 0;
        }
        tr=e[tr].next[t1];
    }
    if(e[tr].flag==1) return 1;
    return 0;
}
char map1[M][20];
int main(){
    int n=0;
    while(~scanf("%d",&n)){
        flash(e[0]);
        en=1;
        for(int i=0;i<n;i++){
            scanf("%s",map1[i]);
            insert(map1[i]);
        }
        for(int i=0;i<n;i++){
            puts(map1[i]);
            puts("~~~~~~~~~");
            for(int j=1;j<strlen(map1[i])-1;j++){
                char str1[20];
                char str2[20];
                for(int k=0;k<j;k++) str1[k]=map1[i][k];str1[j]='\0';
                for(int k=j;map1[i][k];k++) str2[k-j]=map1[i][k];str2[strlen(map1[i])-j]='\0';
                puts(str1);
                puts(str2);
                if(find(str1)&&find(str2)){
                    puts(map1[i]);
                }
             }
        }
    }
    return 0;
}
/*
6
a
ahat
hat
hatword
hziee
word
*/
