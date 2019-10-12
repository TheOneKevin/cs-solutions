/*

1) Find all fixed points, and mark them (psa[fixed point index]++)
2) Run a psa on all marked fixed points
	- This will allow us to quickly find the number of fixed points in a given range
3) 

*/

#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define ff first
#define ss second
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int N, mx, mxl, mxr, a[500005], psa[500005];
vector<int> v[1000002];

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
		int md = abs(i-a[i])+2*min(i,a[i]);
		v[md].push_back(i);
		if(a[i] == i) psa[i]++;
		//printf("%d (%d) has center %d\n", a[i], i, md);
	}
	for(int i = 1; i <= N; i++) psa[i] += psa[i-1];
	for(int i = 1; i < 1000002; i++)
	{
		if(v[i].size() != 0)
		{
			float r = 0;
			for(int e : v[i]) if(abs(i/2.0-e) > r) r = abs(i/2.0-e);
			int lt = max(0,(int)floor(i/2.0-r)), rt = min(N,(int)ceil(i/2.0+r));
			int vl = psa[lt-1]-psa[0]+psa[N]-psa[rt]+v[i].size();
			if(vl > mx) mx = vl, mxl = lt, mxr = rt;
			//printf("%.1f, r=%.1f, [%d, %d], %d", i/2.0, r, lt, rt, vl);
			//for(int e : v[i]) printf("%d ", e);
			//printf("\n");
		}
	}
	printf("%d %d\n", a[mxl], a[mxr]);
}
