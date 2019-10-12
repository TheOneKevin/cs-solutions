#include <bits/stdc++.h>
using namespace std;
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
typedef pair<int, int> ip;

struct node {
	// left index, right index
	// minimum value, GCD
	int l, r, m, g, c;
};

int N, M, A[100001];

struct node seg[300002];

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

void build(int l, int r, int n)
{
	seg[n].l = l, seg[n].r = r;
	if(l == r) {
		seg[n].m = A[l];
		seg[n].g = A[l];
		seg[n].c = 1;
		return;
	}
	int m = (l + r) / 2;
	build(l,   m, 2*n);
	build(m+1, r, 2*n+1);
	
	// Left node and right node (2*n and 2*n+1)
	seg[n].m = min(seg[2*n].m, seg[2*n+1].m);
	seg[n].g = gcd(seg[2*n].g, seg[2*n+1].g);
	seg[n].c = 0;
	if(seg[2*n].g   == seg[n].g) seg[n].c += seg[2*n].c;
	if(seg[2*n+1].g == seg[n].g) seg[n].c += seg[2*n+1].c;
}

void update(int p, int v, int n)
{
	if(seg[n].l == p && seg[n].r == p)
	{
		seg[n].m = v;
		seg[n].g = v;
		return;
	}
	
	int m = (seg[n].l + seg[n].r) / 2;
	if(p <= m) update(p, v, 2*n);
	else       update(p, v, 2*n+1);
	
	seg[n].m = min(seg[2*n].m, seg[2*n+1].m);
	seg[n].g = gcd(seg[2*n].g, seg[2*n+1].g);
	seg[n].c = 0;
	if(seg[2*n].g   == seg[n].g) seg[n].c += seg[2*n].c;
	if(seg[2*n+1].g == seg[n].g) seg[n].c += seg[2*n+1].c;
}

int gcdquery(int l, int r, int n)
{
	if(seg[n].l == l && seg[n].r == r) return seg[n].g;
	int mid = (seg[n].l + seg[n].r) / 2;
	if(r <= mid)     return gcdquery(l, r, 2 * n);
	else if(l > mid) return gcdquery(l, r, 2 * n + 1);
	return gcd(gcdquery(l, mid, 2 * n), gcdquery(mid + 1, r, 2 * n + 1));
}

int minquery(int l, int r, int n)
{
	if(seg[n].l == l && seg[n].r == r) return seg[n].m;
	int mid = (seg[n].l + seg[n].r) / 2;
	if(r <= mid)     return minquery(l, r, 2 * n);
	else if(l > mid) return minquery(l, r, 2 * n + 1);
	return min(minquery(l, mid, 2 * n), minquery(mid + 1, r, 2 * n + 1));
}

int cntquery(int l, int r, int n, int v)
{
	if(seg[n].l == l && seg[n].r == r) return seg[n].g == v ? seg[n].c : 0;
	int mid = (seg[n].l + seg[n].r) / 2;
	if(r <= mid)     return cntquery(l, r, 2 * n,     v);
	else if(l > mid) return cntquery(l, r, 2 * n + 1, v);
	return cntquery(l, mid, 2 * n, v) + cntquery(mid + 1, r, 2 * n + 1, v);
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	build(1, N, 1);
	for(int i = 0; i < M; i++)
	{
		char c;
		int l, r;
		scanf(" %c %d %d", &c, &l, &r);
		if(c == 'C')
		{
			update(l, r, 1);
			A[l] = r;
		}
		else if(c == 'M')
			printf("%d\n", minquery(l, r, 1));
		else if(c == 'G')
			printf("%d\n", gcdquery(l, r, 1));
		else if(c == 'Q')
			printf("%d\n", cntquery(l, r, 1, gcdquery(l, r, 1)));
	}
}