#include<stdio.h>
#include<iostream>
#define ll long long
using namespace std;
ll n,m,N;
ll ** first;
ll ** E;
ll ** newn(ll **p)
{
	p=new ll*[n];
	for(ll i=0;i<n;i++)
	{
		p[i]=new ll[n];
	}
	return p;
}
void myprintf(ll **p)
{
    cout<<"~~~~~~~~~~~~"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d  ",p[i][j]);
        }
        puts("");
    }
    cout<<"~~~~~~~~~~~~"<<endl;
}
void init()
{
		first=newn(first);
		E=newn(E);
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				int t1;
				scanf("%d",&t1);
				first[i][j]=t1;
			}
		}
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				if(i!=j)
				E[i][j]=0;
				else
				E[i][j]=1;
			}
		}
}
ll ** add(ll n1,ll **p1,ll **p2)
{
	ll **tmp;
	tmp=newn(tmp);
	for(ll i=0;i<n1;i++)
	{
		for(ll j=0;j<n1;j++)
		{
			tmp[i][j]=(p1[i][j]+p2[i][j])%N;
		}
	}
	return tmp;
}
ll ** mul(ll n1,ll **p1,ll **p2)
{
	ll **tmp;
	tmp=newn(tmp);
	for(ll i=0;i<n1;i++)
	{
		for(ll j=0;j<n1;j++)
		{
			ll tsum=0;
			for(ll k=0;k<n1;k++)
			{
				tsum=(tsum+p1[i][k]*p2[k][j])%N;
			}
			tmp[i][j]=tsum;
		}
	}
	return tmp;
}
ll **pow(ll n1)
{
	ll ** tmp;
	ll ** ans;
	tmp=newn(tmp);
	ans=newn(ans);
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
		{
			if(i==j) ans[i][j]=1;
			else ans[i][j]=0;
			tmp[i][j]=first[i][j];
		}
	}
	ll t1=n1;
	while(t1)
	{
		ll ** t2;
		if(t1&1)
		{
		//    myprintf(ans);
		 //   myprintf(tmp);
			t2=mul(n,ans,tmp);
			delete ans;
			ans=t2;
		}
		t1=t1>>1;
		t2=mul(n,tmp,tmp);
		delete tmp;
		tmp=t2;
	}
	return ans;
}
void mycopy(ll **p1,ll **p2)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            p1[i][j]=p2[i][j];
        }
    }
}
ll **dfs(ll n1)
{
    ll** tmp;
    ll** t1;
    ll** t2;
    ll** t3;
    ll** t4;
    tmp=newn(tmp);
    mycopy(tmp,first);
    if(n1==1)
    {
        return tmp;
    }
    else
    {
        if(n1&1)
        {
            t1=pow((n1+1)/2);
            t2=add(n,E,t1);
            t3=dfs(n1/2);
            t4=mul(n,t2,t3);
            delete t2;
            delete t3;
            t1=add(n,t1,t4);
            delete t4;
            return t1;
        }
        else
        {
            t1=pow(n1/2);
          //  myprintf(t1);
            t2=add(n,E,t1);
            t3=dfs(n1/2);
            t4=mul(n,t2,t3);
            delete t1;
            delete t2;
            delete t3;
            t1=t4;
            return t1;
        }
    }

}
int main()
{
    ll **ans;
	while(cin>>n>>m>>N)
    {
        init();
        ans=dfs(m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j)
                {
                    printf(" %d",ans[i][j]);
                }
                else
                {
                    printf("%d",ans[i][j]);
                }
            }
            puts("");
        }
    }
    return 0;
}
