#include<cstdio>
#include<cstring>
using namespace std;
int dp[10][3];
int DP(int x)
{
    bool flag=false;
    int s[15];
    int idx=0,summ=x,ans=0;
    for(;x;x/=10)
        s[++idx]=(x%10);
    s[idx+1]=0;
    for(int i=idx;i>0;--i)
    {
        ans+=(dp[i-1][2]*s[i]);//����λ���в��������Ƶ�
        if(flag) ans+=(dp[i-1][0]*s[i]);//֮ǰ���ֲ�����������
        else
        {
            if(s[i]>4)            ans+=dp[i-1][0];//����4
            if(s[i]>6)            ans+=dp[i-1][1];//����6
            if(s[i+1]==6&&s[i]>2) ans+=dp[i][1];//����62
        }
        if(s[i]==4||s[i+1]==6&&s[i]==2)
            flag=true;
    }
    return summ-ans;//���е�����ȥ����������
}
int main()
{
    int a,b;
    memset(dp,0,sizeof(dp));
    //Ԥ����������п���
    dp[0][0]=1;
    for(int i=1;i<=8;++i)
    {
        dp[i][0]=dp[i-1][0]*9-dp[i-1][1];//�ڲ�������������ĩλ�ֱ𲹳���4��9�����֣���ȥ��6���油2�ĸ���
        dp[i][1]=dp[i-1][0];//�ڲ�������������ĩλ��6
        dp[i][2]=dp[i-1][2]*10+dp[i-1][1]+dp[i-1][0];//���ֳ��ֲ������������
    }
    for(;scanf("%d%d",&a,&b);)
    {
        if(a+b==0) break;
        printf("%d\n",DP(b+1)-DP(a));
    }
    return 0;
}
