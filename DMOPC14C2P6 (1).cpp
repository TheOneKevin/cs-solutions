#include <bits/stdc++.h>
using namespace std;
#define LSB(n) ((n) & -(n))

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
long long BIT[100002], ans[100002];
query q[200006];

long long sum(int n)
{
	long long sum = 0;
	for(int i = n; i > 0; i -= LSB(i))
		sum += BIT[i];
	return sum;
}

void add(int n, int k)
{
	for(int i = n; i <= N; i += LSB(i))
		BIT[i] += k;
}

int main()
{
	scanf("%d", &N);
	for(int i = 1, a; i <= N; i++)
		scanf("%d", &a), q[i] = {i, 0, 0, 0, a};
	scanf("%d", &Q);
	for(int i = 1, l, r, k; i <= Q; i++)
		scanf("%d %d %d", &l, &r, &k), q[N + i] = {0, i, l + 1, r + 1, k};
	sort(q + 1, q + N + Q + 1, comp);
	//printf("H\n");
	for(int i = 1; i <= N + Q; i++)
	{
		if(q[i].j != 0)
			ans[q[i].j] = sum(q[i].r) - sum(q[i].l - 1);
		else
			add(q[i].i, q[i].k);
	}
	for(int i = 1; i <= Q; i++)
		printf("%lld\n", ans[i]);
}
