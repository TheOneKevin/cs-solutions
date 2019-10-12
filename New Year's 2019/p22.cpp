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

int N, M;
int a[2][1000006];
int R[1000006];

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d %d", &a[0][i], &a[1][i]);
	R[1] = M;
	for(int i = 1; i <= N; i++)
	{
		R[a[0][i]] += R[i]-R[i]/2;
		R[a[1][i]] += R[i]/2;
	}
	
	for(int i = 1; i <= N; i++)
		printf("%d", R[i]%2);
}
