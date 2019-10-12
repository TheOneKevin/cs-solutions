#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
typedef pair<int, int> ip;
typedef long long ll;

int N, Q, lca[13][6005], dep[6005];
ll dis[6005];
vector<ip> adj[6005];

void dfs(int u, int p)
{
	for(ip el : adj[u])
	{
		int v = el.first, w = el.first;
		if(v != p)
		{
			dep[v] = dep[u] + 1;
			dis[v] = dis[u] + w;
			lca[0][v] = u;
			dfs(v, u);
		}
	}
}

int getLCA(int u, int v)
{
	if(dep[u] < dep[v])
	{
		int a = u;
		u = v;
		v = a;
	}
	// Equalize the depth
	for(int i = _log2(N); i >= 0; i--)
		if(lca[i][u] != -1 && dep[lca[i][u]] >= dep[v])
			u = lca[i][u];
	// If the resultant depths are equal, return
	if(u == v) return v;
	// Else do LCA
	for(int i = _log2(N); i >= 0; i--)
		if(lca[i][u] != -1 && lca[i][v] != -1 && lca[i][u] != lca[i][v])
			u = lca[i][u], v = lca[i][v];
	return lca[0][u];
}

int main()
{
	scanf("%d", &N);
	for(int i = 1, t1, t2, t3; i <= N; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		adj[t1].push_back({ t2, t3 });
		adj[t2].push_back({ t1, t3 });
	}
	memset(lca, -1, sizeof(lca));
	dfs(0, -1);
	for(int i = 1; i < _log2(N) + 1; i++)
		for(int j = 0; j < N; j++)
			if(lca[i - 1][j] != -1)
				lca[i][j] = lca[i - 1][lca[i - 1][j]];
	scanf("%d", &Q);
	for(int i = 1, u, v; i <= Q; i++)
	{
		scanf("%d %d", &u, &v);
		int rt = getLCA(u, v);
		printf("%d", dis[u] + dis[v] + 2 * dis[rt]);
	}
}
