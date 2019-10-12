#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
typedef pair<int, int> ip;

int N, M, p[100005], cnt = 1;

int find(int x)
{
	if(p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

void u(int x, int y)
{
	int xset = find(x);
    int yset = find(y);
    if(xset != yset)
        p[xset] = yset;
	p[x] = y;
}

int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) p[i] = i;
	for(int i = 0, K; i < M; i++)
	{
		scanf("%d", &K);
		int a; scanf("%d", &a);
		for(int j = 1, b; j < K; j++)
		{
			scanf("%d", &b);
			u(a, b);
		}
	}
	
	for(int i = 2; i <= N; i++)
		if(find(i) == find(1))
			cnt++;
	printf("%d\n", cnt);
	printf("1 ");
	for(int i = 2; i <= N; i++)
		if(find(i) == find(1))
			printf("%d ", i);
}
