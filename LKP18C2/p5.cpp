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

int N, D, v[300005];
ll BIT[300005];

ll sum(int n)
{
	ll sum = 0;
	for(int i = n; i > 0; i -= LSB(i))
		sum += BIT[i];
	return sum;
}

void add(int n, int k)
{
	for(int i = n; i <= N; i += LSB(i))
		BIT[i] += (ll) k;
}

ll minColl()
{
	double M = (double) sum(N) / 2;
	//cout << M << endl;
	ll l = 0, r = 0, len = INF;
	double sum = 0;
	//for(int i = 1; i <= N; i++) printf("%d ", v[i-1]);
	while(r < N && l < N)
	{
		while(sum <= M && r < N) sum += v[r++];
		while(sum > M && l < N) { len = min(len, r - l); sum -= v[l++]; }
	}
	return len > N ? 0 : len;
}

int main()
{
	scanf("%d %d", &N, &D);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &v[i-1]);
		add(i, v[i-1]);
	}
	printf("%lld\n", minColl());
	for(int i = 0, a, b; i < D; i++)
	{
		scanf("%d %d", &a, &b);
		add(a, b-v[a-1]);
		v[a-1] = b;
		printf("%lld\n", minColl());
	}
}
