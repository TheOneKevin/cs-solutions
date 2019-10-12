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

int H, D, E, T, B[2003], S[6];
double A[6], dp[2003][6];

int main()
{
	for(int i = 0; i < 1003; i++) for(int j = 0; j < 6; j++) dp[i][j] = 99999;
	scanf("%d %d %d", &H, &D, &E);
	for(int i = 1, a; i <= D; i++)
	{
		scanf("%d %d", &a, &S[i]);
		A[i] = 1.0 - ((double) a / 100.0);
	}
	A[0] = 1;
	for(int i = 0, t, l, x; i < E; i++)
	{
		scanf("%d %d %d", &t, &l, &x);
		t++;
		B[t] += x, B[t+l] -= x;
		T = max(T, t+l);
	}
	for(int i = 1; i < T; i++) B[i] += B[i-1];
	dp[0][0] = 0, dp[0][1] = 0, dp[0][2] = 0, dp[0][3] = 0, dp[0][4] = 0, dp[0][5] = 0;
	for(int i = 1; i < T; i++)
	{
		double m = INF;
		for(int j = 0; j <= D; j++) m = min(dp[i - 1][j], m);
		for(int j = 0; j <= D; j++)
			dp[i][j] = m + (B[i] - S[j] > 0 ? (double) B[i] - S[j] : 0) * A[j];
	}
	double ans = INF;
	for(int j = 0; j <= D; j++) ans = min(dp[T - 1][j], ans);
	if(H - ans <= 0)
		printf("DO A BARREL ROLL!");
	else
		printf("%.2f", H - ans);
}