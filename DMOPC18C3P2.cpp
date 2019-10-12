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

int N, a[100001], b[100001], dp[100001][3];

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= N; i++) scanf("%d", &b[i]);
	dp[0][0] = 0, dp[1][0] = 0, dp[2][0] = 0;
	for(int i = 1; i <= N; i++)
	{
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + b[i],
		dp[i][1] = dp[i - 1][0] + a[i],
		dp[i][2] = dp[i - 1][1] + a[i];
	}
	
	printf("%d", max(dp[N][0], max(dp[N][1], dp[N][2])));
}
