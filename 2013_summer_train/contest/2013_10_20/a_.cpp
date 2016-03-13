#include<cstdio>
#include<cstring>
#define M 300000
int fa[M];
int e[M][2];
int find_fa(int x){
    if(x==fa[x]) return x;
    return fa[x]=find_fa(fa[x]);
}
int un(int x,int y){
    int fa1=find_fa(x);
    int fa2=find_fa(y);
    fa[fa2]=fa1;
}
int main(){
    int cas;
    while(~scanf("%d",&cas)){
        while(cas--){
            int n,m;scanf("%d%d",&n,&m);
            for(int i=1;i<=n;i++) fa[i]=i;
            for(int i=0;i<m;i++){
                scanf("%d%d",&e[i][0],&e[i][1]);
                if(e[i][0]==e[i][1]) m--,i--;
            }
            for(int i=0;i<m;i++){
                un(e[i][0],e[i][1]);
            }
            int flag=0;
            for(int i=1;i<=n;i++){
                if(fa[i]==i){
                    flag++;
                }
            }
            if(flag>1){
                puts("Nani?!");
            }
            else{
                if(m==n-1){
                    puts("Yes");
                }
                else{
                    puts("No");
                }
            }
        }
    }
    return 0;
}
