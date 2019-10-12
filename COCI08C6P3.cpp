#include <bits/stdc++.h>
using namespace std;

int N, M, ans = 1e9;
int pa[101][101];

void checkAllRects(int x1, int y1)
{
	for(int l = 1; l * l <= M; l++)
	{
		// If length is not a factor of M, we cannot make a rectangle with the length L
		if(M % l != 0) continue;
		
		int w = M / l;
		int x2 = x1 + l - 1;
		int y2 = y1 + w - 1;
		int nums = 0;
		
		if(x2 <= N && y2 <= N)
		{
			nums = pa[x2][y2] + pa[x1 - 1][y1 - 1] - pa[x2][y1 - 1] - pa[x1 - 1][y2];
			ans = min(M - nums, ans);
		}
		
		// Switcheroo
		x2 = x1 + w - 1;
		y2 = y1 + l - 1;
		if(x2 <= N && y2 <= N)
		{
			nums = pa[x2][y2] + pa[x1 - 1][y1 - 1] - pa[x2][y1 - 1] - pa[x1 - 1][y2];
			ans = min(M - nums, ans);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0, x, y; i < M; i++)
	{
		scanf("%d %d", &x, &y); pa[x][y] = 1;
	}
	
	for(int x = 1; x <= N; x++)
		for(int y = 1; y <= N; y++)
			pa[x][y] += pa[x - 1][y] + pa[x][y - 1] - pa[x - 1][y - 1];
	
	for(int x = 1; x <= N; x++)
		for(int y = 1; y <= N; y++)
			checkAllRects(x, y);
	printf("%d\n", ans);
}

// 2D prefix sum array
// a[r][c] = a[r - 1][c] + a[r][c - 1] - a[r - 1][c - 1] + val[r][c]
