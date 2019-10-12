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

ll N, M, Q, BT1[200005], BT2[200005]; // Lol I misread the question constraints

void add(ll* BT, ll x, ll a)
{
	for(ll i = x; i <= N; i += LSB(i))
		BT[i] += a;
}

ll sum(ll* BT, ll x)
{
	ll sum = 0;
	for(ll i = x; i > 0; i -= LSB(i))
		sum += BT[i];
	return sum;
}

void addRange(ll l, ll r, ll a)
{
	add(BT1, l, a);
	add(BT1, r + 1, -a);
	add(BT2, l, a * (l - 1));
	add(BT2, r + 1, -a * r);
}

ll sumRange(ll l, ll r)
{
	return sum(BT1, r) * r - sum(BT2, r) - sum(BT1, l - 1) * (l - 1) + sum(BT2, l - 1);
}

int main()
{
	scanf("%lld %lld %lld", &M, &N, &Q);
	for(ll i = 1, a; i <= N; i++)
	{
		scanf("%lld", &a);
		addRange(i, i, a);
	}
	for(ll i = 0, c, l, r, x; i < Q; i++)
	{
		scanf("%lld %lld %lld", &c, &l, &r);
		if(c == 1)
		{
			scanf("%lld", &x);
			addRange(l, r, x);
		}
		
		else if(c == 2)
			printf("%lld\n", sumRange(l, r) % M);
	}
}
