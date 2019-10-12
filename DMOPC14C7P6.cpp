#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define ff first
#define ss second
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

struct node
{
	int l, r, ps, mn;
};

int N, mp[100005], A[100005];
node seg[300005];

void build(int l, int r, int n)
{
	seg[n].l = l, seg[n].r = r;
	if(l == r)
	{
		seg[n].mn = A[l];
		seg[n].ps = A[l];
		return;
	}
	int m = mid(l, r);
	build(l, m, sl(n));
	build(m+1, r, sr(n));
	seg[n].mn = min(seg[sl(n)].mn, seg[sl(n)].ps+seg[sr(n)].mn);
	seg[n].ps = seg[sl(n)].ps+seg[sr(n)].ps;
}

void update(int p, int n)
{
	if(seg[n].l == p && seg[n].r == p)
	{
		seg[n].mn = A[p];
		seg[n].ps = A[p];
		return;
	}
	int m = mid(seg[n].l, seg[n].r);
	if(p <= m) update(p, sl(n));
	else       update(p, sr(n));
	seg[n].mn = min(seg[sl(n)].mn, seg[sl(n)].ps+seg[sr(n)].mn);
	seg[n].ps = seg[sl(n)].ps+seg[sr(n)].ps;
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) A[i] = 1;
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &mp[i]);
		if(i > mid(0, N))
			A[N-mp[i]+1] = -1;
	}
	build(1, N, 1);
	if(seg[1].mn >= 0)
	{
		printf("%d", mid(0, N));
		return 0;
	}
	for(int i = mid(0, N)-1; i > 0; i--)
	{
		A[N-mp[2*i+1]+1] = 0;
		A[N-mp[2*i+2]+1] = 0;
		A[N-mp[i+1]+1] = -A[N-mp[i+1]+1];
		update(N-mp[2*i+1]+1, 1);
		update(N-mp[2*i+2]+1, 1);
		update(N-mp[i+1]+1, 1);
		if(seg[1].mn >= 0)
		{
			printf("%d", i);
			return 0;
		}
	}
	
	printf("0");
}
