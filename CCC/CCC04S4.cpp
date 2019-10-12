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
typedef struct{int x,y,z;}vec;
typedef struct{double x,y,z;}vecf;
typedef pair<int, int> ip;

double ans = 10e9;
vec s, t, n;

vecf operator+(const vec  &a, const vecf &b) { return (vecf){a.x+b.x,a.y+b.y,a.z+b.z}; }
vec  operator+(const vec  &a, const vec  &b) { return (vec) {a.x+b.x,a.y+b.y,a.z+b.z}; }
vecf operator-(const vecf &a, const vecf &b) { return (vecf){a.x-b.x,a.y-b.y,a.z-b.z}; }
vec  operator-(const vec  &a, const vec  &b) { return (vec) {a.x-b.x,a.y-b.y,a.z-b.z}; }
vec  operator*(const vec &a, const int b)    { return (vec) {a.x*b,  a.y*b,  a.z*b  }; }
vecf operator*(const vec &a, const double b) { return (vecf){a.x*b,  a.y*b,  a.z*b  }; }

double minDist(vec u, vec v)
{
	//Why is Bruce's ppt code so complicated?!
	//d=|(t-u)x(t-v)|/|u-v|
	vec uv = v-u, ut = t-u;
	double f=uv.x*ut.x+uv.y*ut.y+uv.z*ut.z;
	double d=uv.x*uv.x+uv.y*uv.y+uv.z*uv.z;
	if(f<0)
		return sqrt(pow(t.x-u.x,2)+pow(t.y-u.y,2)+pow(t.z-u.z,2));
	else if(f>=d)
		return sqrt(pow(t.x-v.x,2)+pow(t.y-v.y,2)+pow(t.z-v.z,2));
	else
	{
		f /= d;
		vecf p = uv*f;
		p = u + p;
		return sqrt(pow(t.x-p.x,2)+pow(t.y-p.y,2)+pow(t.z-p.z,2));
	}
}

int main()
{
	n = {1,0,0};
	scanf("%d %d %d", &s.x, &s.y, &s.z);
	scanf("%d %d %d", &t.x, &t.y, &t.z);
	while(true)
	{
		int d;
		char c;
		scanf("%d %c", &d, &c);
		ans = min(ans, minDist(s,s+(n*d)));
		s=s+(n*d);
		if(c == 'L') n = {n.y,-n.x,n.z};
		else if(c == 'R') n = {-n.y,n.x,n.z};
		else if(c == 'U') n = {n.z,n.y,-n.x};
		else if(c == 'D') n = {-n.z,n.y,n.x};
		else if(c == 'E') break;
	}
	
	printf("%.2f", ans);
}
