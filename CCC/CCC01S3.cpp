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

// CCC '01 S3 - Strategic Bombing
int cnt;
vector<int> g[27];
vector<ip> edges;
bool vis[752]; // Probably way more than needed

bool bfs(ip ex) // Exclude edge
{
	queue<int> q;
	q.push(0);
	memset(vis, 0, sizeof(vis));
	vis[0] = true;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(u == 1) return true;
		for(int v : g[u])
		{
			if(vis[v]) continue;
			if((ex.first == u && ex.second == v) || (ex.first == v && ex.second == u))
				continue;
			q.push(v);
			vis[v] = true;
		}
	}
	
	return vis[1];
}

int main()
{
	char a = 0, b = 0;
	while(true)
	{
		scanf(" %c%c", &a, &b);
		if(a == '*')
			break;
		a -= 'A';
		b -= 'A';
		g[a].push_back(b);
		g[b].push_back(a);
		edges.push_back({ a, b });
	}
	
	for(ip e : edges)
	{
		if(!bfs(e))
		{
			printf("%c%c\n", e.first + 'A', e.second + 'A');
			cnt++;
		}
	}
	printf("There are %d disconnecting roads.", cnt);
}
