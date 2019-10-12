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
#define mod 1000000007
#define smod(a,b) (((a)%mod-(b)%mod+mod)%mod)
#define amod(a,b) (((a)%mod+(b)%mod)%mod)
typedef long long ll;
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

int N, C, dp[1003][10004];

int main()
{
	scanf("%d %d", &N, &C);
	for(int i = 1; i <= N; i++) dp[i][0]=1;
	for(int i = 2; i <= N; i++)
		for(int j = 0; j <= C; j++)
			dp[i][j+1]=amod(dp[i][j],smod(dp[i-1][j+1],dp[i-1][max(0,j-i+1)]));
	printf("%d", smod(dp[N][C],dp[N][C+1]));
}