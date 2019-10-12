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

int W, H, N;
int arr[252][252];

int main()
{
	scanf("%d %d %d", &W, &H, &N);
	for(int y = 1; y <= H; y++)
	{
	    for(int x = 1, a; x <= W; x++)
	    {
			scanf("%d", &a);
			arr[x][y] = arr[x - 1][y] + arr[x][y - 1] - arr[x - 1][y - 1] + a;
		}
	}
	int ans = 0;
	for(int w = 1; w <= N; w++)
	{
		for(int x1 = 0; x1 < W; x1++)
		{
			for(int y1 = 0; y1 < H; y1++)
			{
				int h = N / w; int x2 = x1 + w, y2 = y1 + h;
				if(x2 > W || y2 > H) break;
				ans = max(ans, arr[x2][y2] - arr[x1][y2] - arr[x2][y1] + arr[x1][y1]);
			}
		}
	}
	
	printf("%d\n", ans);
}