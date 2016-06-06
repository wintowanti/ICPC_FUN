#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;
struct E{
    int x1,y1,x2,y2;
    E(int _a, int _b,int _c,int _d){
        x1 = _a; y1 = _b; x2 = _c; y2 = _d;
    }
    bool in(int x,int y){
        if((x1 - x) * (y2-y) == (x2 - x) * (y1-y))
            return 1;
        return 0;
    }
};
vector< E > have;

void judge(int x1,int y1,int x2,int y2){
    for(int i = 0; i < have.size(); i++){
        if(have[i].in(x1,y1) && have[i].in(x2,y2)) return; 
    }
    have.push_back(E(x1,y1,x2,y2));
}
void get(int n,int m){
    have.clear();
    if(n < 2|| m< 2) return;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            for(int i1 = 1; i1<= n; i1++){
                for(int j1 = 1; j1<= m; j1++){
                   if(i1 == i && j1 ==j) continue;

                    judge(i,j,i1,j1);
                }
            }
        }
    }
}

int main(){
    puts("----");
    ofstream outf("good.txt");
    outf<<"aa={";
    int aa[40][40];
    for(int i = 1; i <= 40; i++){
        for(int j = 1; j <= 40; j++){
            printf("%d %d: ",i,j);
            get(i,j);
            printf("%d\n",have.size());
            aa[i-1][j-1] = have.size();
            outf<<aa[i-1][j-1]<<",";
        }
    }
    return 0;
}
