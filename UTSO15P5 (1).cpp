// Daxi the Taxi
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _lg(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
typedef pair<int, int> ip;
typedef pair<int, ip> iip;
typedef long long ll;

#define MM 50001

struct node
{
	int u, v, w;
}; auto comp = [](node a, node b) { return a.w > b.w; };

int N, M, oc, p[MM], lca[17][MM], cst[17][MM];
priority_queue<node, vector<node>, decltype(comp)> pq(comp);
vector<ip> g[MM], e[MM];

int find_set(int x)
{
	return x != p[x] ? p[x] = find_set(p[x]) : p[x];
}

void union_set(int x, int y)
{
	p[x] = y;
}

void dfs(int u /* node */, int p /* parent */)
{
	for(auto v : g[u])
	{
		if(v.first == p) continue;
		lca[_lg(v.first)][v.first] = p == 0 ? -1 : p;
		cst[_lg(v.first)][v.first] = p == 0 ? -1 : v.second;
		dfs(v.first, u);
	}
}

void buildLCA()
{
	for(int i = 0; i < _log2(N); i++)
		for(int j = 1; j <= N; j++)
			lca[i][j] = lca[i - 1][lca[i - 1][j]];
	
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 1, u, v, w; i <= M; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		pq.push({u, v, w});
	}
	// Kruskal's
	for(int i = 1; i <= N; i++) p[i] = i;
	while(!pq.empty())
	{
		auto u = pq.top(); pq.pop();
		int x = find_set(u.u), y = find_set(u.v);
		if(x != y) g[u.u].push_back({u.v,u.w}), g[u.v].push_back({u.u,u.w}), oc += u.w, union_set(x, y);
		else       e[u.u].push_back({u.v,u.w}), e[u.v].push_back({u.u,u.w}); // Add all unused edges
	}
	printf("%d\n", oc);
	dfs(1, 0);
}
