#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
typedef pair<int, int> ip;
typedef long long ll;

struct node {
	int l, r;
	ll m, z; 
};

int N, Q;
node seg[66004];

void prop(int i)
{
	seg[sl(i)].z += seg[i].z;
	seg[sr(i)].z += seg[i].z;
	seg[sl(i)].m -= seg[i].z;
	seg[sr(i)].m -= seg[i].z;
	seg[i].z = 0;
}

void build(int l, int r, int i)
{
	seg[i].l = l, seg[i].r = r;
	if(l == r)
	{
		scanf("%lld", &seg[i].m);
		return;
	}
	int m = mid(l, r);
	build(l, m, sl(i));
	build(m + 1, r, sr(i));
	seg[i].m = min(seg[sl(i)].m, seg[sr(i)].m);
}

void update(int l, int r, int i, int v)
{
	if(seg[i].l == l && seg[i].r == r)
	{
		seg[i].m -= v;
		seg[i].z += v;
		return;
	}
	if(seg[i].z) prop(i);
	int m = mid(seg[i].l, seg[i].r);
	if     (r <= m) update(l, r, sl(i), v);
	else if(l >  m) update(l, r, sr(i), v);
	else
	{
		update(l, m, sl(i), v);
		update(m + 1, r, sr(i), v);
	}
	
	seg[i].m = min(seg[sl(i)].m, seg[sr(i)].m);
}

ll query(int l, int r, int i)
{
	if(seg[i].l == l && seg[i].r == r) return seg[i].m;
	if(seg[i].z) prop(i);
	int m = mid(seg[i].l, seg[i].r);
	if     (r <= m) return query(l, r, sl(i));
	else if(l >  m) return query(l, r, sr(i));
	else return min(query(l, m, sl(i)), query(m + 1, r, sr(i)));
}

int main()
{
	scanf("%d %d", &N, &Q);
	build(1, N, 1);
	for(int i = 1, a, b, c; i <= Q; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		update(a, b, 1, c);
		printf("%lld %lld\n", max(0LL, query(a, b, 1)), max(0LL, seg[1].m));
	}
}
