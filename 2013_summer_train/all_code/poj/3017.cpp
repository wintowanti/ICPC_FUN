#include<cstdio>
#include<set>
#define M 100200
#define ll long long
using namespace std;
ll a[M];
ll dp[M];
ll deq[M];
multiset<int >s1;
int main(){
    s1.clear();
    s1.insert(1);
    printf("%d!!!\b",*s1.begin());
    return 0;
}
