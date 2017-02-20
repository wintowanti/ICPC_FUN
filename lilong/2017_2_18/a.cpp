#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

const long long MOD = 1e9+7;
queue< long long > qa;
queue< long long > qb;
int main(){
    long long cas;
    cin>>cas;
    {
        while(cas--){
            long long a,b,n;
            cin>>a>>b>>n;
            if(1 == a){
                if(b <= n) puts("0");
                else puts("1");
                continue;
            }
            else if(1 == b){
                if(a <= n) puts("0");
                else puts("1");
                continue;
            }
            else{
                while(!qa.empty()) qa.pop();
                while(!qb.empty()) qb.pop();
                for(long long i = 1; i < a; i++) qa.push(0);
                for(long long i = 1; i < b; i++) qb.push(0);
                long long tsuma = 0;
                long long tsumb = 0;
                for(long long i = 0; i < n; i++){
                    long long nexta;
                    long long nextb;
                    if(i == 0){
                        nexta = 1;
                        nextb = 1;
                    }
                    else{
                        nexta = tsumb;
                        nextb = tsuma;
                    }
                    tsuma -= qa.front(); qa.pop();
                    tsuma += MOD; tsuma %= MOD;
                    tsuma += nexta;
                    qa.push(nexta);
                    tsuma %= MOD;

                    tsumb -= qb.front(); qb.pop();
                    tsumb += MOD; tsumb %= MOD;
                    tsumb += nextb;
                    qb.push(nextb);
                    tsumb %= MOD;

                }
                long long ans = tsuma + tsumb; ans %= MOD;
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
