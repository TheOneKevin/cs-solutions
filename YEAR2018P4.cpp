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
typedef long long ll;

ll L, R, d[20], dp[20][164][2];

ll doit(ll p, ll s, ll y, bool tightpants)
{
	if(p < 0) return s == y ? 1 : 0;
	if(dp[p][s][tightpants] != -1) return dp[p][s][tightpants];
	ll up = tightpants ? d[p] : 9;
	ll cnt = 0;
	for(ll i = 0; i <= up; i++)
		cnt += doit(p - 1, s + i, y, tightpants && i == d[p]);
	return dp[p][s][tightpants] = cnt;
}

ll f(ll x, ll y)
{
	memset(dp, -1, sizeof(dp));
	memset(d, 0, sizeof(d));
	int n = 0;
	for(; x != 0; x /= 10) d[n++] = x % 10;
	return doit(n - 1, 0, y, true);
}

int main()
{
	scanf("%lld %lld", &L, &R);
	int cnt = 0;
	for(ll y = 1; y < 163; y++)
		if(f(R, y) - f(L - 1, y) != 0)
			cnt++;
	printf("%d", cnt);
}
