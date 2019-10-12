#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

lld N, res;

lld GCD(lld x, lld y)
{
	lld a = x, b = y;
	while(b != 0)
	{
		lld tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int main()
{
	scanf("%lld", &N);
	scanf("%lld", &res);
	for(lld i = 1, a; i < N; i++)
	{
		scanf("%lld", &a);
		res = GCD(a, res);
	}
	
	lld p = 2;
	lld ans = 0;
	while(p * p <= res)
	{
		if(res % p == 0)
			/*printf("%d ", p),*/ ans = p > ans ? p : ans, res = res / p;
		else
			p++;
	}
	
	//printf("%d ", res);
	ans = res > ans ? res : ans;
	
	if(ans != 1)
		printf("%lld", ans);
	else
		printf("DNE");
}
