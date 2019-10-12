// DOES NOT WORK
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (2*(x)+1)
#define madd(x, y, z) (((x) % (z) + (y) % (z)) % (z))
typedef pair<int, int> ip;
typedef long long ll;

struct node {
	int l, r, s;
};

int M, N, Q, A[100005];
node seg[100005];

void build(int l, int r, int i)
{
	seg[i].l = l, seg[i].r = r;
	if(l == r) // Leaf node
	{
		seg[i].s = A[l] % M;
		return;
	}
	
	int m = mid(l, r);
	build(l, m, sl(i));
	build(m + 1, r, sr(i));
	
	seg[i].s = seg[sl(i)].s + seg[sr(i)].s;
}

void update(int p, int v, int i)
{
	if(seg[i].l == p && seg[i].r == p)
	{
		seg[i].s = v % M;
		return;
	}
	
	int m = mid(seg[i].l, seg[i].r);
	if(p <= m) update(p, v, sl(i)); // Are we left or right?
	else update(p, v, sr(i));
	seg[i].s = seg[sl(i)].s + seg[sr(i)].s;
}

int query(int s, int e, int l, int r, int i)
{
	if(s > e || s > r || e < l) return 0;
	if(lazy[i] != 0)
	{
		seg[i].s += (e - s + 1) * lazy[i];
		if(s != e) lazy[sl(i)] += lazy[i], lazy[sr(i)] += lazy[i];
		lazy[i] = 0;
	}
	
	if(s >= l && e <= r) return seg[i].s;
}

int main()
{
	scanf("%d %d %d", &M, &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	build(1, N, 1);
	cout << query(1, N, 1) << endl;
	update(1, 0, 1);
	cout << query(1, N, 1) << endl;
}
