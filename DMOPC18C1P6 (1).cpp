#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1

typedef pair<int, int> ip;

int A[50001], N, Q;
int sx[16][50001], sn[16][50001];

int main()
{
	scanf("%d %d", &N, &Q);
	for(int i = 1; i <= N; i++) { scanf("%d", &sx[0][i]); sn[0][i] = sx[0][i]; }
	
	for(int l = 1; l <= _log2(N); l++)
		for(int i = 1; i + pow2(l) - 1 <= N; i++)
			sn[l][i] = min(sn[l - 1][i], sn[l - 1][i + pow2(l - 1)]),
			sx[l][i] = max(sx[l - 1][i], sx[l - 1][i + pow2(l - 1)]);
	
	for(int i = 0, l, r; i < Q; i++)
	{
		scanf("%d %d", &l, &r);
		
		int k  = _log2(r - l + 1);
		int mx = max(sx[k][l], sx[k][r - pow2(k) + 1]);
		int mn = min(sn[k][l], sn[k][r - pow2(k) + 1]);
		
		//cout << q.second << " " << q.first << endl;
		printf("%d\n", mx - mn);
	}
}
