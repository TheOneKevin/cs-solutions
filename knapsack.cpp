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

int N, M, cnt[5005];
ll dp[5005], ans = -INF;

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 1, n, w, v; i <= N; i++)
	{
		scanf("%d %d %d", &n, &w, &v);
		memset(cnt, 0, sizeof(cnt));
		for(int j = w; j <= 5000; j++)
			if(dp[j-w]+v > dp[j] && cnt[j-w]+1 <= n)
				dp[j] = dp[j-w]+v, cnt[j] += cnt[j-w]+1;
	}
	// PrOP
	for(int i = 1; i <= 5000; i++) dp[i] = max(dp[i], dp[i-1]);
	for(int i = 1, c, f; i <= M; i++)
	{
		scanf("%d %d", &c, &f);
		ans = max(ans, dp[c] - f);
	}
	printf("%d", ans);
}
