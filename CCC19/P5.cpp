#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define MOD 1000000007
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
typedef long long ll;
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int N, K, a[3003][3003], sum;
int p1[3003], p2[3003];

int f(int s, int i, int j)
{
	if(s == 1) return a[i][j];
	int ans = 0;
	for(int x = i; x < s+i; x++)
		for(int y = j; y < s+j; y++)
			ans = max(ans, a[x][y]);
	return ans;
}

int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= i; j++)
			scanf("%d", &a[i][j]);
	for(int i = 1; i <= N-K+1; i++)
		for(int j = 1; j <= i; j++)
			sum += f(K, i, j);
	printf("%d", sum);
}
