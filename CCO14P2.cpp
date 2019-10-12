#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb (n) ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(int)*8-__builtin_clz(n)-1
#define mid (n, m) (((m)+(n))/2)
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define sc(x) {do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
#define ff first
#define ss second
#define smod(a,b) (((a)%MOD-(b)%MOD+MOD)%MOD)
#define amod(a,b) (((a)%MOD+(b)%MOD)%MOD)
#define btst(a,b) ((a) & (1 << (b)))
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

// Find shortest path from A to B including some edge e_ij
// = Shortest path from A to e_i + B to e_j + e_ij

struct node
{
	int u, l, c;
	bool p;
};

int N, M, A, B, Q;
vector<node> g1[100005], g2[100005];
int d1[100005], d2[100005];
bool vis[100005];

int main()
{
	scanf("%d %d %d %d", &N, &M, &A, &B);
	for(int i = 1, x, y, l, c; i <= M; i++)
	{
		scanf("%d %d %d %d", &x, &y, &l, &c);
		g1[x].push_back({y,l,c});
		g2[y].push_back({x,l,c});
	}
	
	dij1();
	dij2();
	
	scanf("%d", &M);
	for(int i = 0, d; i < M; i++)
	{
		scanf("%d", &d);
	}
}
