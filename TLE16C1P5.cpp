#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
typedef long long ll;
typedef pair<int, int> ip;

struct node {
	int l, r, m;
} seg[400004];

int N;
ll ans[100001], depth[100001], cur[100001], c[100001], d[100001];
vector<int> graph[100001];

// Normal segment tree building
void build(int l, int r, int n)
{
	seg[n].l = l, seg[n].r = r;
	if(l == r) {
		seg[n].m = INF;
		return;
	}
	int m = (l + r) / 2;
	build(l,     m, 2 * n);
	build(m + 1, r, 2 * n + 1);
	
	seg[n].m = min(seg[n * 2].m, seg[n * 2 + 1].m);
}

void update(int p, int v, int n)
{
	if(seg[n].l == seg[n].r) {
		seg[n].m = v;
		return;
	}
	int m = (seg[n].l + seg[n].r) / 2;
	if(p <= m) update(p, v, 2 * n);
	else       update(p, v, 2 * n + 1);
	
	seg[n].m = min(seg[n * 2].m, seg[n * 2 + 1].m);
}

// Modified query :(

/**
 * In the query function, check if the right side has a minimum
 * less than the current cost. If the condition is true, go to
 * the right child of the segment tree node. Otherwise, go to the left.
 * If we recursively continue this process until we hit a leaf node,
 * we will have found the deepest (rightmost) node with a
 * cost less than our current cost.
 */

ll query(int n, int v)
{
	if(v <= seg[n].m) return -INF;
	if(seg[n].l == seg[n].r) return seg[n].l;
	// Left or right???
	if(v > seg[2 * n + 1].m) return query(2 * n + 1, v);
	else return query(2 * n, v);
}

void dfs(int n, int v, int prev)
{
	cur[n] = v;
	if(v != N)
	{
		depth[n] = depth[n - 1] + d[v];
		int tmp = query(1, c[v]);
		ans[v] = ans[cur[tmp]] + (ll) c[v] * (depth[n] - depth[tmp]);
	}
	update(n, c[v], 1);
	for(int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if(next == prev) continue;
		dfs(n + 1, next, v);
	}
	update(n, INF, 1);
}

int main()
{
	scanf("%d", &N);
	for(int i = 1, p; i <= N - 1; i++) {
		scanf("%d %d %d", &p, &d[i], &c[i]);
		graph[p].push_back(i);
	}
	
	build(1, N, 1);
	update(1, 0, 1);
	dfs(1, N, -1);
	for(int i = 0, p, d; i < N - 1; i++) printf("%lld\n", ans[i + 1]);
}
