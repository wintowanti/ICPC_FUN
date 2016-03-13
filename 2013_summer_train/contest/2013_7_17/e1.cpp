#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define M 1010
#define N 505
using namespace std;
bool is_iland[M][M];
int o[2][6][2]={
0,1,
1,0,
1,-1,
0,-1,
-1,-1,
-1,0,

0,1,
1,1,
1,0,
0,-1,
-1,0,
-1,1
};
int a[M];
int  fa[M*M*2];
int  num[M*M*2];
int find_fa(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find_fa(fa[x]);
}
int change(int x,int y){
    return x*M+y;
}
int main(){
    int n,m;
//    for(int i=0;i<6;i++){
//        printf("%d  %d\n",o[i][0],o[i][1]);
//    }
    while(~scanf("%d%d",&n,&m)){
        memset(is_iland,0,sizeof(is_iland));
        for(int i=0;i<M*M-1;i++) fa[i]=i,num[i]=1;
        for(int i=0;i<n;i++){
            int t1,t2;scanf("%d%d",&t1,&t2);
            t1+=N;t2+=N;
            if(is_iland[t1][t2]){
                continue;
            }
            else{
                int tnum=0;
                int t5=(t1+1)%2;
                for(int j=0;j<6;j++){
                    int x1=t1+o[t5][j][0];
                    int y1=t2+o[t5][j][1];
                    int flag1=0;
                    if(is_iland[x1][y1]){
                    for(int k=0;k<j;k++){
                        int x2=t1+o[t5][k][0];
                        int y2=t2+o[t5][k][1];
                        int t4=change(x1,y1);
                        int t6=change(x2,y2);
                            t4=find_fa(t4);
                            t6=find_fa(t6);
                    if(t4==t6){
                                flag1=1;
                                break;
                    }
                    }
                        if(flag1) continue;
                        int t3=change(x1,y1);
                        t3=find_fa(t3);
                        tnum+=num[t3];
                        int flag1=0;
                    }
                }
               // printf("tnum is %d   ~~\n",tnum);
                if(tnum+1>m){
                 //   printf("%d   %d \n",t1-N,t2-N);
                    continue;
                }
                else{
                    is_iland[t1][t2]=1;
                    int t3=change(t1,t2);
                    num[t3]+=tnum;
                    int t5=(t1+1)%2;
                    for(int j=0;j<6;j++){
                        int x1=t1+o[t5][j][0];
                        int y1=t2+o[t5][j][1];
                        if(is_iland[x1][y1]){
                            int t4=change(x1,y1);
                            t4=find_fa(t4);
                            fa[t4]=t3;
                        }
                    }
                }
            }
        }
        int en=0;
        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                if(is_iland[i][j]){
                    int t1=change(i,j);
                    if(fa[t1]==t1){
                        a[en++]=num[t1];
                    }
                }
            }
        }
        sort(a,a+en);
        printf("%d\n",en);
        for(int i=0;i<en;i++){
            if(i) printf(" %d",a[i]);
            else printf("%d",a[i]);
        }
        puts("");
    }
    return 0;
}
/*
2 4
3 0
2 1
*/
