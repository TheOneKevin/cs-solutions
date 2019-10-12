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

int N, w[3][100005], dp[100005][5];

int f(int i, int j, int c)
{
	// Screw recursion
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d %d %d", &w[0][i], &w[1][i], &w[2][i]);
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(j == 0)
				dp[i][j] = max(dp[i-1][1]+w[1][i],dp[i-1][2]+w[2][i]);
			else if(j == 1)
				dp[i][j] = max(dp[i-1][0]+w[0][i],dp[i-1][2]+w[2][i]);
			else
				dp[i][j] = max(dp[i-1][0]+w[0][i],dp[i-1][1]+w[1][i]);
		}
	}
	
	printf("%d", max({dp[N][0],dp[N][1],dp[N][2]}));
}
