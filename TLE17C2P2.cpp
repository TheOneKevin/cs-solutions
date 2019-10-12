#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
typedef pair<int, int> ip;

int BIT[1000001], N, K;

int sum(int n)
{
	int res = 0;
	for(int i = n; i > 0; i -= LSB(i))
		res += BIT[i];
	return res;
}

void add(int n, int k)
{
	for(int i = n; i <= 1000000; i += LSB(i))
		BIT[i] += k;
}

int main()
{
	scanf("%d", &K);
	for(int i = 0, a; i < K; i++)
	{
		scanf("%d", &a);
		add(a, 1);
	}
	scanf("%d", &N);
	for(int i = 0, a; i < N; i++)
	{
		scanf("%d", &a);
		printf("%d\n", a - sum(a));
	}
}

