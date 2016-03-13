#include<cstdio>
#include<cstring>
#define M 200000
#define inf 0x3f3f3f3f
struct G{
    int head[M],en;
    struct E{
        int u,v,next;
    }e[M<<2];
    void init(){
        memset(head,-1,sizeof(head));
        en=0;
    }
    void add(int u,int v){
        e[en].u=u;e[en].v=v;e[en].next=head[u];head[u]=en++;
    }
}g1;
int ans[M][2];
int main(){
    int n;while(~scanf("%d",&n)){
        g1.init();
        for(int i=0;i<n;i++){
            int t1;scanf("%d",&t1);
            g1.add(t1,i);
        }
        int num=0;
        for(int i=1;i<M-2;i++){
            if(g1.head[i]!=-1){
//                printf("%d~~~~\n",i);
                int flag1=0;
                int flag2=0;
                int flag3=0;
                for(int j=g1.head[i];~j;j=g1.e[j].next){
                    int v=g1.e[j].v;
//                    printf("%d!!\n",v);
                    if(flag1==0){
                        flag1=1;
                        flag2=v;
                    }
                    else{
                        int t3=v-flag2;
                        if(flag3==0) flag3=t3;
                        else if(flag3!=t3){
                            flag3=-inf;
                            break;
                        }
                        flag2=v;
                    }
                }
                if(flag3!=-inf){
                    ans[num][0]=i;
                    ans[num++][1]=-flag3;
                }
            }
        }
        printf("%d\n",num);
        for(int i=0;i<num;i++){
            printf("%d %d\n",ans[i][0],ans[i][1]);
        }
    }
    return 0;
}
