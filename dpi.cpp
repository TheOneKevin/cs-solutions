#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb (n) ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(int)*8-__builtin_clz(n)-1
#define mid (n, m) (((m)+(n))/2)
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define sc(x) {do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
#define ff first
#define ss second
#define smod(a,b) (((a)%MOD-(b)%MOD+MOD)%MOD)
#define amod(a,b) (((a)%MOD+(b)%MOD)%MOD)
#define btst(a,b) ((a) & (1 << (b)))
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

int N;
double p[3003], dp[3003][3003];
double dp1[3003];

double f(int i, int j)
{
	if(dp[i][j] != 0) return dp[i][j];
	if(i == 0 && j == 0) return dp[i][j] = 1;
	if(i <= 0) return dp[i][j] = 0;
	return dp[i][j]=f(i-1,j)*(1.0-p[i])+f(i-1,j-1)*p[i];
}

int main()
{
	cintie(0);
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> p[i];
	dp[0][0] = 1;
	for(int i = 1; i <= N; i++)
		for(int j = 0; j <= N; j++)
			dp[i][j]=dp[i-1][j]*(1.0-p[i])+dp[i-1][j-1]*p[i];
	double ans = 0;
	for(int i = N/2+1; i <= N; i++)
		ans += dp[N][i];
	cout.precision(10);
	cout << ans;
}