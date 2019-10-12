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

int N, a[30];
//bool dp[31][30001];
bool dp[30001];

int main()
{
	for(int z = 0; z < 5; z++)
	{
		scanf("%d", &N);
		int s = 0, m = INF;
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &a[i]);
			s += a[i];
		}
		
		//for(int i = 0; i <= N; i++) dp[i][0] = true;
		//for(int i = 1; i <= s; i++) dp[0][i] = false;
		
		memset(dp, false, 30001);
		dp[0] = true;
		for(int i = 0; i < N; i++)
			for(int j = s / 2; j >= a[i]; j--)
					dp[j] |= dp[j - a[i]];
		
		for(int j = s / 2; j >= 0; j--)
		{
			if(dp[j]) {
				m = s - 2 * j;
				break;
			}
		}
		printf("%d\n", m);
	}
}
