/*
 * main.cpp
 *
 *  Created on: Sep 30, 2017
 *      Author: Kevin
 */

#include <bits/stdc++.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef pair<int, int> pii;
struct E { int u, v, id; } q[1000002];
int N, Q; long long dis[6001], ans[1000002]; vector<pii> adj[6002]; bool vis[6002];
bool cmp(E a, E b) { return a.u < b.u || a.u == b.u && a.v < b.v; }

void bfs(int st)
{
	memset(vis, 0, sizeof(vis));
	queue<int> Q; Q.push(st); vis[st] = true; dis[st] = 0;
	while(!Q.empty())
	{
		int cur = Q.front(); Q.pop();
		for(pii t : adj[cur])
		{
			if(!vis[t.first]){
				Q.push(t.first); vis[t.first] = true; dis[t.first] = dis[cur] + t.second;
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	for(int i = 1, x, y, z; i < N; i++)
	{
		scanf("%d %d %d", &x, &y, &z);
		adj[x].push_back({y, z}); adj[y].push_back({x, z});
	}

	scanf("%d", &Q);
	for(int i = 0; i < Q; i++)
	{
		scanf("%d %d", &q[i].u, &q[i].v);
		if(q[i].u > q[i].v) swap(q[i].u, q[i].v);
		q[i].id = i;
	}

	sort(q, q + Q, cmp);

	int pre = -1;
	for(int i = 0; i < Q; i++)
	{
		if(pre != q[i].u) bfs(q[i].u);
		pre = q[i].u; ans[q[i].id] = dis[q[i].v];
	}

	for(int i = 0; i < Q; i++) printf("%lld\n", ans[i]);
}