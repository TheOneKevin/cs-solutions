#include <bits/stdc++.h>
using namespace std;
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
typedef pair<int, int> ip;

int N, Q, A[500001];
ip seg[500001];

void buildshites(int a, int b, int c)
{
	if(a == b)
	{
		seg[c].first = A[a];
		seg[c].second = A[a];
		return;
	}
	
	int m = mid(a, b);
	buildshites(a,     m, c * 2 + 1);
	buildshites(m + 1, b, c * 2 + 2);
	
	seg[c].first  = min(seg[c * 2 + 1].first,  seg[c * 2 + 2].first);
	seg[c].second = max(seg[c * 2 + 1].second, seg[c * 2 + 2].second);
}

ip query(int sl, int sr, int ql, int qr, int i)
{
	ip tmp, tl, tr;
	if(ql <= sl && qr >= sr) return seg[i];
	if(sr < ql || sl > qr)
	{
		tmp = {INT_MAX, INT_MIN};
		return tmp;
	}
	
	int m = mid(sl, sr);
	tl = query(sl,     m, ql, qr, 2 * i + 1);
	tr = query(m + 1, sr, ql, qr, 2 * i + 2);
	tmp.first  = min(tl.first,  tr.first);
	tmp.second = max(tl.second, tr.second);
	return tmp;
}

// KILL ME NOW
int main()
{
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; i++) scanf("%d", &A[i]);
	buildshites(0, N - 1, 0);
	for(int i = 0, l, r; i < Q; i++)
	{
		scanf("%d %d", &l, &r);
		l--, r--;
		ip q = query(0, N - 1, l, r, 0);
		//cout << q.second << " " << q.first << endl;
		printf("%d\n", q.second - q.first);
	}
}
