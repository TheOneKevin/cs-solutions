#include <bits/stdc++.h>
using namespace std;

int N, M;
int p[100001];

bool check(int sz)
{
	int st = p[0];
	int cur = 1;
	for(int i = 1; i < N; i++)
	{
		if(p[i] - st >= sz)
		{
			st = p[i];
			cur++;
			if(cur >= M) return true;
		}
	}
	return false;
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%d", &p[i]);
	sort(p, p + N);
	int l = p[0], r = p[N - 1], mid = 0, ans = -1;
	while(l < r)
	{
		mid = (l + r) / 2;
		if(check(mid))
			ans = max(ans, mid), l = mid + 1;
		else
			r = mid;
	}
	printf("%d", ans);
}
