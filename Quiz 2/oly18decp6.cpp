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

int N, h[1001], s[1001];
double x = INF;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d %d", &h[i], &s[i]);
	for(int i = 0; i < N; i++)
	{
		for(int j = i; j < N; j++)
		{
			if(s[i] == s[j])
			{
				if(h[i] == h[j] && i != j)
				{
					printf("0");
					return 0;
				}
				continue;
			}
			double xx = (double)(h[j] - h[i]) / (double)(s[i] - s[j]);
			if(xx == floor(xx) && xx >= 0)
				x = min(floor(xx), x);
		}
	}
	
	printf("%.0f", x == INF ? -1 : x);
}
