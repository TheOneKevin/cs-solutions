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
#define amod(a,b) (((a)%MOD+(b)%MOD)%MOD)
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int N, K, a[100005];
ll ans, dp[100005][51];

ll f(int n, int k)
{
	if(dp[n][k] != -1) return dp[n][k];
	if(n == 0 || k == 0 || n == k) return dp[n][k]=1;
	return dp[n][k]=amod(f(n-1, k-1),f(n-1,k));
}

int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	sort(a, a+N);
	memset(dp, -1, sizeof(dp));
	for(int i = K-1; i < N; i++)
		ans = amod(ans, a[i]*f(i,K-1));
	printf("%lld", ans);
}
