#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define MOD 1000000007 // Change me!
#define lsb(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define ilog2(n) sizeof(int)*8-__builtin_clz(n)-1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define ff first
#define ss second
#define sc(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define smod(a,b) (((a)%MOD-(b)%MOD+MOD)%MOD)
#define amod(a,b) (((a)%MOD+(b)%MOD)%MOD)
typedef long long ll;
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

int H, W, dp[1003][1003];
char g[1003][1003];

int main()
{
	scanf("%d%d",&H,&W);
	dp[1][1]=1;
	for(int y = 1; y <= H; y++)
	{
		for(int x = 1; x <= W; x++)
		{
			scanf(" %c", &g[x][y]);
			if(g[x][y] != '.') continue;
			if(g[x-1][y]=='.') dp[x][y]=amod(dp[x][y],dp[x-1][y]);
			if(g[x][y-1]=='.') dp[x][y]=amod(dp[x][y],dp[x][y-1]);
		}
	}
	printf("%d", dp[W][H]);
}
