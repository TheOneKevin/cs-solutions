#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
typedef long long ll;
typedef pair<ll, ll> ip;

struct node {
	ll v, c, n; // Node v, time, level
};

ll N, M, A, B, C, dist[100001];
vector<node> adj[200001];
priority_queue<ip, vector<ip>, greater<ip>> pq;

void dij(ll st, ll l)
{
	memset(dist, INF, sizeof(dist));
	while(!pq.empty()) pq.pop();
	pq.push({ 0, st });
	dist[st] = 0;
	while(!pq.empty())
	{
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if(d > dist[u]) continue;
		for(auto v : adj[u])
		{			
			if(dist[v.v] > dist[u] + v.c && v.n <= l)
			{
				dist[v.v] = dist[u] + v.c;
				pq.push({ dist[v.v], v.v });
			}
		}
	}
}

int main()
{
	scanf("%lld %lld", &N, &M);
	for(ll i = 1, a, b, c; i <= M; i++)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		adj[a].push_back({ b, c, i });
		adj[b].push_back({ a, c, i });
	}
	scanf("%lld %lld %lld", &A, &B, &C);
	
	ll hi = M, lo = 0, res = INF;
	while(lo <= hi)
	{
		int m = mid(hi, lo);
		dij(A, m);
		if(dist[B] < C) res = m, hi = m - 1;
		else lo = m + 1;
	}
	printf("%lld", res > M ? -1 : res);
}
