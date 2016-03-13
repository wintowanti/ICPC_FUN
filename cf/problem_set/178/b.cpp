#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<stack>
#include<queue>
#define M 108
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int sum1[M];
int sum2[M];
int e1[M],e2[M];
int g1,g2;
int cmp(int a,int b)
{
    if(a>b)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    while(cin>>n)
    {
        g1=0;
        g2=0;
        for(int i=0;i<n;i++)
        {
            int t1,t2;
            cin>>t1>>t2;
            if(t1==1)
            {
               e1[g1++]=t2;
            }
            else
            {
                e2[g2++]=t2;
            }
        }
        sort(e1,e1+g1,cmp);
        sort(e2,e2+g2,cmp);
        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum2));
        for(int i=1;i<=g1;i++)
        {
            sum1[i]=sum1[i-1]+e1[i-1];
        }
        for(int i=1;i<=g2;i++)
        {
            sum2[i]=sum2[i-1]+e2[i-1];
        }
        int ans=1000000;
        int flag=0;
//        cout<<"!!!!!!!!"<<endl;
//        cout<<g1<<"  "<<g2<<endl;
        for(int i=1;;i++)
        {
            for(int j=0;2*j<=i&&j<=g2;j++)
            {
                int k=i-2*j;
                int t1;
                if(k>g1)
                {
                    continue;
                }
                t1=i;
             //   int t1=i;
                int t2=sum1[g1]-sum1[k];
                int t3=sum2[g2]-sum2[j];
         //       printf("%d  %d  %d \n",t1,t2,t3);
                if(t1>=t2+t3)
                {
                    ans=t1;
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/**
3
2 100
1 100
2 13213
3
1 100
2 200
2 3
*/
