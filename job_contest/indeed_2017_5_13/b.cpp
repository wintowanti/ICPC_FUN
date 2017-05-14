#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MX = 10;
int val[MX][MX];
int count(int x){
    int result = 0;
    while(x){
        result += 1;
        x = x&(x-1);
    }
    return result;
}
int main(){
    int n,k,m;
    cin>>n>>k>>m;
    int tmax = 0;
    memset(val, 0, sizeof(val));
    for(int i = 0; i < m; i++){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        val[a-1][b-1] = c;
    }
    for(int i = 0; i < (1<<n); i++){
        if(count(i) == k){
            for(int j = 0; j < (1<<n); j++){
                if(i&j) continue;
                if(count(j) != k) continue;
                int tsum = 0;
                for(int i1 = 0; i1 < n; i1++){
                    for(int j1 =0; j1 < n; j1++){
                        if((i&(1<<i1)) ==0 )  continue;
                        if((i&(1<<j1)) ==0 )  continue;
                        tsum += val[i1][j1];
                    }
                }
                for(int i1 = 0; i1 < n; i1++){
                    for(int j1 =0; j1 < n; j1++){
                        if((j&(1<<i1)) ==0 )  continue;
                        if((j&(1<<j1)) ==0 )  continue;
                        tsum += val[i1][j1];
                    }
                }
                if(tsum > tmax) tmax = tsum;
            }
        }
    }
    cout<<tmax<<endl;
    return 0;
}
