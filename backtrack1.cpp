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

int N;
ll dp[64][64];

ll f(int s, int n)
{
	ll cnt = 0;
	if(dp[s][n] != -1) return dp[s][n];
	if(s < 0 || n < 0) return dp[s][n]=0;
	if(2*s <= N) cnt++;
	for(int i = 1; i <= n/2; i++)
		cnt += f(i+s, n-i);
	return dp[s][n]=cnt;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	printf("%lld", f(0, N));
}
