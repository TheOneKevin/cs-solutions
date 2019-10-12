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
typedef struct{int i; ll v;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

ll N, K, ans, psa[200005];
deque<vec> dq;

int main()
{
	scanf("%lld %lld", &N, &K);
	for(int i = 1; i <= N; i++)
	{
		scanf("%lld", &psa[i]);
		psa[i+N] = psa[i];
	}
	for(int i = 1; i <= 2*N; i++)
		psa[i]+=psa[i-1];
	for(int i = 1; i <= 2*N; i++)
	{
		ans = max(ans, psa[i]-psa[i-1]);
		if(psa[i] <= 0) dq.push_back({i, psa[i]});
		while(!dq.empty() && abs(i-dq.front().i) > K)
			dq.pop_front();
		ans = max(ans, psa[i]-dq.front().v);
		while(!dq.empty() && dq.back().v >= psa[i])
			dq.pop_back();
		dq.push_back({i, psa[i]});
	}
	printf("%lld", ans);
}
