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

int N;
ll a[1000006], dp[1000006];

ll f(int i)
{
	if(i <= 0) return 0;
	if(dp[i] != 0) return dp[i];
	return dp[i] = max(f(i-1), f(i-2)+a[i]);
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &a[i]);
	printf("%lld", f(N));
}
