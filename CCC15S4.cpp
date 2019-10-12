#include <bits/stdc++.h>

using namespace std;

struct edge
{
	int u, t, h; // node, time, wear
	/*bool operator < (const edge &e) const {
		return false;
	}*/
};

typedef pair<int, int> ip;
vector<edge> adj[10001];
priority_queue<ip, vector<ip>, greater<ip>> pq;
int dist[100001][201];
int K, N, M, A, B;
bool p[100001];

inline void dij(int st) {
	memset(dist, 0x3F, sizeof(dist));
	pq.push(make_pair(0, st));
	dist[st][0] = 0;
	p[st] = true;
	while(!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		p[u] = false;
		for(int i = 0; i < (signed) adj[u].size(); i++) {
			for(int j = 0; adj[u][i].h + j < K; j++) {
				int newVal = dist[u][j] + adj[u][i].t;
				if(newVal < dist[adj[u][i].u][adj[u][i].h + j]) {
					dist[adj[u][i].u][adj[u][i].h + j] = newVal;
					if(!p[adj[u][i].u]) {
					    p[adj[u][i].u] = true;
					    pq.push({ newVal, adj[u][i].u });
					}
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &K, &N, &M);
	for(int i = 0, a, b, t, h; i < M; i++) {
		scanf("%d %d %d %d", &a, &b, &t, &h);
		adj[a].push_back({ b, t, h });
		adj[b].push_back({ a, t, h });
	}
	scanf("%d %d", &A, &B);
	dij(A);
	int mini = 0x3F3F3F3F;
	for(int i = 0; i < K; i++)
		mini = min(dist[B][i], mini);
	if(mini == 0x3F3F3F3F)
		printf("-1");
	else
		printf("%d", mini);
}