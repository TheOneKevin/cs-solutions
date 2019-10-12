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

struct bus
{
	int d, i;
}

bool cmp(bus a, bus b)
{
	if(a.d == b.d) return a.i < b.i;
	return a.d < b.d;
}

priority_queue<bus, vector<bus>, decltype(&cmp)> bs(cmp);
vector<ip> ps;
int N, M, cur, pass[50005];
set<int> stp[50005];
set<int> dst[50005];

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0, s, f; i < M; i++)
	{
		scanf("%d %d", &s, &f);
		ps.push_back({s,f});
	}
	cur = 1;
	for(ip p : ps)
	{
		bus b = bs.top();
		if(pass[b.i] > 40)
		{
			cur++;
			bs.push_back({cur*10, cur});
			b = bs.top();
		}
		stp[b.i].push_back(p.ff);
		dst[b.i].push_back(p.ss);
		if(dst[b.i].find(p.ff) != dst[b.i].end())
			stp[b.i].push_back(p.ff);
	}
}
