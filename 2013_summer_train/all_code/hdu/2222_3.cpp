#include<cstdio>
#include<cstring>
#define M 1040000
#define N 26
struct AC{
    int en;
    int my_que[M<<2];
    int sp,tp,root;
    void init(){
        en=1;root=0;
        flash(e[root]);
    }
    struct E{
        int next[N];
        int fail,flag;
    }e[M];
    void flash(E &e){
        memset(e.next,-1,sizeof(e.next));
        e.fail=-1;
        e.flag=0;
    }
    void insert(char *p){
        int tr=root;
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
    void bfs(){
        sp=0,tp=-1;
        my_que[++tp]=root;
//        printf("%d!!~~~\n",root);
        while(sp<=tp){
            int pu=my_que[sp++];
//            printf("pu is %d\n",pu);
            for(int i=0;i<N;i++){
                if(e[pu].next[i]!=-1){
                    if(pu==root){
//                        printf("this is %d!!!   %c\n",root,i+'a');
                       e[e[pu].next[i]].fail=root;
                    }
                    else{
                        int pv=e[pu].fail;
                        while(pv!=-1){
                            if(e[pv].next[i]!=-1){
                                e[e[pu].next[i]].fail=e[pv].next[i];
                                break;
                            }
                            pv=e[pv].fail;
                        }
                        if(pv==-1){
                            e[e[pu].next[i]].fail=root;
                        }
                    }
//                    printf("%d*****\n",e[pu].next[i]);
                    my_que[++tp]=e[pu].next[i];
                }
            }
        }
    }
    void dfs(E e1){
        for(int i=0;i<N;i++){
            if(e1.next[i]!=-1){
                printf("mark %c   fail is %d   flag is %d \n",i+'a',e[e1.next[i]].fail,e[e1.next[i]].flag);
//                getchar();
//                getchar();
                dfs(e[e1.next[i]]);
            }
        }
    }
    int query(char *p){
        int tr=root;
        int ans=0;
        for(int i=0;p[i];i++){
            int t1=p[i]-'a';
//            printf("%d!!%c!\n",tr,t1+'a');
            while(e[tr].next[t1]==-1&&tr!=root) tr=e[tr].fail;
            tr=e[tr].next[t1];

//            printf("%d!!!\n",tr);
            if(tr==-1) tr=root;
            int tmp=tr;
            while(tmp!=root&&e[tmp].flag!=-1){
                ans+=e[tmp].flag;
                e[tmp].flag=-1;
                tmp=e[tmp].fail;
            }
        }
        return ans;
    }
}ac;
char str1[1000006];
int main(){
    int cas;while(~scanf("%d",&cas)){
        while(cas--){
            ac.init();
            int n;scanf("%d",&n);
            char str[100];
            for(int i=0;i<n;i++){
                scanf("%s",str);
                ac.insert(str);
            }
            ac.bfs();
//            ac.dfs(ac.e[0]);
            scanf("%s",str1);
            int ans=ac.query(str1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
1
3
she
he
e
she
*/
