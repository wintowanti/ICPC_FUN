#include<iostream>
#define ll long long
using namespace std;
int main(){
    ll a,b;while(cin>>a>>b){
        ll ans=a/b;
        a=a-b*ans;
        while(a){
//            cout<<a<<"***"<<b;
            ll t1=b/a;
            ans+=t1;
            b=b-a*t1;
            swap(b,a);
//            cout<<a<<"***"<<b;
        }
        cout<<ans<<endl;
    }
}
