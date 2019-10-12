#include <math.h>
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

struct coord
{
	int x, y, z;
};

struct vec3 {
	double x, y, z;
};

struct hh {
size_t operator()(const vec3 &k) const {
	size_t h1 = hash<double>()(k.x);
	size_t h2 = hash<double>()(k.y);
	size_t h3 = hash<double>()(k.z);
	return (h1 ^ (h2 << 1)) ^ h3;
}};

struct eq {
bool operator()(const vec3 &l, const vec3 &r) const {
	return (l.x == r.x) && (l.y == r.y) && (l.z == r.z);
}};

int N;
coord o;
//unordered_set<vec3, hh, eq> s;
set<pair<ll, pair<ll, ll>>> s;

// I'm starting to hate my life a lot
ll gcd(ll a, ll b)
{
	if(b == 0l) return a;
	return gcd(b, a % b);
}

int main()
{
	scanf("%d %d %d", &o.x, &o.y, &o.z);
	scanf("%d", &N);
	for(ll i = 0, x, y, z; i < N; i++)
	{
		scanf("%lld %lld %lld", &x, &y ,&z);
		ll dx = x - o.x, dy = y - o.y, dz = z - o.z;
		
		/*
		int sx = dx == abs(dx) ? 1 : -1;
		int sy = dy == abs(dy) ? 1 : -1;
		int sz = dz == abs(dz) ? 1 : -1;
		
		double len2 = dx * dx + dy * dy + dz * dz;
		double nx = sx * ((dx * dx) / len2);
		double ny = sy * ((dy * dy) / len2);
		double nz = sz * ((dz * dz) / len2);
		
		s.insert((vec3){ nx, ny, nz });
		*/
		
		ll len = abs(gcd(dx, gcd(dy, dz)));
		s.insert({ dx / len, { dy / len, dz / len }});
	}
	
	printf("%d", s.size());
}