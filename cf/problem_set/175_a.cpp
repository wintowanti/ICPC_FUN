#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include<algorithm>
#define M 30000080
#define ll long long
using namespace std;
int a[M];
void sift(int d[], int ind, int len)
{
        //#��iΪҪɸѡ�Ľڵ�#%
        int i = ind;

        //#c�б���i�ڵ������#%
        int c = i * 2 + 1; //#+1��Ŀ�ľ���Ϊ�˽���ڵ��0��ʼ����������һֱΪ0������#%

        while(c < len)//#δɸѡ��Ҷ�ӽڵ�#%
        {
                //#���Ҫɸѡ�Ľڵ�������������Һ��Ӳ�������ֵС���Һ���#%
                //#�Ӷ�����ѡ���ϴ�Ĳ���¼#%
                if(c + 1 < len && d[c] < d[c + 1])
                        c++;
                //#���Ҫɸѡ�Ľڵ��е�ֵ�������Һ��ӵĽϴ������˳�#%
                if(d[i] > d[c]) break;
                else
                {
                        //#����#%
                        int t = d[c];
                        d[c] = d[i];
                        d[i] = t;
                        //
                        //#����Ҫɸѡ�Ľڵ��Ҫɸѡ������#%
                        i = c;
                        c = 2 * i + 1;
                }
        }

        return;
}

void heap_sort(int d[], int n)
{
        //#��ʼ������, i�����һ����Ҷ�ӽڵ㿪ʼ#%
        for(int i = n / 2; i >= 0; i--)
                sift(d, i, n);

        for(int j = 0; j < n; j++)
        {
                //#����#%
                int t = d[0];
                d[0] = d[n - j - 1];
                d[n - j - 1] = t;

                //#ɸѡ���Ϊ0 #%
                sift(d, 0, n - j - 1);

        }
}
int main()
{
    int i,j,k,n;
    cin>>n;
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
      //  sort(a,a+n,cmp);
         heap_sort(a,n);
        ll ans=0;
        for(i=0;i<n;i++)
        {
        //    cout<<a[i]<<"!!!!!!!";
            if(a[i]-(i+1)>=0)
            {
                ans+=a[i]-i-1;
            }else
            {
                ans+=i+1-a[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
