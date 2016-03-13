#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define N 1005
#define min(a,b) (a<b?a:b)

int n, m;
int size, id, scc;
int color[N], head[N];
int low[N], dfn[N], block[N];
int stack[N], temp[N], top, cnt; // temp ��һ����ʱ��ջ���洢��˫��ͨ��֧
bool map[N][N], expell[N], instack[N];  // expell[i]==true��ʾi��Ҫ������
struct { int v, next; } edge[N*1000];

bool odd_cycle ( int u, int clr ) //�ж��Ƿ������Ȧ
{
	color[u] = clr;
	for ( int i = head[u]; i; i = edge[i].next )
	{
		int v = edge[i].v;
		if ( block[v] == scc )
		{
			if ( color[v] && color[v] == color[u] )
				return true;
			if ( !color[v] && odd_cycle (v, -clr) )
				return true;
		}
	}
	return false;
}

void Tarjan ( int u, int father )
{
	int v, t;
	stack[++top] = u;
	instack[u] = true;
	dfn[u] = low[u] = ++id;
	for ( int i = head[u]; i; i = edge[i].next )
	{
		v = edge[i].v;
		if ( v == father ) continue;
		if ( ! dfn[v] )
		{
			Tarjan ( v, u );
			low[u] = min ( low[u], low[v] );
			if ( low[v] >= dfn[u] )  // u�Ǹ��
			{
				scc++;
				do {
					t = stack[top--];
					instack[t] = false;
					block[t] = scc;
					temp[++cnt] = t; //��ջ��ͬʱ�����еĵ��¼��temp�У�����temp������˫��ͨ��֧�����еĵ�
				} while ( t != v ); //ע�ⲻҪ��u��ջ����Ϊһ�����������ڲ�ͬ��˫��ͨ��֧

				temp[++cnt] = u; // ���u���ڲ�ͬ��˫��ͨ��֧����������ȻҲ����temp
				memset(color,0,sizeof(color)); // ������ɫ��Ϊ0
			    if ( cnt >= 3 && odd_cycle(u,1) ) // ��temp�д�����Ȧ����ôtemp�е������˶���������
				{
					while ( cnt != 0 )
						expell[temp[cnt--]] = false;
				}
				else cnt = 0;
			}
		}
		else if ( instack[v] )
			low[u] = min ( low[u], dfn[v] );
	}
}


void initial()
{
	top = cnt = 0;
	size = id = scc = 0;
	memset(map,0,sizeof(map));
	for ( int i = 1; i <= n; i++ )
	{
		expell[i] = true;
		instack[i] = false;
		dfn[i] = low[i] = block[i] = head[i] = 0;
	}
}

void add ( int u, int v )
{
	size++;
	edge[size].v = v;
	edge[size].next = head[u];
	head[u] = size;
}

int main()
{
	int u, v, i, j;
	while ( scanf("%d%d",&n,&m) && (m+n) )
	{
		initial();
		while ( m-- )
		{
			scanf("%d%d",&u,&v);
			map[u][v] = map[v][u] = true;
		}

		for ( i = 1; i <= n; i++ )
			for ( j = i+1; j <= n; j++ )
				if ( ! map[i][j] )
					add(i,j), add(j,i);

		for ( i = 1; i <= n; i++ )
			if ( ! dfn[i] ) Tarjan(i,-1);

		int res = 0;
		for ( i = 1; i <= n; i++ )
		    if ( expell[i] ) res++;

		printf("%d\n", res );
	}
	return 0;
}
