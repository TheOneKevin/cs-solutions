#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb(n)  ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(int)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
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
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

string K;
int D, ret, d[10005], dp[10005][102][2];

ll f(int p, ll s, bool t)
{
	if(p < 0)
	{
		if(s % D == 0) return 1;
		return 0;
	}
	if(dp[p][s][t] != -1) return dp[p][s][t];
	int u = t ? d[p] : 9;
	ll c = 0;
	for(int i = 0; i <= u; i++)
		c = amod(c, f(p-1, (s+i)%D, t && i == d[p]));
	return dp[p][s][t] = c%MOD;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> K >> D;
	for(int i = K.length()-1; i >= 0; i--)
		d[i] = K[K.length()-1-i]-'0';
	cout << f(K.length()-1, 0, true)-1 << "\n";
}
