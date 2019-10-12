#include <bits/stdc++.h>
using namespace std;
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
typedef pair<int, int> ip;

int res = 0x3F3F3F3F, N;
ip A[11];

// Screw segment trees, ima brute force, I give up :((
void solve(int i, int p, int s)
{
	if(i == N) { if(s != 0) res = min(res, abs(p - s)); return; }
	solve(i + 1, p, s);
	solve(i + 1, p * A[i].first, s + A[i].second);
}


int main()
{
	scanf("%d", &N);
	for(int i = 0, P, S; i < N; i++)
	{
		scanf("%d %d", &P, &S);
		A[i] = { P, S };
	}
	
	solve(0, 1, 0);
	
	printf("%d", res);
}
