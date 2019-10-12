#include <bits/stdc++.h>
using namespace std;

int N, K, hi = 1e6, lo = 0;
int H[1001];

bool check(int mid)
{
	int sz = mid * 2;
	int ans = N;
	for(int i = 0; i < N && H[i] <= H[0] + sz; i++)
	{
		int cur = 1, end = H[i];
		for(int j = i + 1; j < N && H[j] < H[i] - sz + 1000000; j++)
			if(H[j] > end)
				end = H[j] + sz, cur++;
		ans = min(cur, ans);
	}
	
	return ans <= K;
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &H[i]);
	sort(H, H + N);
	scanf("%d", &K);
	int lo = 0, hi = 1e6, mid = 0, ans = 0;
	while(lo <= hi)
	{
		mid = (lo + hi) / 2;
		if(check(mid))
			ans = mid, hi = mid - 1;
		else
			lo = mid + 1;
	}
	
	printf("%d", ans);
}

/*

lo = 0, hi = 1e6
while(lo <= hi) {
	mid = (lo + hi) / 2;
	if(check(mid))
		ans = mid, hi = mid - 1;
	else
		lo = mid + 1;
}

bool check()
{
	do shit in here
}

*/
