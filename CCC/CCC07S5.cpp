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

int T, N, K, W;
int s[30004], dp[502][30004];

int main()
{
	scanf("%d", &T);
	for(int z = 1; z <= T; z++)
	{
		scanf("%d %d %d", &N, &K, &W);
	    memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= N; i++) scanf("%d", &s[i]);
		for(int i = 1; i <= K; i++)
		{
			for(int j = W; j <= N; j++)
			{
				int sum = 0;
				for(int k = j; k > j-W; k--) sum += s[k];
				dp[i][j] = max(dp[i-1][j-W] + sum, dp[i][j-1]);
			}
		}
	
		printf("%d\n", dp[K][N]);
	}
}