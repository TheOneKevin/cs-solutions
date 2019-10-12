#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define ilog2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define loop(x, a, b) for(int x = a; x < b; x++)
#define sc(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
typedef long long ll;
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

int N, K, h[100105], dp[100105];

int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%d", &h[i]);
	dp[2] = abs(h[2]-h[1]);
	for(int i = 2; i <= N; i++)
	{
		dp[i] = INF;
		for(int k = 1; k <= K && i != k; k++)
			dp[i] = min(dp[i], dp[i-k]+abs(h[i]-h[i-k]));
	}
	printf("%d", dp[N]);
}
