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

typedef pair<int, int> ip;
typedef long long ll;

int N, M, A[402][402];

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			char c;
			scanf(" %c", &c);
			A[i][j] = c == '.' ? 1 : 0;
			A[i][j] += A[i][j - 1];
		}
	}
	int ans = 0;
	for(int i = 1; i <= M; i++)
	{
		for(int j = i; j <= M; j++)
		{
			int len = j - i + 1, mx = 0, cnt = 0;
			for(int l = 1; l <= N; l++)
			{
				if(A[l][j] - A[l][i - 1] != len)
					cnt = 0;
				else
				{
					cnt++;
					mx = max(mx, cnt);
				}
			}
			
			if(mx > 0) ans = max(ans, mx + len);
		}
	}
	
	printf("%d", 2 * ans - 1);
}
