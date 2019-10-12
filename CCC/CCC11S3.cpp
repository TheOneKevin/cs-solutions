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

//CCC '11 S3 - Alice Through the Looking Glass
int T;
// Notice that from:
// m1 -> m2
// c  -> 5^(m2-m1)(c-1)+1
// Even when m2 < m1 (convert from 2x to 1x)
//
// sx, sy = seed
// x, y = target
// m1 = mag from
// m2 = mag to
#define mag(x) (5*((x) - 1) + 1)
#define magto(x, m1, m2) ((int)(pow(5, (m2)-(m1))*((x) - 1) + 1))
bool cf(int sx, int sy, int m1, int x, int y, int m2)
{
	int ox = mag(sx), oy = mag(sy);
	int tx = magto(x, m2, m1), ty = magto(y, m2, m1);
	//printf("%d %d %d %d\n", ox, oy, tx, ty);
	// The crystal is structured as:
	// (2, 1) (3, 1) (3, 2) (4, 1)
	bool isInBody = (tx == ox+1 && ty == oy+0) ||
					(tx == ox+2 && ty == oy+0) ||
					(tx == ox+3 && ty == oy+0) ||
					(tx == ox+2 && ty == oy+1);
	
	if(isInBody) return true;
	
	// Generate little spikes
	// The spikes are located at:
	// (2, 2) (3, 3) (4, 2)
	if(m1 < m2)
	{
		bool s1 = false;
		s1 = cf(ox+1, oy+1, m1+1, x, y, m2); if(s1) return true;
		s1 = cf(ox+3, oy+1, m1+1, x, y, m2); if(s1) return true;
		s1 = cf(ox+2, oy+2, m1+1, x, y, m2); if(s1) return true;
	}
	
	return false;
}

int main()
{
	scanf("%d", &T);
	for(int i = 0, m, x, y; i < T; i++)
	{
		scanf("%d %d %d", &m, &x, &y);
		x++, y++;
		bool res = cf(1, 1, 1, x, y, m);
		printf(res ? "crystal\n" : "empty\n");
	}
}
