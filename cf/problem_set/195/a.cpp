#include<cstdio>
#include<cstring>
#define M 100
int z(int x){
    if(x<=0) return -x;return x;
}
int t[M][2];
int main(){
    int a,b;
    while(~scanf("%d%d",&a,&b)){
        int t1=z(a)+z(b);
        memset(t,0,sizeof(t));
        if(a>=0) t[0][0]=t1;
        else t[0][0]=-t1;
        if(b>=0) t[1][1]=t1;
        else t[1][1]=-t1;
        if(t[0][0]<t[1][0]){
            printf("%d %d %d %d",t[0][0],t[0][1],t[1][0],t[1][1]);
        }
        else printf("%d %d %d %d",t[1][0],t[1][1],t[0][0],t[0][1]);
        puts("");
    }
    return 0;
}
