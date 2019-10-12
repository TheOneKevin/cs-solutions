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

// CCC '12 S3 - Absolutely Acidic
int N, freq[1003], rev[3003], mx, mn = INF;
vector<vec> v;

// Condition such that a goes before b

int main()
{
	scanf("%d", &N);
	for(int i = 0, a; i < N; i++)
	{
		scanf("%d", &a);
		freq[a]++;
		mx = max(mx, a);
		mn = min(mn, a);
	}
	
	for(int i = mn; i <= mx; i++)
	{
		rev[freq[i]]++;
		v.push_back({ i, freq[i] });
	}
	
	sort(v.begin(), v.end(), [](vec a, vec b) { return a.y == b.y ? a.x < b.x : a.y > b.y; });
	
	int idx = rev[v[0].y] - 1;
	if(idx == 0)
	{
		int ans = 0;
		for(int i = 1; i <= rev[v[1].y]; i++)
			ans = max(ans, abs(v[0].x - v[i].x));
		printf("%d\n", ans);
	}
	else printf("%d\n", v[idx].x - v[0].x);
	//for(auto e : v) printf("%d %ds\n", e.y, e.x);
}
