#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb(n)  ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define ff first
#define ss second
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

struct query
{
	int i, j, l, r, k;
};

// a > b
bool comp(query a, query b)
{
	return a.k == b.k ? a.i > b.i : a.k > b.k;
	//if(a.k == b.k) return a.i > b.i;
	//return a.k > b.k;
}

int N, Q;
ll BIT[200002], ans[200002], psa[200002];
query q[400006];

ll sum(int n)
{
	ll sum = 0;
	for(int i = n; i > 0; i -= lsb(i))
		sum += BIT[i];
	return sum;
}

void add(int n, int k)
{
	for(int i = n; i <= N; i += lsb(i))
		BIT[i] += k;
}

int main()
{
	scanf("%d %d", &N, &Q);
	//printf("%d %d\n", N, Q);
	for(int i = 1; i <= N; i++)
	{
		scanf("%lld", &psa[i]);
		q[i] = {i, 0, 0, 0, psa[i]};
	}
	for(int i = 1; i <= N; i++) psa[i] += psa[i-1];
	for(int i = 1, l, r, k; i <= Q; i++)
	{
		scanf("%d %d %d", &l, &r, &k);
		q[N + i] = {0, i, l, r, k};
	}
	sort(q + 1, q + N + Q + 1, comp);
	//printf("H\n");
	for(int i = 1; i <= N + Q; i++)
	{
		if(q[i].j != 0)
			ans[q[i].j] = 2*(sum(q[i].r)-sum(q[i].l-1))-(psa[q[i].r]-psa[q[i].l-1]);
		else
			add(q[i].i, q[i].k);
	}
	for(int i = 1; i <= Q; i++)
		printf("%lld\n", ans[i]);
}