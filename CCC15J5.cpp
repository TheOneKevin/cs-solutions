#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
typedef pair<int, int> ip;
typedef long long ll;

int A, B, dp[255][255];

int solve(int a, int b)
{
	if(a == 0 || b == 0) return 0;
    if(a == b) { dp[a][b] = 1; return 1; }
    else if((a - 1 < 0) || (b - 1 < 0) || (a - b < 0)) { dp[0][0] = 0; return 0; }
    else if((dp[a - 1][b - 1] == -1) && (dp[a - b][b] > -1))
        dp[a][b] = solve(a - 1, b - 1) + dp[a - b][b];
    else if((dp[a - b][b] == -1) && (dp[a - 1][b - 1] > -1))
        dp[a][b] = dp[a - 1][b - 1] + solve(a - b, b);
    else if((dp[a - b][b] > -1) && (dp[a - 1][b - 1] > -1))
        dp[a][b] = dp[a - 1][b - 1] + dp[a - b][b];
    else
        dp[a][b] = solve(a - 1, b - 1) + solve(a - b, b);

    return dp[a][b];
}

int main()
{
	scanf("%d %d", &A, &B);
	memset(dp, -1, sizeof(dp));
	printf("%d", solve(A, B));
}
