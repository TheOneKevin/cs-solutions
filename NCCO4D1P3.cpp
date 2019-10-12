// This is just the same code as CCO12P2
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

int N, M, d1[5003], d2[5003];
vector<ip> g1[5003];
vector<pair<ip, int>> e;
priority_queue<ip, vector<ip>, greater<ip>> pq;

void dij(int st, int* d, vector<ip>* g)
{
	while(!pq.empty()) pq.pop(); // >:(((
	pq.push({ 0, st });
	d[st] = 0;
	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		//if(l > d[u]) continue;
		//d[u] = l;
		for(ip v : g[u])
		{
			int l = v.second;
			if(d[v.first] > d[u] + l)
			{
				d[v.first] = d[u] + l;
				pq.push({ d[v.first], v.first });
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0, a, b, l; i < M; i++)
	{
		scanf("%d %d %d", &a, &b, &l);
		g1[a].push_back({ b, l });
		g1[b].push_back({ a, l });
		e.push_back({ { a, b }, l });
		e.push_back({ { b, a }, l });
	}
	
	memset(d1, INF, sizeof(d1));
	memset(d2, INF, sizeof(d2));
	
	dij(1, d1, g1);
	dij(N, d2, g1);
	
	int mn = d1[N], res = INF;
	for(auto v : e)
	{
		int t = d1[v.first.first] + d2[v.first.second] + v.second;
		if(t > mn && t < res) res = t;
	}
	
	printf("%d\n", res == INF ? -1 : res);
}
