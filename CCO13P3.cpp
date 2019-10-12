#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define ff first
#define ss second
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int N, dia, dis[400005];
ll num, cnt[400005];
vector<int> g[400005];

int dfs(int u, int pa)
{
	cnt[u] = 1, dis[u] = 0;
	for(int v : g[u])
	{
		if(v != pa)
		{
			dfs(v, u);
			if(dis[u]+dis[v]+1 > dia)
			{
				dia = dis[u]+dis[v]+1;
				num = cnt[u]*cnt[v];
			}
			else if(dis[u]+dis[v]+1 == dia)
				num += cnt[u]*cnt[v];
			if(dis[v]+1 > dis[u])
			{
				dis[u] = dis[v]+1;
				cnt[u] = cnt[v];
			}
			else if(dis[v]+1 == dis[u])
				cnt[u] += cnt[v];
		}
	}
}

int main()
{
	memset(cnt, 1, sizeof(cnt));
	scanf("%d", &N);
	for(int i = 1, a, b; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs(1, 0);
	printf("%d %lld\n", dia+1, num);
}
