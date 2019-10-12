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
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int N, K, a[5004], g[5004];
vector<vec> v;

// Note: "All contestants are going to have distinct levels of skill."

int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
		v.push_back({a[i],i});
	}
	sort(v.begin(), v.end(), [](vec a, vec b) { return a.x < b.x; });
	for(int i = 1; i <= N; i++)
		g[v[i].y] = i/N+1;
	
}
