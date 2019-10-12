#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define ilog2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define loop(x, a, b) for(int x = a; x < b; x++)
#define sc(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
typedef long long ll;
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

struct node
{
	int a, b, i, l;
};

int N, M, s, t, cr;
vector<node> g;
vector<int> res;
int pre[1000006];
bool vis[1000006];

int main()
{
	scanf("%d %d", &N, &M);
	queue<node> q;
	g.push_back({0,0,0,0});
	for(int i = 0, a, b; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		if(i == 0) s = a;
		if(i == M - 1) t = b;
		// Add all nodes
		g.push_back({ a, b, i+1, 0 });
		// Find all possible starting points
		if(a == s) q.push({ a, b, i+1, 1 }), pre[i+1] = 0;
	}
	
	//printf("st %d %d\n", s, t);
	
	// BFS
	while(!q.empty())
	{
		node v = q.front(); q.pop();
		if(v.b == t)
		{
			res.push_back(v.i);
			cr = v.i;
			printf("%d\n", v.l);
			break;
		}
		for(int i = v.i; i <= M; i++)
		{
			if(v.b == g[i].a && !vis[i])
			{
				q.push({ g[i].a, g[i].b, i, v.l+1 });
				pre[i] = v.i;
				vis[i] = true;
			}
		}
	}
	
	pre[0] = -1;
	//for(int i = 0; i <= M; i++) cout << pre[i] << endl;
	while(pre[cr] != 0)
	{
		printf("%d %d\n", g[pre[cr]].a, g[pre[cr]].b);
		res.push_back(pre[cr]);
		cr = pre[cr];
	}
}
