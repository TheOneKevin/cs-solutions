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

int N, W, w[102], v[102], vv;
ll dp[102][1003], ans;

int main()
{
	scanf("%d %d", &N, &W);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d %d", &w[i], &v[i]);
		vv = max(vv, v[i]);
	}
	memset(dp, INF, sizeof(dp));
	dp[0][0] = 0;
	for(int i = 1; i <= N; i++)
	{
		for(int j = 0; j <= 1000; j++)
		{
			dp[i][j] = dp[i-1][j];
			if(j >= v[i]) dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]]+w[i]);
		}
	}
	for(int i = 0; i <= 1003; i++)
		if(dp[N][i] <= W)
			ans = max(ans, (ll)i);
	printf("%lld", ans);
}
