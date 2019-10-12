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

int N, m[10001];

int main()
{
	for(int _ = 0, M; _ < 5; _++)
	{
		scanf("%d", &N);
		M = N;
		for(; M > 1; M--)
		{
			int p = 2;
			N = M;
			while(N >= p * p)
			{
				if(N % p == 0)
					m[p]++, N /= p;
				else
					p++;
			}
			m[N]++;
		}
		bool doit = false;
		for(int i = 2; i < 10001; i++)
		{
			if(m[i] != 0)
			{
				if(doit)
					printf(" * ");
				printf("%d^%d", i, m[i]);
				doit = true;
			}
		}
		printf("\n");
		memset(m, 0, sizeof(m));
	}
}
