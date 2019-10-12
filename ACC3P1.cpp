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

int N, K, a[1000006], cnt[1000006];

int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++) scanf("%d", &a[i]);
	int l = -1, r = 0, num = 1;
	ll res = 0;
	cnt[a[0]] = 1;
	
	while(l++ < N - 1)
	{
		// While we have less than K elements,
		// increase the right pointer until we do.
		while(num < K && r++ < N - 1)
		{
			// Increase count every time we encounter an array
			// that has less than K elements
			if(!cnt[a[r]]) num++;
			cnt[a[r]]++;
		}
		// The remainder is the answer
		if(num == K) res += N - r;
		if(cnt[a[l]] == 1) num--;
		// Decrease the frequency at the removed element by 1
		cnt[a[l]]--;
	}
	
	printf("%lld\n", res);
}