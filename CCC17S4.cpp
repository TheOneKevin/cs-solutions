#include <bits/stdc++.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct dset
{
	int* p;
	int* rank;
	int n;

	void make_set(int x)
	{
		p[x] = x;
		rank[x] = 0;
	}

	int find_set(int x)
	{
		if(x != p[x])
			p[x] = find_set(p[x]);
		return p[x];
	}

	void union_set(int x, int y)
	{
		x = find_set(x), y = find_set(y);
		if(rank[x] > rank[y])
			p[y] = x;
		else
			p[x] = y;
		if(rank[x] == rank[y])
			rank[y]++;
	}

	dset(int n)
	{
		this -> n = n;
		p = new int[n + 1];
		rank = new int[n + 1];
		for(int i = 0; i < n; i++)
			make_set(i);
	}
};

struct E
{
	int u;
	int v;
	int w;
	int exist;
};

int N, M, D;
vector<E> edges;

bool cmp(E a, E b)
{
	return a.w < b.w || (a.w == b.w && a.exist < b.exist);
}

int main()
{
	scanf("%d %d %d", &N, &M, &D);
	for(int i = 0, A, B, C; i < M; i++)
	{
		scanf("%d %d %d", &A, &B, &C);
		if(i >= N - 1)
			edges.push_back({A, B, C, 1});
		else
			edges.push_back({A, B, C, 0});
	}

	sort(edges.begin(), edges.end(), cmp);
	dset ds(M + 1);
	int cnt = 0;
	int e = 0;
	int last = 0;
	int maxw = 0;
	for(int i = 0; i < M; i++)
	{
		int u = edges[i].u;
		int v = edges[i].v;
		//printf("%d %d %d %d\n", u, v, edges[i].w, edges[i].exist);
		int set_u = ds.find_set(u);
		int set_v = ds.find_set(v);
		if(set_u != set_v)
		{
			last = i;
			ds.union_set(set_u, set_v);
			e++;
			maxw = edges[i].w;
			if(edges[i].exist)
				cnt += 1;
		}
	}

	if(edges[last].exist)
	{
		dset ds1(M + 1);
		for(int i = 0; i < M; i++)
		{
			int u = edges[i].u;
			int v = edges[i].v;
			int set_u = ds1.find_set(u);
			int set_v = ds1.find_set(v);
			if(set_u != set_v)
			{
				if(edges[i].w < maxw || (edges[i].w == maxw && !edges[i].exist))
					ds1.union_set(set_u, set_v);
				else if(!edges[i].exist && edges[i].w <= D)
				{
					cout << cnt - 1;
					return 0;
				}
			}
		}
	}
	cout << cnt;
}