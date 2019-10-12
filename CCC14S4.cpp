#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define ilog2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
typedef pair<int, int> ip;
typedef long long ll;

struct query {
	int x1, y1, x2, y2, t;
};

int N, T, cx, cy, psa[2001][2001], vx[2001], vy[2001];
map<int, int> mx, my;
vector<query> qs;

int main()
{
	scanf("%d %d", &N, &T);
	for(int i = 0, x1, y1, x2, y2, a; i < N; i++)
	{
		scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &a);
		qs.push_back({ x1, y1, x2, y2, a });
		mx.emplace(x1, 1); my.emplace(y1, 1);
		mx.emplace(x2, 1); my.emplace(y2, 1);
	}
	
	// Coordinate compression
	for(auto c : mx) { mx[c.first] = ++cx; vx[cx] = c.first; }
	for(auto c : my) { my[c.first] = ++cy; vy[cy] = c.first; }
	
	// Difference array
	for(auto q : qs)
	{
		int x1 = mx[q.x1], x2 = mx[q.x2], y1 = my[q.y1], y2 = my[q.y2];
		psa[x1][y1] += q.t;
		psa[x2][y1] -= q.t;
		psa[x1][y2] -= q.t;
		psa[x2][y2] += q.t;
	}
	
	//cout << cx << " " << cy << endl;
	ll ans = 0;
	// Prefix Sum
	for(int i = 1; i <= cx; i++)
	{
		for(int j = 1; j <= cy; j++)
		{
			psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
			if(psa[i][j] >= T) ans += (ll)(vx[i + 1] - vx[i]) * (vy[j + 1] - vy[j]);
		}
	}
	
	printf("%lld", ans);
}
