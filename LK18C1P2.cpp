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

ll N;//, L;

int main()
{
	scanf("%lld", &N);
	//L = (N + 1)/2;
	//printf("%lld", (N + 1)*(2*L - N) - 2*L*(L + 1) + N*(N + 1));
	// Factored and simplified!!
	printf("%lld", (((N + 1) >> 1) << 1) * (N - ((N + 1) >> 1)));
}