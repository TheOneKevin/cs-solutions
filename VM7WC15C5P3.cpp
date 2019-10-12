#include <bits/stdc++.h>
using namespace std;
#define LSB(n) ((n) & -(n))

/**
 * We can map the diagonals of a grid like so:
 *
 *          1 . .
 * 1 3 6    2 3 .
 * 2 5 8 -> 4 5 6
 * 4 7 9    . 7 8
 *          . . 9
 *
 * The coordinate on the original grid (x, y) will become
 * The coordinate on the new grid (x, x + y - 1)
 *
 * Patented Kevin technology (c) 2018 on a really hot September evening
 */

typedef long long int ll;

ll N;
ll BIT[5750][5750]; // [y][x]
ll ans;

ll sum(ll a, ll n)
{
	ll sum = 0;
	for(ll i = n; i > 0; i -= LSB(i)) sum += BIT[a][i];
	return sum;
}

void add(ll a, ll n, ll k)
{
	for(ll i = n; i <= N; i += LSB(i))
		BIT[a][i] += k;
}

int main()
{
	scanf("%lld", &N);
	for(ll i = 0, a, r, c, x; i < N; i++)
	{
		scanf("%lld %lld %lld %lld", &a, &r, &c, &x);
		if(a == 1)
			add(r + c, r, x);
		else
		{
			ans = ans % 1000000007ll + (sum(r + c, r) - sum(r + c, r - x - 1)) % 1000000007ll;
		    //ans = ans % 1000000007ll;
		}
	}
	printf("%lld\n", ans % 1000000007ll);
}