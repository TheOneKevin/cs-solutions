#include <bits/stdc++.h>
using namespace std;
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
typedef pair<int, int> ip;

int N, Q;
ip A[pow2(21) + 1];

int main()
{
	scanf("%d %d", &N, &Q);
	N = pow2(N);
	for(int i = 1, a; i <= N; i++)
		scanf("%d", &a), A[N + i - 1] = { a, i };
	for(int i = N - 1; i > 0; i--)
		A[i] = max(A[2 * i], A[2 * i + 1]);
	for(int id = 0, i, S; id < Q; id++)
	{
		char c;
		scanf(" %c", &c);
		if(c == 'R')
		{
			scanf("%d %d", &i, &S);
			A[i + N - 1].second = S;
			for(int j = (i + N - 1) / 2; j > 0; j /= 2)
				A[j] = max(A[2 * j], A[2 * j + 1]);
		}
		
		else if(c == 'W')
		{
			printf(" - %d\n", A[1].second);
		}
		
		else if(c == 'S')
		{
			scanf("%d", &i);
			int cnt = 0;
			for(int j = (i + N - 1) / 2; j >= 1; j /= 2)
				if(A[j] == A[i + N - 1]) cnt++;
				else break;
			printf(" - %d\n", cnt);
		}
	}
}