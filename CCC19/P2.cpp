#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000000

int T, fct[MAXN+5];

int main()
{
	fct[1] = 1;
	for(int i = 2; i <= MAXN; i++) fct[i] = i;
	for(int i = 4; i < MAXN; i+=2) fct[i] = 2;
	for(int i = 3; i*i <= MAXN; i++)
		if(fct[i] == i)
			for(int j = i*i; j <= MAXN; j+=i)
				if(fct[j]==j)
					fct[j]=i;
	scanf("%d", &T);
	for(int i = 0, N; i < T; i++)
	{
		scanf("%d", &N);
		N *= 2;
		for(int B = 2; B <= MAXN; B++)
		{
			if(fct[B]==B && fct[N-B]==N-B)
			{
				printf("%d %d\n", N-B, B);
				break;
			}
		}
	}
}
