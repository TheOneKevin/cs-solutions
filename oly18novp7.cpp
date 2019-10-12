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

int X, Y, cnt = 0;
bool vis[100001];

#define isInBounds(x,y)((x)y >= 0 && (x)y <= 100000)

int main()
{
	scanf("%d %d", &X, &Y);
	
	queue<ip> q;
	q.push({ X, 0 });
	
	while(!q.empty())
	{
		int v = q.front().first;
		int u = q.front().second + 1;
		if(v == Y)
		{
			printf("%d\n", u - 1);
			break;
		}
		
		q.pop();
		if(isInBounds(v,+1) && !vis[v + 1]) q.push({ v + 1, u }), vis[v + 1] = true;
        if(isInBounds(v,-1) && !vis[v - 1]) q.push({ v - 1, u }), vis[v - 1] = true;
        if(isInBounds(v,*2) && !vis[v * 2]) q.push({ v * 2, u }), vis[v * 2] = true;
	}
}
