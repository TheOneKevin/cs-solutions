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

int N, M, dist[1002];
typedef pair<int, int> ip;
priority_queue<ip, vector<ip>, greater<ip>> pq;
vector<ip> graph[1001];

void dijkstra(int st)
{
	memset(dist, 0x3F, sizeof(dist));
	pq.push(make_pair(0, st));
	dist[st] = 0;
	while(!pq.empty())
	{
		int d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if(d > dist[u]) continue;
		dist[u] = d;
		for(ip e : graph[u])
			pq.push(make_pair(e.first + d, e.second));
	}

	for(int i = 0; i < N; i++)
	{
		if(dist[i] == 0x3F3F3F3F)
			cout << "-1" << endl;
		else
			cout << dist[i] << endl;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++)
	{
		int n, m, w;
		scanf("%d %d %d", &n, &m, &w);
		n--;
		m--;
		graph[n].push_back(make_pair(w, m));
		graph[m].push_back(make_pair(w, n));
	}

	dijkstra(0);
}