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
typedef struct{ll x,y;}vec;
typedef pair<int, int> ip;

int N, cx, cy;
ll ans;
map<ll, int> mx, my;
vector<vec> vc;
vector<int> px[100005], py[100005];

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		ll x, y;
		scanf("%lld %lld", &x, &y);
		mx.emplace(x, 1), my.emplace(y, 1);
		vc.push_back({x,y});
	}
	
	for(auto c : mx) mx[c.first]=++cx;
	for(auto c : my) my[c.first]=++cy;
	for(auto e : vc) px[mx[e.x]].push_back(my[e.y]),
					 py[my[e.y]].push_back(mx[e.x]);
	for(int i = 0; i < 100000; i++)
		sort(px[i].begin(), px[i].end()), sort(py[i].begin(), py[i].end());
	
	for(vec e : vc)
	{
		int x = mx[e.x], y = my[e.y];
		auto lx = lower_bound(px[x].begin(), px[x].end(), y);
		auto ly = lower_bound(py[y].begin(), py[y].end(), x);
		ans+=(lx-px[x].begin())*(px[x].end()-lx-1)*(ly-py[y].begin())*(py[y].end()-ly-1)*2;
	}
	
	printf("%lld", ans);
}
