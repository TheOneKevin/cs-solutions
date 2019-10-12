#include <bits/stdc++.h>
using namespace std;

int N, l[2001], ans[4002];

int main()
{
	scanf("%d", &N);
	for(int i = 0, v; i < N; i++)
		scanf("%d", &v), l[v]++;
	for(int i = 1; i <= 2000; i++)
	{
		for(int j = i; j <= 2000; j++)
		{
			int t = min(l[i], l[j]);
			if(i == j) t = l[i] / 2;
			ans[i + j] += t;
		}
	}
	
	int res = 0, len = 0;
	
	for(int i = 1; i <= 4000; i++)
	{
		if(ans[i] == res)
		{
			len++;
			continue;
		}
		
		if(ans[i] > res)
			len = 1;
		
		res = max(res, ans[i]);
	}
	
	printf("%d %d", res, len);
}
