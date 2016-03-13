#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
int min(int a,int b){
    if(a <= b) return a;
    return b;
}
void solve(){
    int a,b;
    scanf("%d%d",&a,&b);
    int ans = 0;
    while(min(a,b) > 0){
        if(a > b ) swap(a,b);
        ans += b / a;
        b = b % a;
    }
    cout<<ans<<endl;

}
int main(){
    int cas;
    cin>>cas;
    while(cas--){
        solve();
    }
}
