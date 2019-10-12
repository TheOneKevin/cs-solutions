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

int N, M, p[50001];
priority_queue<pair<int, ip>> e;
vector<pair<int, ip>> g, mst;

int find_set(int x)
{
	return x != p[x] ? p[x] = find_set(p[x]) : p[x];
}

void union_set(int x, int y)
{
	p[x] = y;
}

int kruskal(pair<int, ip> exc, bool ys)
{
	int cost = 0;
	for(int i = 1; i <= N; i++) p[i] = i;
	for(auto v : g) e.push(v);
	while(!e.empty())
	{
		pair<int, ip> u = e.top();
		//cout << -u.first << " " << u.second.first << " " << u.second.second << endl;
		e.pop();
		if((u == exc) && !ys)
			continue;
		int x = find_set(u.second.first), y = find_set(u.second.second);
		if(x != y)
		{
			if(ys) mst.push_back(u);
			union_set(x, y);
			cost += (-u.first);
		}
	}
	
	return cost;
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 1, u, v, w; i <= M; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		g.push_back(make_pair(-w, make_pair(u, v)));
	}
	int cn = kruskal({0, 0}, true);
	int mn = 0x3f3f3f3f;
	//cout << mn << endl;
	for(auto v : mst)
	{
		//cout << v.first << " " << v.second << endl;
		mn = min(mn, kruskal(v, false));
	}
	
	if(g.size() < N - 1 || mn >= cn)
		printf("-1");
	else
		printf("%d", mn);
}
