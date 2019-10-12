#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb(n)  ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(int)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2)
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define sc(x) {do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
#define ff first
#define ss second
#define smod(a,b) (((a)%MOD-(b)%MOD+MOD)%MOD)
#define amod(a,b) (((a)%MOD+(b)%MOD)%MOD)
#define btst(a,b) ((a) & (1 << (b)))
#define cintie(x) { cin.sync_with_stdio(x); cin.tie(x); }
// Typedefs
typedef long long ll;
typedef struct{int e,a;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

struct node
{
	vec i, j;
	int c;
};

int N, M, P, Q;
vector<node> edj;

int main()
{
	scanf("%d %d %d %d", &N, &M, &P, &Q);
	for(int i = 1, a, b, c; i <= P; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		for(int j = 1; j <= N; j++)
			edj.push_back({{j,a},{j,b},c});
	}
	for(int i = 1, a, b, c; i <= Q; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		for(int j = 1; j <= M; j++)
			edj.push_back({{a,j},{b,j},c});
	}
	
	// MST
	
	
}
