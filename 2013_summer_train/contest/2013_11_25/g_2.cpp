#include<cstdio>
int main(){
    int n,a,b;
    while(~scanf("%d%d%d",&n,&a,&b)){
        if(n>100000){
            puts("fuck");
            continue;
        }
        int ans=n%(a+b);
        if(ans<a) puts("Bob");
        else puts("Alice");
    }
    return 0;
}
