#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define ilog2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define loop(x, a, b) for(int x = a; x <= b; x++)
typedef pair<int, int> ip;
typedef long long ll;

int N, A[101][101];

// Fucking Cayley tables and Light's Associativity Test
// O(N^3+3N^2) -> 1030000 iter. < 2 s -> No TLE !!
bool isValidGroup()
{
	// 1) Light's Associativity Test : O(N^3) -> 1000000
	// A[x][y] represents x*y, thus x*(y*z) = A[x][A[y][z]]
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			for(int k = 1; k <= N; k++)
				if(A[i][A[j][k]] != A[A[i][j]][k])
					return false;
	
	// 2) Get identity i * x = x : O(N^2) -> 10000
	int ident = -1;
	for(int i = 1; i <= N; i++)
	{
		bool f1 = true; // Is this column the identity?
		for(int j = 1; j <= N; j++)
		{
			if(A[i][j] != j)
			{
				f1 = false;
				break;
			}
		}
		
		if(!f1) continue;
		
		// Now we must check if the row is also identity
		// as i * x = x * i = x (is commutative)
		bool f2 = true;
		for(int j = 1; j <= N; j++)
		{
			if(A[j][i] != j)
			{
				f2 = false;
				break;
			}
		}
		
		if(f2)
		{
			ident = i;
			break;
		}
	}
	
	if(ident == -1) return false;
	
	// 3) Check Inverse: O(2N^2) -> 20000
	bool f2 = true;
	// Every row must contain identity
	for(int i = 1; i <= N && f2; i++)
	{
		bool f1 = false;
		for(int j = 1; j <= N; j++)
		{
			if(A[i][j] == ident)
			{
				f1 = true;
				break;
			}
		}
		f2 &= f1;
	}
	// Every column must contain identity
	for(int i = 1; i <= N && f2; i++)
	{
		bool f1 = false;
		for(int j = 1; j <= N; j++)
		{
			if(A[j][i] == ident)
			{
				f1 = true;
				break;
			}
		}
		f2 &= f1;
	}
	
	return f2;
}

int main()
{
	while(true)
	{
		scanf("%d", &N);
		if(!N) break;
		
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				scanf("%d", &A[i][j]);
		printf("%s\n", isValidGroup() ? "yes" : "no");
	}
}
