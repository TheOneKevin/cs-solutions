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

int N, pmx[1000006], smx[1000006], a[1000006];
ll ans;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= N; i++)
		pmx[i] = max(pmx[i-1], a[i]),
		smx[N-i+1] = max(smx[N-i+2], a[N-i+1]);
	for(int i = 1; i <= N; i++)
		ans += min(pmx[i], smx[i]) - a[i];
	printf("%lld", ans);
}
