#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define MOD 1000000007 // Change me!
#define lsb(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define ilog2(n) sizeof(int)*8-__builtin_clz(n)-1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define ff first
#define ss second
#define sc(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define smod(a,b) (((a)%MOD-(b)%MOD+MOD)%MOD)
#define amod(a,b) (((a)%MOD+(b)%MOD)%MOD)
typedef long long ll;
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

int N;
unordered_map<int,ll> dp;

ll f(int w)
{
	if(w == 1 || w == 2) return 1;
	if (dp.find(w) != dp.end()) return dp[w];
	ll ans = 0;
	for(int k = w; k >= 2; k=w/(w/k+1))
		ans += (k-w/(w/k+1))*f(w/k);
	//cout << w << " " << k << endl;
	return dp[w] = ans;
}

int main()
{
	scanf("%d", &N);
	printf("%lld", f(N));
}