#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
const int mod = 100;
const int maxn = 210;
const double eps = 1e-6;
const double PI = acos(-1.0);

int n,m,l,r;
int cnt[maxn];

double a[maxn],b[maxn],c[maxn];

inline int read()
{
    int ret=0;
    char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9')
    {
        ret=ret*10+ch-48;
        ch=getchar();
    }
    return ret;
}

int main()
{
    while (scanf("%d%d%d%d",&n,&m,&l,&r)==4 && (n||m||l||r))
    {
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=m;i++)
        {
            int w;
            scanf("%d",&w);
            w%=n;
            w=min(w,n-w);
            cnt[w]++;
        }
        if (n==1)
        {
            puts("1.0000");
            continue;
        }
        memset(a,0,sizeof(a));
        a[0]=1;
        for (int w=1;w<=100;w++)
        {
            if (!cnt[w]) continue;
            for (int i=0;i<n;i++) b[i]=0;
            b[w%n]+=0.5;
            b[(n-w)%n]+=0.5;
            while (cnt[w])
            {
                if (cnt[w]&1)
                {
                    for (int i=0;i<n;i++)
                    {
                        c[i]=0;
                        for (int j=0;j<n;j++)
                            c[i]+=a[j]*b[(j+i)%n];
                    }
                    for (int i=0;i<n;i++)
                        a[i]=c[i];
                }
                for (int i=0;i<n;i++)
                {
                    c[i]=0;
                    for (int j=0;j<n;j++)
                        c[i]+=b[j]*b[(i+j)%n];
                }
                for (int i=0;i<n;i++)
                    b[i]=c[i];
                cnt[w]>>=1;
            }
        }

        double ans=0;
        for (int i=l-1;i<r;i++) ans+=a[i];
        printf("%.4lf\n",ans);
    }
    return 0;
}
