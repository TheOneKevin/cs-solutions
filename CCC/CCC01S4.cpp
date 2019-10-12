#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb(n)  ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(int)*8-__builtin_clz(n)-1
#define mid(n,m)(((m)+(n))/2.0) //
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
typedef struct{int x,y;}vec;
typedef struct{double x,y;}vecf;
typedef pair<int, int> ip;

int N;
vector<vec> v;

bool check(vecf u, double r)
{
	for(auto p : v)
	{
		// Some stupid fucking c++ precision error
		//printf("%f == %f is %d\n", pow(u.x-p.x,2)+pow(u.y-p.y,2),r,pow(u.x-p.x,2)+pow(u.y-p.y,2)==r);
		if(abs(pow(u.x-p.x,2)+pow(u.y-p.y,2)-r)<=0.000001)
			continue;
		if(pow(u.x-p.x,2)+pow(u.y-p.y,2) > r)
			return false;
	}
	return true;
}

int main()
{
	scanf("%d", &N);
	
	for(int i = 0, x, y; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		v.push_back({x,y});
	}
	
	double d = 10e6;
	
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = i+1; j < v.size(); j++)
		{
			vecf u = {mid(v[i].x,v[j].x),mid(v[i].y,v[j].y)};
			double r = pow(u.x-v[i].x,2)+pow(u.y-v[i].y,2);
			if(check(u, r)) d = min(d, r);
		}
	}
	
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = i+1; j < v.size(); j++)
		{
			for(int k = j+1; k < v.size(); k++)
			{
				vecf u = {
					(double)(v[i].x*v[i].x+v[i].y*v[i].y)*(v[j].y-v[k].y)+
					(double)(v[j].x*v[j].x+v[j].y*v[j].y)*(v[k].y-v[i].y)+
					(double)(v[k].x*v[k].x+v[k].y*v[k].y)*(v[i].y-v[j].y),
					(double)(v[i].x*v[i].x+v[i].y*v[i].y)*(v[k].x-v[j].x)+
					(double)(v[j].x*v[j].x+v[j].y*v[j].y)*(v[i].x-v[k].x)+
					(double)(v[k].x*v[k].x+v[k].y*v[k].y)*(v[j].x-v[i].x)
				};
				u.x /= 2.0*(v[i].x*(v[j].y-v[k].y)+v[j].x*(v[k].y-v[i].y)+v[k].x*(v[i].y-v[j].y));
				u.y /= 2.0*(v[i].x*(v[j].y-v[k].y)+v[j].x*(v[k].y-v[i].y)+v[k].x*(v[i].y-v[j].y));
				double r = pow(u.x-v[i].x,2)+pow(u.y-v[i].y,2);
				if(check(u, r)) d = min(d, r);
			}
		}
	}
	
	printf("%.2lf", sqrt(d)*2);
}
