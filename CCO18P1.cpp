#include <bits/stdc++.h>
using namespace std;
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
typedef pair<int, int> ip;

int A[1001], B[1001], N, dp[1001][1001];
bool S1[1001], S2[1001];

int main()
{
	scanf("%d ", &N);
	for(int i = 1; i <= N; i++) { char c; scanf("%c", &c); S1[i] = c == 'W'; }
	for(int i = 1; i <= N; i++) scanf("%d ", &A[i]);
	for(int i = 1; i <= N; i++) { char c; scanf("%c", &c); S2[i] = c == 'W'; }
	for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			int score = 0;
			if((A[i] > B[j] && S1[i] && !S2[j]) || (A[i] < B[j] && !S1[i] && S2[j]))
				score = dp[i - 1][j - 1] + A[i] + B[j];
			else
				score = dp[i - 1][j - 1];
			score = max(dp[i - 1][j], score);
			score = max(dp[i][j - 1], score);
			dp[i][j] = score;
		}
	}
	
	printf("%d", dp[N][N]);
}
