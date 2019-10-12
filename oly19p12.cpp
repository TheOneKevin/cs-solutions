#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
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

int N, K, psa[20004], dp[2][20004], mn[20004];

int main()
{
	memset(dp, -INF, sizeof(dp));
	for(int i = 0; i < 20004; i++) dp[0][i] = 0;
	scanf("%d %d", &N, &K);
	for(int i = 1, a; i <= N; i++)
	{
		scanf("%d", &a);
		psa[i] = psa[i-1] + a;
	}
	for(int k = 1; k <= K; k++)
	{
		for(int n = 1; n <= N; n++)
		{
			int mx = -INF;
			for(int j = 1; j <= n; j++)
		 		mx = max(mx, dp[(k-1)%2][j]+psa[n]-psa[j]);
			cout << dp[k%2][n-1] << " " << mx << endl;
			dp[k%2][n] = max(dp[k%2][n-1], mx);
		}
	}
	printf("%d", dp[K%2][N]);
}
