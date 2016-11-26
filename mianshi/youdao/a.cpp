#include <cstdio>
#include <iostream>
using namespace std;

const int MX = 30;
struct E{
    E(int x1,int y1,int x2,int y2){
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    E(){

    }
    bool hang(){
        if(x1 != x2) return true;
        return false;
    }
    int x1,y1,x2,y2;
};
E edge[MX];
int n;
int find(int x1,int y1,int x2,int y2){
    for(int i = 0; i < n; i++){
        if((x1 == edge[i].x1)&&(y1 == edge[i].y1)&&(x2 == edge[i].x2)&&(y2 == edge[i].y2)) return 1;
    }
    return 0;
}
int main(){
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < n; i++){
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1 > x2 || y1 > y2){
                swap(x1,x2);
                swap(y1,y2);
            }
            edge[i] = E(x1,y1,x2,y2);
        }
        int tflag = 0;
        for(int i = 0; i < n; i++){
            if(tflag) break;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(!edge[i].hang()) continue;
                if(!edge[j].hang()) continue;
                if(edge[i].y1 > edge[j].y1) continue;
                if(edge[i].x1 == edge[j].x1 && edge[i].x2 == edge[j].x2){
                    int flag = 0;
                    flag += find(edge[i].x1,edge[i].y1,edge[j].x1,edge[j].y1);
                    flag += find(edge[i].x2,edge[i].y2,edge[j].x2,edge[j].y2);
                    if(flag == 2){
                        tflag = 1;
                        printf("%d %d %d %d\n",edge[i].x1,edge[i].y1,edge[j].x2,edge[j].y2);
                    }
                }
                else continue;

            }
        }
    }
    return 0;
}
