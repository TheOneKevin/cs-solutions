#include <bits/stdc++.h>
using namespace std;

typedef long ll;

ll N, K;

int main()
{
	scanf("%lld %lld", &N, &K);
	if(K * K < N)
		printf("-1");
	else
	{
		for(int i = 0, d = 0; i < (N + K - 1) / K; i++)
		{
			int sz = min(K, N - d);
			for(int j = 0; j < sz; j++, d++)
				printf("%d ", sz + i * K - j);
		}
	}
}
