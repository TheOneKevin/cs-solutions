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

int N, K, ans, f[50004]; // Frequency of %K
ll ps;

int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 1, a; i <= N; i++) 
	{
		scanf("%d", &a);
		ps += a;
		f[ps%K]++;
	}
	
	for(int i = 0; i < K; i++)
		// Sum from 0 to k=f[i] = k(k-1)/2
		ans += (f[i]*f[i]-f[i])/2;
	ans += f[0];
	printf("%d", ans);
}
