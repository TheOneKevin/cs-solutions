#include <bits/stdc++.h>
using namespace std;
// Change me!
#define INF 0x3F3F3F3F
#define MOD 1000000007
// All other macros.
#define lsb (n) ((n)&-(n))
#define pow2(n) (1<<(n))
#define ilg2(n) sizeof(int)*8-__builtin_clz(n)-1
#define mid (n, m) (((m)+(n))/2)
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
typedef pair<int, int> ip;

int N, ans, dup;
vec r, j;

bool check(vec p, vec v)
{
	if(!(max(r.x,j.x)>=min(p.x,v.x)&&max(p.x,v.x)>=min(r.x,j.x)
		&&max(r.y,j.y)>=min(p.y,v.y)&&max(p.y,v.y)>=min(r.y,j.y)))
		return false;
	
	// Vector cross product
	// (p-r)x(j-r)=<px-rx,py-ry,0>x<jx-rx,jy-ry,0>=<0,0,(px-rx)(jy-ry)-(py-ry)(jx-rx)>
	// (v-r)x(j-r)=<vx-rx,vx-rx,0>x<jx-rx,jx-ry,0>=<0,0,(vx-rx)(jy-ry)-(vy-ry)(jx-rx)>
	
	int c1 = (p.x-r.x)*(j.y-r.y)-(p.y-r.y)*(j.x-r.x);
	int c2 = (v.x-r.x)*(j.y-r.y)-(v.y-r.y)*(j.x-r.x);
	
	if(c1<0&&c2<0) return false;
	if(c1<0&&c2>0) return true;
	if(c1==0||c2==0) return true;
	return false;
}

int main()
{
	scanf("%d %d %d %d", &r.x, &r.y, &j.x, &j.y);
	scanf("%d", &N);
	for(int _i = 0, n; _i < N; _i++)
	{
		bool flag = false;
		scanf("%d", &n);
		if(n==0)continue;
		vec p, v, l;
		scanf("%d %d", &p.x, &p.y);
		l.x=p.x,l.y=p.y;
		for(int _j = 1; _j < n; _j++)
		{
			scanf("%d %d", &v.x, &v.y);
			//if((p.x-v.x)*(cr.y-cj.y)-(p.y-v.y)*(cr.x-cj.x)!=0)
			flag |= check(v, p) || check(p, v);
			p.x = v.x, p.y = v.y;
		}
		flag |= check(l, p) || check(p, l);
		if(flag) ans++;
	}
	
	printf("%d", ans);
}
