#include<cstdio>
#include<cstring>
#define M 1080
int dp[M][M];
int a[M];
int b[M];
int my_hash[300][300];
int max(int x,int y){
    if(x>y) return x;return y;
}
int min(int x,int y){
    if(x>y) return y;return x;
}
int dfs(int x,int y){
    if(x<0||y<0) return 0;
    int tsum=0;
    if(a[x]==b[y]){
        tsum=dfs(x-1,y-1)+1;
    }
    else{
        dfs(x-1,y);
        dfs(x,y-1);
        dp[x][y]=0;
    }
    return dp[x][y]=tsum;
}
int max_com(int n1,int n2){
    memset(dp,0,sizeof(dp));
    int ans=dfs(n1-1,n2-1);
    int tmax=0;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(tmax<dp[i][j]) tmax=dp[i][j];
        }
    }
    return tmax;
}
int f(char *p){
    int t1=p[0]-'0';
    t1=t1*12;
//    printf("%d!!!!\n",t1);
    int t2=my_hash[p[1]][p[2]];
    t1=t1+t2;
    return t1;
}
void init(){
    my_hash['C']['-']=-1;
    my_hash['C'][0]=0;
    my_hash['C']['+']=1; my_hash['D']['-']=1;
    my_hash['D'][0]=2;
    my_hash['D']['+']=3; my_hash['E']['-']=3;
    my_hash['E'][0]=4;   my_hash['F']['-']=4;
    my_hash['F'][0]=5;   my_hash['E']['+']=5;
    my_hash['F']['+']=6; my_hash['G']['-']=6;
    my_hash['G'][0]=7;
    my_hash['G']['+']=8; my_hash['A']['-']=8;
    my_hash['A'][0]=9;
    my_hash['A']['+']=10;my_hash['B']['-']=10;
    my_hash['B'][0]=11;
    my_hash['B']['+']=12;
}
/*
 C, C+, D, D+, E, F, F+, G, G+, A, A+, B
*/
int main(){
    int n;
    init();
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            char str[100];scanf("%s",str);
            a[i]=f(str);
        }
//        for(int i=0;i<n;i++){
//            printf("%d  !",a[i]);
//        }
//        puts("");
        int m;scanf("%d",&m);
        for(int i=0;i<m;i++){
            int n2;scanf("%d",&n2);
            for(int j=0;j<n2;j++){
                char str[100];
                scanf("%s",str);
                b[j]=f(str);
            }
//            for(int j=0;j<n2;j++){
//                printf(" %d~~~",b[j]);
//            }
//            puts("!!!!!");
            int t1=max_com(n,n2);
            double ans=(t1*1.0)/n2;
            printf("%.6lf\n",ans);
        }
    }
    return 0;
}
/*
4 5C+ 5D 5C 5G
4
2 5D- 5D
2 5D 4B+
4 5D 5C+ 5D 5F-
4 5G 5C+ 5D 5C


9
2C+  2E-  2F-  2F   2F+  3C- 2G+  2A+ 4B+
100
9
2D- 2D+  2E    2E+   2G- 2B  2A-  2B- 5C
*/
