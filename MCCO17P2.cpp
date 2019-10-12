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
	int l, r, m;
}

int A[i];
node seg[200005];

void build(int l, int r, int i)
{
	seg[i].l = l, seg[i].r = r;
	if(l == r)
	{
		seg[i].m = A[i];
		return;
	}
}

void update(int l, int r, int i)
{
	
}

int query(int s, int v, int i)
{
	
}

int main()
{

}
