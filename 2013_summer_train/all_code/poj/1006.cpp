#include<cstdio>
#define M 200
int map1[M][M];
int next[M];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<m;i++){
            map1[i][0]=i%n+1;
        }
        for(int i=1;i<=n;i++) next[i]=n-1;
        for(int i=0;i<m;i++){
            int t1=map1[i][0];
            map1[i][1]=next[t1]%n+1;
            while(map1[i][1]==map1[i][0]){
//                printf("!!!!!%d   %d!!!!!!!! ***",t1,next[t1]);
                next[t1]--;
                next[t1]=(next[t1]+n)%n;
                map1[i][1]=next[t1]%n+1;
            }
            next[t1]--;
            next[t1]=(next[t1]+n)%n;
        }
////        for(int i=0;i<m;i++){
////            printf("%d   %d\n",map1[i][0],map1[i][1]);
////        }
        for(int i=0;i<m;i++){
            int t1=1;
            for(int j=2;j<n;j++){
                while(t1==map1[i][0]||t1==map1[i][1]){
                    t1++;
                }
                map1[i][j]=t1++;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j) printf(" %d",map1[i][j]);
                else printf("%d",map1[i][j]);
            }
            puts("");
        }
    }
    return 0;
}
