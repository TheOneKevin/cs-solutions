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

int N, K, z[200003], sz[200003];
vector<ip> g[200003];
ll ans;

int dfs(int u, int pa)
{
	sz[u] = z[u];
	for(ip v : g[u])
	{
		if(v.first != pa)
		{
			dfs(v.first, u);
			sz[u] += sz[v.first];
		}
	}
}

int dfs2(int u, int pa, int t)
{
	ans += (ll)z[u]*t;
	for(ip v : g[u])
		if(v.first != pa)
			dfs2(v.first, u, v.second + t);
}

int cntr(int u, int pa)
{
	for(ip v : g[u])
		if(v.first != pa && sz[v.first]*2 > K)
			return cntr(v.first, u);
	return u;
}

int main()
{
	scanf("%d %d", &K, &N);
	for(int i = 0, a; i < K; i++)
	{
		scanf("%d", &a);
		z[a]++;
	}
	for(int i = 0, a, b, c; i < N-1; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	dfs(1, -1);
	dfs2(cntr(1, -1), -1, 0);
	printf("%lld\n", ans);
}