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

int A, B, N;
ll dp[42];
int m1[] = { 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000 };
vector<int> m(m1, m1+sizeof(m1)/sizeof(int));

bool isBetween(int a, int b)
{
	return abs(a-b) >= A && abs(a-b) <= B;
}

int main()
{
	scanf("%d %d %d", &A, &B, &N);
	for(int i = 1, m2; i <= N; i++) { scanf("%d", &m2); m.push_back(m2); }
	sort(m.begin(), m.end());
	N = m.size();
	for(int i = 0; i <= N; i++)
		if(isBetween(m[0], m[i]))
			dp[i] = 1;
	for(int i = 1; i <= N-1; i++)
		for(int j = 1; j <= i; j++)
			if(isBetween(m[i], m[i-j]))
				dp[i] += dp[i-j];
	printf("%lld\n", dp[N-1]);
	//for(int i = 0; i < 42; i++) printf("%d ", dp[i]);
}
