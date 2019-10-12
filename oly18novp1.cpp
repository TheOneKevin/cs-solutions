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

int N;
ip A[1000005];

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d %d", &(A[i].first), &(A[i].second));
	sort(A, A + N, [](ip a, ip b)
	{
		return a.second < b.second;
	});
	// Please work :((
	int ans = 0, cur = 0;
	for(int i = 0; i < N; i++)
		if(A[i].first >= cur)
			ans++, cur = A[i].second;
	printf("%d", ans);
}
