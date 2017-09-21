#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long lint;

const int MOD = 1e9+7;
const int N = 10;

struct matrix
{
    lint m[N][N];
    matrix()
    {
        memset(m,0,sizeof(m));//注意要清零
    }
};

matrix operator * (const matrix & a,const matrix & b)
{
    matrix c;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            c.m[i][j]=0;
            for (int k=0; k<N; k++)
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;//一般题目都要求要modulo一个数
        }
    return c;
}

matrix quick(matrix base,lint pow)
{
    matrix a;
    for (int i=0; i<N; i++) a.m[i][i]=1;//单位阵，矩阵乘法时要用到
    while (pow)
    {
        if (pow&1) a=a*base;
        base=base*base;
        pow>>=1;
    }
    //if (pow==0) return base;
    return a;
}
lint n,m;
int main(){
    while(cin>>n>>m){
        matrix base;
        matrix first;
        for(int i = 1; i < N && i <= m; i++){
            first.m[0][i] = 1;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(j*i <= m && i <= m && j <= m){
                    base.m[j][i] = 1;
                }
            }
        }
        base = quick(base, n-1);
        first = first * base;
        lint ans = 0;
        for(int i = 0; i < N; i++){
            ans += first.m[0][i];
            ans %= MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
