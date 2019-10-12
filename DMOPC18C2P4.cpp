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

ll N, M, d[500005];

int main()
{
	scanf("%lld %lld", &N, &M);
	for(int i = 0; i < N; i++) scanf("%lld", &d[i]);
	ll l = 0, r = 0, len = INF, sum = 0;
	while(r < N && l < N)
	{
		while(sum < M && r < N) sum += d[r++];
		while(sum >= M && l < N) { len = min(len, r - l); sum -= d[l++]; }
	}
	
	printf("%lld", len > N ? -1 : len);
}
