/***************************************************
   #>File Name: test.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/3 16:51:31
***************************************************/

#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<set>

using namespace std ;

#define int int
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define it iterator
#define mt(a,b) memset(a,b,sizeof(a))

typedef pair<int,int> pii;
typedef long long ll;

const int INF=0x3f3f3f3f;
const int MV=300008;
const int ME=2000006;
const int MOD=1000000007;

map<int,int> mp1;
int main(){
	int &t1=mp1[10];
	t1+=10;
	printf("%d\n",mp1[10]);
	return 0;
}
