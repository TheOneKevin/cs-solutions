#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb(n)  ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
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

int N, M, mn, a[1004], dp[1004];

bool check(int g, int r)
{
	
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < N; i++)
	{
		for(int j = 1; j < 2*(M+1) && i-j >= 0; j++)
		{
			for(int k = 1; k < j; k++)
				if(check(i-j, j-k) && check(i, j-k))
					break;
			mn = min(mn, i-j);
		}
		dp[i] = mn;
	}
}
