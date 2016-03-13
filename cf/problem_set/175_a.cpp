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
        //#置i为要筛选的节点#%
        int i = ind;

        //#c中保存i节点的左孩子#%
        int c = i * 2 + 1; //#+1的目的就是为了解决节点从0开始而他的左孩子一直为0的问题#%

        while(c < len)//#未筛选到叶子节点#%
        {
                //#如果要筛选的节点既有左孩子又有右孩子并且左孩子值小于右孩子#%
                //#从二者中选出较大的并记录#%
                if(c + 1 < len && d[c] < d[c + 1])
                        c++;
                //#如果要筛选的节点中的值大于左右孩子的较大者则退出#%
                if(d[i] > d[c]) break;
                else
                {
                        //#交换#%
                        int t = d[c];
                        d[c] = d[i];
                        d[i] = t;
                        //
                        //#重置要筛选的节点和要筛选的左孩子#%
                        i = c;
                        c = 2 * i + 1;
                }
        }

        return;
}

void heap_sort(int d[], int n)
{
        //#初始化建堆, i从最后一个非叶子节点开始#%
        for(int i = n / 2; i >= 0; i--)
                sift(d, i, n);

        for(int j = 0; j < n; j++)
        {
                //#交换#%
                int t = d[0];
                d[0] = d[n - j - 1];
                d[n - j - 1] = t;

                //#筛选编号为0 #%
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
