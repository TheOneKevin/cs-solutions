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
typedef long long ll;
typedef struct{int x,y;}vec;
typedef pair<int, int> ip;

struct tri
{
	int x1,y1,x2,y2,x3,y3;
};

int N, M;
vector<vec> p;
vector<tri> t;

// Optimized dot product to remove denominator
ll dot(vec p1, vec p2, vec p3)
{
	return (ll)(p1.x-p3.x)*(p2.y-p3.y)-(ll)(p1.y-p3.y)*(p2.x-p3.x);
}

bool isInTriangle(vec p, vec p1, vec p2, vec p3)
{
	double d1, d2, d3; // Dot 1, 2, 3
	d1 = dot(p, p1, p2);
	d2 = dot(p, p2, p3);
	d3 = dot(p, p3, p1);
	bool c1, c2;
	c1 = (d1 < 0) || (d2 < 0) || (d3 < 0);
	c2 = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return !(c1 && c2);
}

bool isOnEdge(vec p, vec v1, vec v2)
{
   if (p.x == v2.x) return v1.x == v2.x;
   if (p.y == v2.y) return v1.y == v2.y;
   return (p.x - v2.x)*(p.y - v2.y) == (v2.x - v1.x)*(v2.y - v1.y);
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0, x, y; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		p.push_back({ x, y });
	}
	
	// Good thing it's not a hexagon
	for(int i = 0, x1,y1,x2,y2,x3,y3; i < M; i++)
	{
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		vec v1 = { x1,y1 };
		vec v2 = { x2,y2 };
		vec v3 = { x3,y3 };
		int ans = 0;
		//t.push_back({ x1,y1,x2,y2,x3,y3 });
		for(vec v : p)
			if(isInTriangle(v, v1, v2, v3))
				ans++;
		printf("%d\n", ans);
	}
}
