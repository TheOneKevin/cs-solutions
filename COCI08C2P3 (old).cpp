#include <bits/stdc++.h>
using namespace std;
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
typedef pair<int, int> ip;

struct node
{
	// product, sum
	int p, s;
};

int N;
ip A[11];
struct node seg[201];

int query(int l, int r)
{
	int p = 1, s = 0;
	
	for(l += N, r += N; l < r; l /= 2, r /= 2)
	{
		if(l & 1)
		{
			int i = l++;
			s += seg[i].s;
			p *= seg[i].p == 0 ? 1 : seg[i].p;
		}
		
		if(r & 1)
		{
			int i = --r;
			s += seg[i].s;
			p *= seg[i].p == 0 ? 1 : seg[i].p;
		}
	}
	
	return abs(p - s);
}

int main()
{
	scanf("%d", &N);
	for(int i = 0, P, S; i < N; i++)
	{
		scanf("%d %d", &P, &S);
		A[i] = { P, S };
	}
	sort(A, A + N);
	for(int i = 0, P, S; i < N; i++)
		seg[N + i].p = A[i].first, seg[N + i].s = A[i].second;
	
	for(int i = N - 1; i > 0; --i)
		seg[i].p = seg[i*2].p * seg[i*2+1].p, seg[i].s = seg[i*2].s + seg[i*2+1].s;
	int res = 0x3F3F3F3F;
	int cnt = 0;
	for(int i = 1; i <= N; i++)
		for(int j = i; j <= N; j++)
			res = min(res, query(i - 1, j)), cnt++;
			//cout << query(i - 1, j) << endl;
	if(cnt != (N * (N+1))/2) return -1;
	printf("%d", res);
	
	//printf("%d", query(1, 3));
}
