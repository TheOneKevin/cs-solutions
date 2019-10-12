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
typedef struct{ll x; int y;}vec;
typedef pair<ll, int> ip;

int N, M, K, X, res[200005], c;
ip f[200005];

int main()
{
	scanf("%d %d %d %d", &N, &M, &K, &X);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &f[i].first);
		f[i].second = i;
	}
	sort(f + 1, f + N + 1);
	for(int i = 1; i <= N; i++)
		f[i].first += f[i - 1].first;
	if(f[X - 1].first >= K || f[N].first - f[N - X].first < K) { printf("-1\n"); return 0; }
	for(int r = X; r <= N; r++)
	{
		ll s = f[r].first - f[r - X].first;
		if(s >= K)
		{
			for(int j = i; j <= N; j++) res[f[j].second] = ++c;
			for(int j = 1; j < i; j++) res[f[j].second] = ++c;
			for(int j = 1; j <= N; j++) printf("%d ", ans[j]);
			return 0;
		}
	}
}
