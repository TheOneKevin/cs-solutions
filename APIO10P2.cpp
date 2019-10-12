#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define ff first
#define ss second
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int N, K, d1[100005], d2[100005], ch1[100005], ch2[100005], dia;
//unordered_map<ip, int> adj;
vector<ip> g[100005];

void dfs(int u, int pa)
{
	d1[u] = 0, d2[u] = 0;
	ch1[u] = -1, ch2[u] = -1;
	for(ip v : g[u])
	{
		if(v.ff == pa) continue;
		dfs(v.ff, u);
		if(d1[v.ff]+v.ss > d1[u])
		{
			d2[u] = d1[u];
			d1[u] = d1[v.ff]+v.ss;
			ch1[u] = v.ff;
		}
		else if(d1[v.ff]+v.ss > d2[u])
		{
			d2[u] = d1[v.ff]+v.ss;
			ch2[u] = v.ff;
		}
	}
	if(ch2[u] == -1)
	{
		for(ip v : g[u])
		{
			if(v.ff != ch1[u] && v.ff != pa)
			{
				ch2[u] = v.ff;
				break;
			}
		}
	}
	
	dia = max(dia, d1[u]+d2[u]);
}

int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 0, a, b; i < N-1; i++)
	{
		scanf("%d %d", &a, &b);
		//adj[{a, b}] = 1; adj[{b, a}] = 1;
		g[a].push_back({b,1});
		g[b].push_back({a,1});
	}
	dfs(1, -1);
	cout << 2*(N-1)-dia+1 << endl;
	for(int i = 1; i < N; i++) cout << ch1[i] << " ";
	cout << endl;
	for(int i = 1; i < N; i++) cout << ch2[i] << " ";
}

/*
 * 1) Find diameter of tree for K=1
 * 2) Answer = 2*(N-1)-diameter+1
 * 3) For K=2, mark all edges along diameter as -1
 * 4) Find diameter of weighted tree with DP
 * 5) Answer = Answer-diameter2+1
*/