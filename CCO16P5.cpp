#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define ilog2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
#define loop(x, a, b) for(int x = a; x < b; x++)
#define sc(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;
typedef long long ll;

struct area {
	int x1, y1, x2, y2;
};

int N, M, K, Q, cx, cy, psa[2003][2003], vx[2003], vy[2003];
map<int, int> mx, my;
vector<vec> zs;
vector<area> as;

ll getTintedGlass(int q)
{
	// Reset
	memset(psa, 0, sizeof(psa));
	as.clear();
	mx.clear(); my.clear();
	
	// Coordinate compression
	cx = 0, cy = 0;
	for(auto v : zs)
	{
		int x1 = v.x - q, y1 = v.y - q;
		int x2 = v.x + q, y2 = v.y + q;
		x1 = max(1, x1), y1 = max(1, y1);
		x2 = min(N, x2), y2 = min(M, y2);
		printf("z=%d %d to %d %d\n", x1, y1, x2, y2);
		as.push_back({ x1, y1, x2, y2 });
		mx[x1] = 1, mx[x2] = 1, my[y1] = 1, my[y2] = 1;
	}
	for(auto c : mx) { mx[c.first] = ++cx; vx[cx] = c.first; }
	for(auto c : my) { my[c.first] = ++cy; vy[cy] = c.first; }
	
	for(auto v : as)
	{
		int x1 = mx[v.x1], x2 = mx[v.x2], y1 = my[v.y1], y2 = my[v.y2];
		printf("z=%d %d to %d %d\n", x1, y1, x2, y2);
		psa[mx[v.x1]][my[v.y1]] += 1;
		psa[mx[v.x2]+1][my[v.y1]] -= 1;
		psa[mx[v.x1]][my[v.y2]+1] -= 1;
		psa[mx[v.x2]+1][my[v.y2]+1] += 1;
	}
	
	ll ans = 0;
	// Prefix Sum
	for(int i = 1; i <= cx; i++)
	{
		for(int j = 1; j <= cy; j++)
		{
			psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
			if(psa[i][j] >= q) ans += (ll)(vx[i + 1] - vx[i]) * (vy[j + 1] - vy[j]);
		}
	}
	printf("--\n");
	return ans;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0, x, y; i < K; i++)
	{
		scanf("%d %d", &x, &y);
		zs.push_back({x, y});
	}
	scanf("%d", &Q);
	printf("%lld", getTintedGlass(Q) - getTintedGlass(Q - 1));
}
