#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ip;

int D, F, T, wt[1002], ans[1002];
int _time[1002];
vector<int>  adj[1002];
priority_queue<ip, vector<ip>, greater<ip>> q;

void bfs()
{
	q.push({0, 0});
	
	while(!q.empty())
	{
		int t = q.top().first;
		int v = q.top().second;
		q.pop();
		if(_time[v] + wt[v] >= t) continue;
		if(t > T) continue;
		_time[v] = t;
		ans[v]++;
		for(int u : adj[v])
			q.push({ wt[u] + t, u });
	}
	
	for(int i = 0; i < D; i++)
		printf("%d\n", ans[i]);
}

int main()
{
	fill_n(_time, 1002, -0x3f3f3f);
	scanf("%d", &D);
	for(int i = 0; i < D; i++)
		scanf("%d", &wt[i]);
	scanf("%d", &F);
	for(int i = 0, a, b; i < F; i++)
		scanf("%d %d", &a, &b), adj[a - 1].push_back(b - 1);
	scanf("%d", &T);
	bfs();
}
