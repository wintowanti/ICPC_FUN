#include<cstdio>
#include<cstring>
#define M 3000000
int en;
struct T{
    int next[26];
}trie[M];
void flash(T & t){
    memset(t.next,-1,sizeof(t.next));
}
char str1[2000];
char str2[30];
int main(){
    int k;
    while(~scanf("%s%s%d",str1,str2,&k)){
        int ans=0;
        int n=strlen(str1);
        en=1;
        flash(trie[0]);
        for(int i=0;i<n;i++){
            int tr=0;
            int flag=0;
            for(int j=i;j<n;j++){
                int t1=str1[j]-'a';
                if(str2[t1]=='0') flag++;
                if(flag>k) break;
//                printf("%d!!!\n",flag);
                if(trie[tr].next[t1]==-1){
                    ans++;
                    int t2=en++;
                    flash(trie[t2]);
                    trie[tr].next[t1]=t2;
                }
                tr=trie[tr].next[t1];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
