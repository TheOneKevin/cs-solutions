#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb(n)  ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(n)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define ff first
#define ss second
#define smod(a,b) (((a)%MOD-(b)%MOD+MOD)%MOD)
#define amod(a,b) (((a)%MOD+(b)%MOD)%MOD)
#define btst(a,b) ((a) & (1 << (b)))
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int main()
{

for(int _ = 0; _ < 10; _++)
{
	map<int, int> arr;
	int N, mn = INF;
	scanf("%d", &N);
	for(int i = 1, a, r, v = INF; i <= N; i++)
	{
		v = INF;
		scanf("%d", &a);
		scanf("%d", &r);
		for(int j = 0, b; j < r; j++)
		{
			scanf("%d", &b);
			v = min(v, b);
		}
		arr[a] = v;
		mn = min(mn, v);
	}
	
	printf("%d {", mn);
	bool bbb = false;
	for(int i = 1; i <= N; i++)
	{
		if(arr[i] == mn)
		{
			if(bbb) printf(",");
			bbb = true, printf("%d", i);
		}
	}
	printf("}\n");
}}
