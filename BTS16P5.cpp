#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb(n)  ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(int)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
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
typedef struct{int u,w;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int N, C, K, cc[100005], cnt;
vector<vec> g[100005];

vec f(int u, int w)
{
	vec res = {cc[u],w};
	for(vec v : g[u])
	{
		vec ret = f(v.u, v.w);
		res.u += ret.u, res.w += ret.w;
	}
	if(u != 1)
	{
		//cout << res.u << " " << res.w << endl;
		if(res.u >= C && res.w <= K)
			cnt++;
	}
	return res;
}

int main()
{
	scanf("%d %d %d", &N, &C, &K);
	for(int i = 1; i <= N; i++)
		scanf("%d", &cc[i]);
	for(int i = 1, a, b, c; i <= N-1; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		g[a].push_back({b, c});
	}
	vec r = f(1, 0);
	//cout << r.u << " " << r.w << endl;
	printf("%d\n", cnt);
}
