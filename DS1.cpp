#include <bits/stdc++.h>
using namespace std;

#define LSB(n) ((n) & -(n))

int N, M, A[100002];
long long B[100002], C[100002];

long long sum(long long* BT, int i)
{
	long long sum = 0;
	while(i > 0)
		sum += BT[i], i -= LSB(i);
	return sum;
}

void add(long long* BT, int i, int k)
{
	while(i < 100002)
		BT[i] += k, i += LSB(i);
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d ", &A[i]);
		add(B, i, A[i]);
		add(C, A[i], 1);
	}
	for(int j = 0; j < M; j++)
	{
		char c;
		int i, k;
		scanf(" %c", &c);
		if(c == 'C')
		{
			scanf("%d %d", &i, &k);
			add(B, i, k - A[i]);
			add(C, A[i], -1);
			add(C, k, 1);
			A[i] = k;
		}
		else if(c == 'S')
		{
			scanf("%d %d", &i, &k);
			printf("%lld\n", sum(B, k) - sum(B, i - 1));
		}
		else if(c == 'Q')
		{
			scanf("%d", &i);
			printf("%lld\n", sum(C, i));
		}
	}
}
