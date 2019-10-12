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

int A[100005], N, M, lo, hi; // lower and upper bounds of our search space

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		hi += A[i];
		lo = max(A[i], lo);
	}
	
	while(lo < hi)
	{
		int m = mid(lo, hi);
		int p = 1, t = 0; // Find p, # of partitions for target sum (m)
		for(int i = 0; i < N; i++)
		{
			t += A[i];
			if(t > m) t = A[i], p++; // We greedily find all the best fit partitions in A
		}
		
		if(p <= M) hi = m;
		else lo = m + 1;
	}
	
	printf("%d", lo);
}
