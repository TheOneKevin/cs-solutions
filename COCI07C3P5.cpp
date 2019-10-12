#include <bits/stdc++.h>
#include <climits>
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

ll L, R, Sm, n, aa = LLONG_MAX, d[16], dp[16][139][2];

ll fun(ll p, ll s, ll nu, bool tightpants)
{
	if(p < 0) {
		if(s == Sm) 
		{
			//cout << nu << endl;
			if(nu >= L && nu <= R)
				aa = min(aa, nu);
			return 1;
		}
		return 0;
	}
	//if(dp[p][s][tightpants] != -1) return dp[p][s][tightpants];
	ll up = tightpants ? d[p] : 9;
	ll cnt = 0;
	for(ll i = 0; i <= up; i++)
		cnt += fun(p - 1, s + i, nu + i * pow(10, p), tightpants && i == d[p]);
	return dp[p][s][tightpants] = cnt;
}

ll solve(ll x)
{
	memset(dp, -1, sizeof(dp));
	n = 0;
	for(; x != 0; x /= 10) d[n++] = x % 10;
	return fun(n - 1, 0, 0, true);
}

int main()
{
	scanf("%lld %lld %lld", &L, &R, &Sm);
	printf("%lld\n", solve(R) - solve(L - 1));
	int hi = R, lo = L;
	while(lo <= hi)
	{
		int m = mid(hi, lo);
		int p = solve(hi) - solve(m - 1);
		if(p != 0) lo = m;
		else hi = m - 1;
	}
	printf("%lld", aa);
}
