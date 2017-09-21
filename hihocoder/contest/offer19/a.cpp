#include <cstdio>
#include <iostream>
using namespace std;

const int MX = 808;
char base[MX][MX];
char target[MX][MX];
int main(){
    int n,m,kk;
    while(cin>>n>>m>>kk){
        for(int i = 0;i <n; i++){
            scanf("%s",base[i]);
        }
        for(int i = 0; i < kk; i++){
            int N,M; scanf("%d%d",&N,&M);
            for(int j = 0;j < N; j++){
                scanf("%s", target[j]);
            }
            int tsum = 0;
            for(int i1 = 0; i1 < n; i1++){
                for(int j1 = 0; j1 < m; j1++){
                    tsum = 0;
                    for(int i2 = 0; i2 < N; i2++){
                        if(tsum == -1) break;
                        for(int j2 = 0; j2 < M; j2++){
                            if(base[(i1+i2)%n][(j1+j2)%m] == target[i2][j2]){
                                tsum ++;
                            }
                            else{
                                tsum = -1;
                                break;
                            }
                        }
                    }
                    if(tsum == N*M){
                        break;
                    }
                }
                if(tsum == N*M){
                    break;
                }
            }
            if(tsum == N*M){
                puts("YES");
            }
            else{
                puts("NO");
            }
        }
    }
    return 0;
}
