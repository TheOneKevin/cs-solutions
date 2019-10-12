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
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

int N, W, w[102];
ll v[102], p[102], dp[100005];

int main()
{
	scanf("%d %d", &N, &W);
	for(int i = 1; i <= N; i++) { scanf("%d %lld", &w[i], &v[i]); p[i] = p[i-1]+v[i]; }
	for(int i = 1; i <= N; i++)
		for(int j = W; j >= (int)max(W-p[N]+p[i-1],(ll)w[i]); j--)
			dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
	printf("%lld", dp[W]);
}
