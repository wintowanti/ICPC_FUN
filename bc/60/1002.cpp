#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef unsigned long long LL;
const LL MX = 1e6+88;
LL is_prime[MX];
vector< LL > prime_key;
void init(){
    memset(is_prime,0,sizeof(is_prime));
    is_prime[0] = is_prime[1] = 1;
    for(LL i = 2; i < MX; i++){
        if(is_prime[i] == 0){
            for(LL j = 2; i*j < MX; j++){
                is_prime[i *j ] = 1;
            }
        }
    }
    prime_key.clear();
    for(LL i = 2; i < MX; i++){
        if(is_prime[i] == 0){
            prime_key.push_back(i);
        }
    }
}
void work(){
    LL n,m; cin>>n>>m;
    vector< LL > nkey; nkey.clear();
    vector< LL > nnum; nnum.clear();
    vector< LL > mkey; mkey.clear();
    vector< LL > mnum; mnum.clear();
    LL tmp = n;
    for(LL i = 0; i < prime_key.size(); i++){
        if(tmp % prime_key[i] == 0){
            tmp /= prime_key[i]; nkey.push_back(prime_key[i]);
            LL count = 1;
            while(tmp % prime_key[i] == 0){
                tmp /= prime_key[i];
                count ++;
            }
            nnum.push_back(count);
        }
    }
    if(tmp != 1){
        nkey.push_back(tmp);
        nnum.push_back(1);
    }
    LL tmp2 = m;
    LL flag = 1;
    for(LL i = 0; i < nkey.size(); i++){
        if(tmp2 % nkey[i] == 0){
            tmp2 /= nkey[i];
            LL count = 1;
            mkey.push_back(nkey[i]);
            while(tmp2 % nkey[i] == 0){
                tmp2 /= nkey[i];
                count ++;
            }
            mnum.push_back(count);
        }
        else{
            flag = 0;
        }
    }
    if(tmp2 != 1) flag = 0;
   /* for(LL i = 0; i < nkey.size();i++){
        cout<<nkey[i]<<" " <<nnum[i]<<" "<<mnum[i]<<endl;
    }*/
    if(flag == 1){
        LL ans = 0;
        for(LL i = 0; i < nkey.size(); i++){
            if(nkey[i] > mkey[i]) flag = 0;
            else{
                LL tans = 0;
                LL tmp1 = nnum[i];
                LL tmp2 = mnum[i];
                if(tmp1 == tmp2) continue;
                while(tmp2 > 2 * tmp1){
                    tmp1 *= 2;
                    tans ++;
                }
                tans ++;
                if(tans > ans) ans = tans;
            }
        }
        if(flag){
            cout<<ans<<endl;
        }
        else{
            puts("-1");
        }
    }
    else{
        puts("-1");
    }
}
int main(){
    LL _;
    init();
    /*for(LL i = 0; i< 10; i++){
        cout<<prime_key[i]<<endl;
    }*/
    while(cin>>_){
        while(_--){
            work();
        }
    }
    return 0;
}

