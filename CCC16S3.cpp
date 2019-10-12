/*
 * main.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: Kevin
 */

#include <bits/stdc++.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int N, M, e;
vector<int> adj[100002];
vector<int> adj2[100002];
int pho[100002];
bool vis[100002];

bool dfs(int u, int pa)
{
	bool flag = pho[u];

	for(int v : adj[u])
		if(v != pa)
			flag |= dfs(v, u);
	if(flag && pa != -1)
	{
		//cout << u << " " << pa << endl;
		adj2[u].push_back(pa);
		adj2[pa].push_back(u);
		e++;
	}

	return flag;
}

int len, node;
void dfs2(int u, int pa, int d)
{
	if(d > len)
	{
		len = d;
		node = u;
	}

	for(int v : adj2[u])
		if(v != pa)
			dfs2(v, u, d + 1);
}

int main()
{
	scanf("%d %d", &N, &M);
	int st = 0;
	for(int i = 0, a; i < M; i++)
	{
		scanf("%d", &a);
		pho[a] = true;
		st = a;
	}

	for(int i = 0, a, b; i < N - 1; i++)
	{
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(st, -1);
	dfs2(st, -1, 0);
	len = 0;
	dfs2(node, -1, 0);
	printf("%d\n", 2 * e - len);
	//cout << len << endl;
}