#include<cstdio>
#include<cstring>
#define M 200
char map1[M][4];
int main(){
    int n;while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%s",map1[i]);
        }
        int q;scanf("%d",&q);
        for(int i=0;i<q;i++){
            int u;scanf("%d",&u);
            u--;
            if(map1[u][0]!='?'){
                puts(map1[u]);
            }
            else{
                for(int i=1;;i++){
                    int flag=0;
                    int flag1=u-i;
                    int flag2=u+i;
                    if(flag1>=0&&map1[flag1][0]!='?'){
                        flag+=1;
                    }
                    if(flag2<n&&map1[flag2][0]!='?'){
                        flag+=2;
                    }
                    if(flag==3){
                        printf("middle of %s and %s\n",map1[flag1],map1[flag2]);
                        break;
                    }
                    else if(flag==1){
                        for(int j=0;j<i;j++){
                            printf("right of ");
                        }
                        puts(map1[flag1]);
                        break;
                    }
                    else if(flag==2){
                        for(int j=0;j<i;j++){
                            printf("left of ");
                        }
                        puts(map1[flag2]);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
/*
9
sp  ? ? ? ? ? ? ? sb
1000
*/
