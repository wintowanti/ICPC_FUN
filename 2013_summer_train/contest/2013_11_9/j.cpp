#include<cstdio>
#include<iostream>
#include<cstring>
#define M 1010
#define inf 0x3f3f3f3f
using namespace std;
int ans[M][2];
struct L{
    int a[M];
    int hash[M];
    int en;
    int id;
    void init(int id1){
        memset(hash,-1,sizeof(hash));
        en=-1;
        id=id1;
    }
    int is_empty(){
        if(en==-1) return 1;return 0;
    }
    int is_in(int see){
        if(hash[see]==-1) return -1;
        return hash[see];
    }
    void pop(int ti){
        int t1=a[0];
        ans[t1][0]=id;
        ans[t1][1]=ti;
        hash[t1]=-1;
        for(int i=1;i<=en;i++){
            a[i-1]=a[i];
            hash[a[i]]--;
        }
        en--;
    }
    void push_back(int t){
        a[++en]=t;
        hash[t]=en;
    }
    void insert_behand(int behand,int t2){
        int pos=hash[behand];
        for(int i=en;i>pos;i--){
            a[i+1]=a[i];
            hash[a[i]]++;
        }
        a[pos+1]=t2;
        hash[t2]=pos+1;
        ++en;
    }
}list[2];
int can_in[M][200];// 0 is num;
int group[M][M];// 0 for time 1 for en
int main(){
    int n,m;while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++){
            can_in[i][0]=0;
            while(1){
                int t1;scanf("%d",&t1);
                if(t1==0) break;
                can_in[i][++can_in[i][0]]=t1;
            }
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d",&group[i][0],&group[i][1]);
            for(int j=2;j<group[i][1]+2;j++){
                scanf("%d",&group[i][j]);
            }
        }
//        puts("^^^^");
        // kong
        list[0].init(0);
        list[1].init(1);
        int time=1;
        for(int i=1;i<=m;i++){
            while(time<=group[i][0]){
                if(!list[0].is_empty()) list[0].pop(time);
                if(!list[1].is_empty()) list[1].pop(time);
                time++;
                if(list[0].is_empty()&&list[1].is_empty()) break;
            }
            time=group[i][0]+1;
          //  printf("%d**%d*\n",time,group[i][1]);
            for(int j=2;j<group[i][1]+2;j++){
                int u=group[i][j];
                int tmin=inf;
                for(int k=1;k<=can_in[u][0];k++){
                    int v=can_in[u][k];
                   // printf("%d^^^v^^\n",v);
                    for(int i1=0;i1<2;i1++){
                        int pos=list[i1].is_in(v);
                        if(pos!=-1){
                            if(tmin>pos) tmin=pos;
                        }
                    }
                }
//                printf("%d**\n",tmin);
                if(tmin==inf){
                    int t1=0;
                    if(list[0].en>list[1].en) t1=1;
                    list[t1].push_back(u);
                  //  printf("%d  in_ %d\n",u,t1);
                }
                else if(tmin>=list[0].en){
                    if(list[0].en<=list[1].en){
                        list[0].push_back(u);
                    }
                    else list[1].push_back(u);
                }
                else{
                    int is_do=0;
                    for(int k=1;k<=can_in[u][0];k++){
                        int v=can_in[u][k];
                        if(is_do) break;
                        for(int i1=0;i1<2;i1++){
                            if(is_do) break;
                            int pos=list[i1].is_in(v);
                            if(pos!=-1){
                                if(pos==tmin) list[i1].insert_behand(v,u),is_do=1;
                            }
                        }
                    }
                }
            }
        }
        while(!list[0].is_empty()||!list[1].is_empty()){
           // printf("len is %d  %d\n",list[0].en,list[1].en);
 //           getchar();
            if(!list[0].is_empty()) list[0].pop(time);
            if(!list[1].is_empty()) list[1].pop(time);
            time++;
//            printf("%d^^^\n",time);
        }
        for(int i=1;i<=n;i++){
            printf("%d ",ans[i][1]);
            if(!ans[i][0]) puts("right");
            else puts("left");
        }
    }
    return 0;
}
/*
7 2
0
0
0
0
1 2 3 0
0
0
1 5
1 2 3 6 7
3 2
4 5

5 1
0
0
0
0
3 2 0
100000000 5
1 2 3 4 5



5 2
0
0
0
0
4 0
10 4
1 2 3 4
10  1
5
*/
