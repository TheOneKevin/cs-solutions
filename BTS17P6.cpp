#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
typedef pair<int, int> ip;

int N, A[100001];
unordered_map<int, int> m;

int main()
{
	scanf("%d", &N);
	for(int i = 1, a; i <= N; i++) { scanf("%d", &a); m[a] = i; }
	for(int i = 0, a; i < N; i++) { scanf("%d", &a); A[i] = m[a]; }
	// LIA
	int l = 0, mx = 0, ml = 0;
	for(int r = 1; r < N; r++)
	{
		if(A[i] > A[i - 1]) l++;
		else
		{
			if(ml < l)
			{
				ml = l;
				mx = r - l;
			}
			
			l = 1;
		}
		if(ml < l)
		{
			ml = l;
			mx = r - l;
		}
	}
	
	
}
