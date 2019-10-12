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

// CCC '03 S3 - Floor Plan

int A, Y, X;
char c[27][27];
priority_queue<int> pq;

inline bool isInBounds(int x, int y)
{
	return x > 0 && x <= X && y > 0 && y <= Y;
}

bool bfs()
{
	// Find start
	queue<vec> q;
	for(int x = 1; x <= X; x++)
	{
		bool flag = false;
		for(int y = 1; y <= Y; y++)
			if(c[x][y] == '.'){ flag = true; q.push({x,y}); break; }
		if(flag) break;
	}
	if(q.empty()) return false;
	int cnt = 0;
	// Do BFS
	while(!q.empty())
	{
		vec v = q.front(); q.pop();
		if(c[v.x][v.y] != '.') continue;
		c[v.x][v.y] = 'x';
		cnt++;
		if(isInBounds(v.x+1,v.y) && c[v.x+1][v.y] == '.') q.push({v.x+1,v.y});
		if(isInBounds(v.x-1,v.y) && c[v.x-1][v.y] == '.') q.push({v.x-1,v.y});
		if(isInBounds(v.x,v.y+1) && c[v.x][v.y+1] == '.') q.push({v.x,v.y+1});
		if(isInBounds(v.x,v.y-1) && c[v.x][v.y-1] == '.') q.push({v.x,v.y-1});
	}
	/*for(int x = 1; x <= X; x++)
	{
		for(int y = 1; y <= Y; y++)
			printf("%c", c[x][y]);
		printf("\n");
	}*/
	//printf("- %d\n", cnt);
	pq.push(cnt);
	return true;
}

int main()
{
	memset(c, 'I', sizeof(c));
	scanf("%d %d %d", &A, &X, &Y);
	for(int x = 1; x <= X; x++)
		for(int y = 1; y <= Y; y++)
			scanf(" %c", &c[x][y]);
	while(bfs());
	int rms = 0;
	while(!pq.empty())
	{
		A -= pq.top();
		if(A < 0) { A += pq.top(); break; }
		pq.pop();
		rms++;
	}
	printf("%d %s, %d square metre(s) left over\n", rms, rms == 1 ? "room" : "rooms", A);
}
