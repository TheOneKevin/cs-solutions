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

int N, K, l, r, len, dif, a[200005];

int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++) scanf("%d", &a[i]);
	sort(a, a+N);
	l = 0, r = 0;
	while(l <= r && r < K)
	{
		if(a[r]-a[l] <= K)
		{
			r++;
			len = max(len, r-l+1);
		}
		else l++;
	}
	printf("%d", len);
}
