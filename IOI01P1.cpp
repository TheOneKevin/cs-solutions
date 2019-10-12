#include <bits/stdc++.h>
using namespace std;

#define LSB(n) ((n) & -(n))

int S, /*A[1026][1026],*/ BIT[1026][1026];

int sum(int x, int y)
{
	int sum = 0;
	for(int i = x; i > 0; i -= LSB(i))
		for(int j = y; j > 0; j -= LSB(j))
			sum += BIT[i][j];
	return sum;
}

int add(int x, int y, int a)
{
	for(int i = x; i <= S; i += LSB(i))
		for(int j = y; j <= S; j += LSB(j))
			BIT[i][j] += a;
}

int main()
{
	int instr;
	scanf("%d %d", &instr, &S);
	while(instr != 3)
	{
		scanf("%d", &instr);
		
		if(instr == 1){
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			x++; y++;
			add(x, y, z);
		}
		if(instr == 2){
			int L, B, R, T;
			scanf("%d %d %d %d", &L, &B, &R, &T);
			L++; B++; R++; T++;
			printf("%d\n", sum(R, T) - sum(R, B - 1) - sum(L - 1, T) + sum(L - 1, B - 1));
		}
	}
}
