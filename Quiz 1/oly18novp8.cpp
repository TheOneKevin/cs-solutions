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

int BIT[32002], m[15001], N, x, y;

int sum(int n)
{
	int res = 0;
	for(int i = n; i > 0; i -= LSB(i))
		res += BIT[i];
	return res;
}

void add(int n, int k)
{
	for(int i = n; i < 32002; i += LSB(i))
		BIT[i] += k;
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		m[sum(++x)]++;
		add(x, 1);
	}
	
	for(int i = 0; i < N; i++)
		printf("%d\n", m[i]);
}
