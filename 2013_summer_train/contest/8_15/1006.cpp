#include<cstdio>
#include<cstring>
#include<iostream>
#define M 1080
using namespace std;
int dp1[M][M];
int dp2[M][M];
char str1[M];
char str2[M];
char str11[M];
char str22[M];
char c[M];
int ans1[M][2];
int ans2[M][2];
int max(int x,int y){
    if(x>y) return x;return y;
}
void rv(char *p){
    int i=0,j=strlen(p)-1;
    for(;j>i;i++,j--){
        swap(p[i],p[j]);
    }
}
int dfs1(int x,int y){
    if(x<0||y<0) return 0;
    if(dp1[x][y]!=-1) return dp1[x][y];
    if(str1[x]==str2[y]){
        return dp1[x][y]=dfs1(x-1,y-1)+1;
    }
    else {
        int t1=dfs1(x-1,y);
        int t2=dfs1(x,y-1);
            t1=max(t1,t2);
         return dp1[x][y]=t1;
    }
}
int dfs2(int x,int y){
    if(x<0||y<0) return 0;
    if(dp2[x][y]!=-1) return dp2[x][y];
    if(str11[x]==str22[y]){
        return dp2[x][y]=dfs2(x-1,y-1)+1;
    }
    else {
        int t1=dfs2(x-1,y);
        int t2=dfs2(x,y-1);
        t1=max(t1,t2);
        return dp2[x][y]=t1;
    }
}
int main(){
    int cas;
    while(~scanf("%d",&cas)){
        int q=1;
        while(cas--){
            scanf("%s%s%s",str1,str2,c);
            strcpy(str11,str1);rv(str11);
            strcpy(str22,str2);rv(str22);
            int n,m;n=strlen(str1);m=strlen(str2);
            memset(dp1,-1,sizeof(dp1));
            memset(dp2,-1,sizeof(dp2));
//            dfs1(n-1,m-1);
//            dfs2(n-1,m-1);
            int en1=0;int en2=0;
            int cn=strlen(c);
            for(int i=0;i<n;i++){
                if(str1[i]==c[0]){
                    int tsum=1;
                    for(int j=i+1;j<n;j++){
                        if(str1[j]==c[tsum]){
                            tsum++;
                        }
                        if(tsum==cn){
                            ans1[en1][0]=i;
                            ans1[en1++][1]=j;
                            break;
                        }
                    }
                }
            }
            for(int i=0;i<m;i++){
                if(str2[i]==c[0]){
                    int tsum=1;
                    for(int j=i+1;j<m;j++){
                        if(str2[j]==c[tsum]){
                            tsum++;
                        }
                        if(tsum==cn){
                            ans2[en2][0]=i;
                            ans2[en2++][1]=j;
                            break;
                        }
                    }
                }
            }
//            for(int i=0;i<en1;i++){
//                printf("%d   %d\n",ans1[i][0],ans1[i][1]);
//            }
//            puts("*************************");
//            for(int i=0;i<en2;i++){
//                printf("%d   %d\n",ans2[i][0],ans2[i][1]);
//            }
//            puts("__________________________________");
            int tmax=0;
            for(int i=0;i<en1;i++){
                for(int j=0;j<en2;j++){
                    int t1=0;
                    int t2=0;
                    if(ans1[i][0]>0&&ans2[j][0]>0){
                        t1=dfs1(ans1[i][0]-1,ans2[j][0]-1);
                    }
                    if(ans1[i][1]<n-1&&ans2[j][1]<m-1){
                        int r1=(n-1-ans1[i][1])-1;
                        int r2=(m-1-ans2[j][1])-1;
//                        printf("%d   %d    ^^^\n",r1,r2);
                        t2=dfs2(r1,r2);
                    }
//                    printf("%d   %d*******\n",t1,t2);
                    if(t1+t2>tmax) tmax=t1+t2;
                }
            }
            printf("Case #%d: %d\n",q++,tmax+cn);
        }
    }
    return 0;
}
/*
aacaaaf
cafceeef
cf
*/
