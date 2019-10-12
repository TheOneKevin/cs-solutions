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

int N, ff[4];
double dp[302][302][302];

double f(int a, int b, int c)
{
	if(a+b+c==0) return 0;
	if(dp[a][b][c]!=0)return dp[a][b][c];
	double ans = (double)(N-a-b-c)/(a+b+c);
	if(a>0) ans += a*(f(a-1,b  ,c)+1)/(double)(a+b+c);
	if(b>0) ans += b*(f(a+1,b-1,c)+1)/(double)(a+b+c);
	if(c>0) ans += c*(f(a,b+1,c-1)+1)/(double)(a+b+c);
	return dp[a][b][c]=ans;
}

int main()
{
	cintie(0);
	cin >> N;
	for(int i = 0, a; i < N; i++)
	{
		cin >> a;
		ff[a]++;
	}
	cout.precision(10);
	cout << f(ff[1],ff[2],ff[3]);
}