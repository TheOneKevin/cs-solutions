#include <bits/stdc++.h>
using namespace std;
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
typedef pair<int, int> ip;

int W, D, V, A[11], B[6];
bool res[11], mem[6][5000001];

// Hopefully we can complete this in 756000 (??) tries

void solve(int op, int num)
{
	// We must use exactly W operations
	if(op == W)
	{
		for(int i = 0; i < V; i++)
			if(B[i] == num) res[i] = true;
		return;
	}
	
	// Optimization
	if(mem[op][num]) return;
	mem[op][num] = true;
	
	for(int i = 0; i < D; i++)
	{
		solve(op + 1, A[i] + num); // Try adding
		solve(op + 1, A[i] * num);
	}
}

int main()
{
	scanf("%d %d", &W, &D);
	for(int i = 0; i < D; i++) scanf("%d", &A[i]);
	scanf("%d", &V);
	for(int i = 0; i < V; i++) scanf("%d", &B[i]);
	for(int i = 0; i < D; i++) solve(0, A[i]);
	for(int i = 0; i < V; i++) printf(res[i] ? "Y\n" : "N\n");
}
